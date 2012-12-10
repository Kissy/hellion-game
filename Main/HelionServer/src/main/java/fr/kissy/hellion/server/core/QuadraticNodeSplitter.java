package fr.kissy.hellion.server.core;

import java.util.ArrayList;

/**
* Created with IntelliJ IDEA.
* User: Guillaume
* Date: 10/12/12
* Time: 01:39
* To change this template use File | Settings | File Templates.
*/
public class QuadraticNodeSplitter<T extends BoundedObject> implements NodeSplitter<T> {
    private RTree<T> rTree;

    public QuadraticNodeSplitter(RTree<T> rTree) {
        this.rTree = rTree;
    }

    public void split(Node<T> n) {
        if (n.size() <= rTree.getMaxSize()) return;
        boolean isleaf = n.isLeaf();

        // Choose seeds. Would write a function for this, but it requires returning 2 objects
        BoundedObject seed1 = null, seed2 = null;
        ArrayList<? extends BoundedObject> list;
        if (isleaf)
            list = n.getData();
        else
            list = n.getChildren();

        int maxD = Integer.MIN_VALUE;
        AABB box = new AABB();
        for (int i = 0; i < list.size(); i++)
            for (int j = 0; j < list.size(); j++) {
                if (i == j) continue;
                BoundedObject n1 = list.get(i), n2 = list.get(j);
                n1.getBounds().copyInto(box);
                box.merge(n2.getBounds());
                int d = box.getVolume() - n1.getBounds().getVolume() - n2.getBounds().getVolume();
                if (d > maxD) {
                    maxD = d;
                    seed1 = n1;
                    seed2 = n2;
                }
            }
        assert (seed1 != null);

        // Distribute
        Node<T> group1 = new Node<T>(rTree, isleaf);
        group1.setBox(seed1.getBounds().getCopy());
        Node<T> group2 = new Node<T>(rTree, isleaf);
        group2.setBox(seed2.getBounds().getCopy());
        if (isleaf)
            distributeLeaves(n, group1, group2);
        else
            distributeBranches(n, group1, group2);

        Node<T> parent = n.getParent();
        if (parent == null) {
            parent = new Node<T>(rTree, false);
            rTree.setRoot(parent);
        } else
            parent.getChildren().remove(n);

        group1.setParent(parent);
        parent.getChildren().add(group1);
        group1.computeMBR();
        split(parent);

        group2.setParent(parent);
        parent.getChildren().add(group2);
        group2.computeMBR();
        split(parent);
    }

    private void distributeBranches(Node<T> n, Node<T> g1, Node<T> g2) {
        assert (!(n.isLeaf() || g1.isLeaf() || g2.isLeaf()));

        while (!n.getChildren().isEmpty() && g1.getChildren().size() < rTree.getMaxSize() - rTree.getMinSize() + 1 &&
                g2.getChildren().size() < rTree.getMaxSize() - rTree.getMinSize() + 1) {
            // Pick next
            int difmax = Integer.MIN_VALUE;
            int nmax_index = -1;
            for (int i = 0; i < n.getChildren().size(); i++) {
                Node<T> node = n.getChildren().get(i);
                int dif = Math.abs(node.getBox().expansionNeeded(g1.getBox()) - node.getBox().expansionNeeded(g2.getBox()));
                if (dif > difmax) {
                    difmax = dif;
                    nmax_index = i;
                }
            }
            assert (nmax_index != -1);

            // Distribute Entry
            Node<T> nmax = n.getChildren().remove(nmax_index);
            Node<T> parent;

            // ... to the one with the least expansion
            int overlap1 = nmax.getBox().expansionNeeded(g1.getBox());
            int overlap2 = nmax.getBox().expansionNeeded(g2.getBox());
            if (overlap1 > overlap2) parent = g1;
            else if (overlap2 > overlap1) parent = g2;
            else {
                // Or the one with the lowest volume
                int vol1 = g1.getBox().getVolume();
                int vol2 = g2.getBox().getVolume();
                if (vol1 > vol2) parent = g2;
                else if (vol2 > vol1) parent = g1;
                else {
                    // Or the one with the least items
                    if (g1.getChildren().size() < g2.getChildren().size()) parent = g1;
                    else parent = g2;
                }
            }
            parent.getChildren().add(nmax);
            nmax.setParent(parent);
        }

        if (!n.getChildren().isEmpty()) {
            Node<T> parent;
            if (g1.getChildren().size() == rTree.getMaxSize() - rTree.getMinSize() + 1)
                parent = g2;
            else
                parent = g1;

            for (int i = 0; i < n.getChildren().size(); i++) {
                parent.getChildren().add(n.getChildren().get(i));
                n.getChildren().get(i).setParent(parent);
            }
            n.getChildren().clear();
        }
    }

    @SuppressWarnings("unchecked")
    private void distributeLeaves(Node<T> n, Node<T> g1, Node<T> g2) {
        // Same process as above; just different types.
        assert (n.isLeaf() && g1.isLeaf() && g2.isLeaf());

        while (!n.getData().isEmpty() && g1.getData().size() < rTree.getMaxSize() - rTree.getMinSize() + 1 &&
                g2.getData().size() < rTree.getMaxSize() - rTree.getMinSize() + 1) {
            // Pick next
            int difmax = Integer.MIN_VALUE;
            int nmax_index = -1;
            for (int i = 0; i < n.getData().size(); i++) {
                BoundedObject node = n.getData().get(i);
                int d1 = node.getBounds().expansionNeeded(g1.getBox());
                int d2 = node.getBounds().expansionNeeded(g2.getBox());
                int dif = Math.abs(d1 - d2);
                if (dif > difmax) {
                    difmax = dif;
                    nmax_index = i;
                }
            }
            assert (nmax_index != -1);

            // Distribute Entry
            T nmax = n.getData().remove(nmax_index);

            // ... to the one with the least expansion
            int overlap1 = nmax.getBounds().expansionNeeded(g1.getBox());
            int overlap2 = nmax.getBounds().expansionNeeded(g2.getBox());
            if (overlap1 > overlap2) g1.getData().add(nmax);
            else if (overlap2 > overlap1) g2.getData().add(nmax);
            else {
                int vol1 = g1.getBox().getVolume();
                int vol2 = g2.getBox().getVolume();
                if (vol1 > vol2) g2.getData().add(nmax);
                else if (vol2 > vol1) g1.getData().add(nmax);
                else {
                    if (g1.getData().size() < g2.getData().size()) g1.getData().add(nmax);
                    else g2.getData().add(nmax);
                }
            }
        }

        if (!n.getData().isEmpty()) {
            if (g1.getData().size() == rTree.getMaxSize() - rTree.getMinSize() + 1)
                g2.getData().addAll(n.getData());
            else
                g1.getData().addAll(n.getData());
            n.getData().clear();
        }
    }
}