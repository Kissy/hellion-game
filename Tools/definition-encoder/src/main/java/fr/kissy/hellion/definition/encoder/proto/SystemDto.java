// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Proto/Common/System.proto

package fr.kissy.hellion.definition.encoder.proto;

public final class SystemDto {
  private SystemDto() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface SystemProtoOrBuilder
      extends com.google.protobuf.MessageOrBuilder {
    
    // required .SystemProto.Type type = 1;
    boolean hasType();
    fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type getType();
    
    // repeated .PropertyProto properties = 2;
    java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> 
        getPropertiesList();
    fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto getProperties(int index);
    int getPropertiesCount();
    java.util.List<? extends fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder> 
        getPropertiesOrBuilderList();
    fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder getPropertiesOrBuilder(
        int index);
  }
  public static final class SystemProto extends
      com.google.protobuf.GeneratedMessage
      implements SystemProtoOrBuilder {
    // Use SystemProto.newBuilder() to construct.
    private SystemProto(Builder builder) {
      super(builder);
    }
    private SystemProto(boolean noInit) {}
    
    private static final SystemProto defaultInstance;
    public static SystemProto getDefaultInstance() {
      return defaultInstance;
    }
    
    public SystemProto getDefaultInstanceForType() {
      return defaultInstance;
    }
    
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return fr.kissy.hellion.definition.encoder.proto.SystemDto.internal_static_SystemProto_descriptor;
    }
    
    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return fr.kissy.hellion.definition.encoder.proto.SystemDto.internal_static_SystemProto_fieldAccessorTable;
    }
    
    public enum Type
        implements com.google.protobuf.ProtocolMessageEnum {
      AI(0, 0),
      AUDIO(1, 1),
      GEOMETRY(2, 2),
      GRAPHIC(3, 3),
      INPUT(4, 4),
      PHYSIC(5, 5),
      ;
      
      public static final int AI_VALUE = 0;
      public static final int AUDIO_VALUE = 1;
      public static final int GEOMETRY_VALUE = 2;
      public static final int GRAPHIC_VALUE = 3;
      public static final int INPUT_VALUE = 4;
      public static final int PHYSIC_VALUE = 5;
      
      
      public final int getNumber() { return value; }
      
      public static Type valueOf(int value) {
        switch (value) {
          case 0: return AI;
          case 1: return AUDIO;
          case 2: return GEOMETRY;
          case 3: return GRAPHIC;
          case 4: return INPUT;
          case 5: return PHYSIC;
          default: return null;
        }
      }
      
      public static com.google.protobuf.Internal.EnumLiteMap<Type>
          internalGetValueMap() {
        return internalValueMap;
      }
      private static com.google.protobuf.Internal.EnumLiteMap<Type>
          internalValueMap =
            new com.google.protobuf.Internal.EnumLiteMap<Type>() {
              public Type findValueByNumber(int number) {
                return Type.valueOf(number);
              }
            };
      
      public final com.google.protobuf.Descriptors.EnumValueDescriptor
          getValueDescriptor() {
        return getDescriptor().getValues().get(index);
      }
      public final com.google.protobuf.Descriptors.EnumDescriptor
          getDescriptorForType() {
        return getDescriptor();
      }
      public static final com.google.protobuf.Descriptors.EnumDescriptor
          getDescriptor() {
        return fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.getDescriptor().getEnumTypes().get(0);
      }
      
      private static final Type[] VALUES = {
        AI, AUDIO, GEOMETRY, GRAPHIC, INPUT, PHYSIC, 
      };
      
      public static Type valueOf(
          com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
        if (desc.getType() != getDescriptor()) {
          throw new java.lang.IllegalArgumentException(
            "EnumValueDescriptor is not for this type.");
        }
        return VALUES[desc.getIndex()];
      }
      
      private final int index;
      private final int value;
      
      private Type(int index, int value) {
        this.index = index;
        this.value = value;
      }
      
      // @@protoc_insertion_point(enum_scope:SystemProto.Type)
    }
    
    private int bitField0_;
    // required .SystemProto.Type type = 1;
    public static final int TYPE_FIELD_NUMBER = 1;
    private fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type type_;
    public boolean hasType() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    public fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type getType() {
      return type_;
    }
    
    // repeated .PropertyProto properties = 2;
    public static final int PROPERTIES_FIELD_NUMBER = 2;
    private java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> properties_;
    public java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> getPropertiesList() {
      return properties_;
    }
    public java.util.List<? extends fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder> 
        getPropertiesOrBuilderList() {
      return properties_;
    }
    public int getPropertiesCount() {
      return properties_.size();
    }
    public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto getProperties(int index) {
      return properties_.get(index);
    }
    public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder getPropertiesOrBuilder(
        int index) {
      return properties_.get(index);
    }
    
    private void initFields() {
      type_ = fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type.AI;
      properties_ = java.util.Collections.emptyList();
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized != -1) return isInitialized == 1;
      
      if (!hasType()) {
        memoizedIsInitialized = 0;
        return false;
      }
      for (int i = 0; i < getPropertiesCount(); i++) {
        if (!getProperties(i).isInitialized()) {
          memoizedIsInitialized = 0;
          return false;
        }
      }
      memoizedIsInitialized = 1;
      return true;
    }
    
    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeEnum(1, type_.getNumber());
      }
      for (int i = 0; i < properties_.size(); i++) {
        output.writeMessage(2, properties_.get(i));
      }
      getUnknownFields().writeTo(output);
    }
    
    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;
    
      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeEnumSize(1, type_.getNumber());
      }
      for (int i = 0; i < properties_.size(); i++) {
        size += com.google.protobuf.CodedOutputStream
          .computeMessageSize(2, properties_.get(i));
      }
      size += getUnknownFields().getSerializedSize();
      memoizedSerializedSize = size;
      return size;
    }
    
    private static final long serialVersionUID = 0L;
    @java.lang.Override
    protected java.lang.Object writeReplace()
        throws java.io.ObjectStreamException {
      return super.writeReplace();
    }
    
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return newBuilder().mergeFrom(data).buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return newBuilder().mergeFrom(data, extensionRegistry)
               .buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return newBuilder().mergeFrom(data).buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return newBuilder().mergeFrom(data, extensionRegistry)
               .buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return newBuilder().mergeFrom(input).buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return newBuilder().mergeFrom(input, extensionRegistry)
               .buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      Builder builder = newBuilder();
      if (builder.mergeDelimitedFrom(input)) {
        return builder.buildParsed();
      } else {
        return null;
      }
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      Builder builder = newBuilder();
      if (builder.mergeDelimitedFrom(input, extensionRegistry)) {
        return builder.buildParsed();
      } else {
        return null;
      }
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return newBuilder().mergeFrom(input).buildParsed();
    }
    public static fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return newBuilder().mergeFrom(input, extensionRegistry)
               .buildParsed();
    }
    
    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto prototype) {
      return newBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() { return newBuilder(this); }
    
    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessage.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder>
       implements fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProtoOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return fr.kissy.hellion.definition.encoder.proto.SystemDto.internal_static_SystemProto_descriptor;
      }
      
      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return fr.kissy.hellion.definition.encoder.proto.SystemDto.internal_static_SystemProto_fieldAccessorTable;
      }
      
      // Construct using fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }
      
      private Builder(BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders) {
          getPropertiesFieldBuilder();
        }
      }
      private static Builder create() {
        return new Builder();
      }
      
      public Builder clear() {
        super.clear();
        type_ = fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type.AI;
        bitField0_ = (bitField0_ & ~0x00000001);
        if (propertiesBuilder_ == null) {
          properties_ = java.util.Collections.emptyList();
          bitField0_ = (bitField0_ & ~0x00000002);
        } else {
          propertiesBuilder_.clear();
        }
        return this;
      }
      
      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }
      
      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.getDescriptor();
      }
      
      public fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto getDefaultInstanceForType() {
        return fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.getDefaultInstance();
      }
      
      public fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto build() {
        fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }
      
      private fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto buildParsed()
          throws com.google.protobuf.InvalidProtocolBufferException {
        fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(
            result).asInvalidProtocolBufferException();
        }
        return result;
      }
      
      public fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto buildPartial() {
        fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto result = new fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.type_ = type_;
        if (propertiesBuilder_ == null) {
          if (((bitField0_ & 0x00000002) == 0x00000002)) {
            properties_ = java.util.Collections.unmodifiableList(properties_);
            bitField0_ = (bitField0_ & ~0x00000002);
          }
          result.properties_ = properties_;
        } else {
          result.properties_ = propertiesBuilder_.build();
        }
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }
      
      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto) {
          return mergeFrom((fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }
      
      public Builder mergeFrom(fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto other) {
        if (other == fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.getDefaultInstance()) return this;
        if (other.hasType()) {
          setType(other.getType());
        }
        if (propertiesBuilder_ == null) {
          if (!other.properties_.isEmpty()) {
            if (properties_.isEmpty()) {
              properties_ = other.properties_;
              bitField0_ = (bitField0_ & ~0x00000002);
            } else {
              ensurePropertiesIsMutable();
              properties_.addAll(other.properties_);
            }
            onChanged();
          }
        } else {
          if (!other.properties_.isEmpty()) {
            if (propertiesBuilder_.isEmpty()) {
              propertiesBuilder_.dispose();
              propertiesBuilder_ = null;
              properties_ = other.properties_;
              bitField0_ = (bitField0_ & ~0x00000002);
              propertiesBuilder_ = 
                com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders ?
                   getPropertiesFieldBuilder() : null;
            } else {
              propertiesBuilder_.addAllMessages(other.properties_);
            }
          }
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }
      
      public final boolean isInitialized() {
        if (!hasType()) {
          
          return false;
        }
        for (int i = 0; i < getPropertiesCount(); i++) {
          if (!getProperties(i).isInitialized()) {
            
            return false;
          }
        }
        return true;
      }
      
      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder(
            this.getUnknownFields());
        while (true) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              this.setUnknownFields(unknownFields.build());
              onChanged();
              return this;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                this.setUnknownFields(unknownFields.build());
                onChanged();
                return this;
              }
              break;
            }
            case 8: {
              int rawValue = input.readEnum();
              fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type value = fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type.valueOf(rawValue);
              if (value == null) {
                unknownFields.mergeVarintField(1, rawValue);
              } else {
                bitField0_ |= 0x00000001;
                type_ = value;
              }
              break;
            }
            case 18: {
              fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder subBuilder = fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.newBuilder();
              input.readMessage(subBuilder, extensionRegistry);
              addProperties(subBuilder.buildPartial());
              break;
            }
          }
        }
      }
      
      private int bitField0_;
      
      // required .SystemProto.Type type = 1;
      private fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type type_ = fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type.AI;
      public boolean hasType() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      public fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type getType() {
        return type_;
      }
      public Builder setType(fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type value) {
        if (value == null) {
          throw new NullPointerException();
        }
        bitField0_ |= 0x00000001;
        type_ = value;
        onChanged();
        return this;
      }
      public Builder clearType() {
        bitField0_ = (bitField0_ & ~0x00000001);
        type_ = fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Type.AI;
        onChanged();
        return this;
      }
      
      // repeated .PropertyProto properties = 2;
      private java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> properties_ =
        java.util.Collections.emptyList();
      private void ensurePropertiesIsMutable() {
        if (!((bitField0_ & 0x00000002) == 0x00000002)) {
          properties_ = new java.util.ArrayList<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto>(properties_);
          bitField0_ |= 0x00000002;
         }
      }
      
      private com.google.protobuf.RepeatedFieldBuilder<
          fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder> propertiesBuilder_;
      
      public java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> getPropertiesList() {
        if (propertiesBuilder_ == null) {
          return java.util.Collections.unmodifiableList(properties_);
        } else {
          return propertiesBuilder_.getMessageList();
        }
      }
      public int getPropertiesCount() {
        if (propertiesBuilder_ == null) {
          return properties_.size();
        } else {
          return propertiesBuilder_.getCount();
        }
      }
      public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto getProperties(int index) {
        if (propertiesBuilder_ == null) {
          return properties_.get(index);
        } else {
          return propertiesBuilder_.getMessage(index);
        }
      }
      public Builder setProperties(
          int index, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto value) {
        if (propertiesBuilder_ == null) {
          if (value == null) {
            throw new NullPointerException();
          }
          ensurePropertiesIsMutable();
          properties_.set(index, value);
          onChanged();
        } else {
          propertiesBuilder_.setMessage(index, value);
        }
        return this;
      }
      public Builder setProperties(
          int index, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder builderForValue) {
        if (propertiesBuilder_ == null) {
          ensurePropertiesIsMutable();
          properties_.set(index, builderForValue.build());
          onChanged();
        } else {
          propertiesBuilder_.setMessage(index, builderForValue.build());
        }
        return this;
      }
      public Builder addProperties(fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto value) {
        if (propertiesBuilder_ == null) {
          if (value == null) {
            throw new NullPointerException();
          }
          ensurePropertiesIsMutable();
          properties_.add(value);
          onChanged();
        } else {
          propertiesBuilder_.addMessage(value);
        }
        return this;
      }
      public Builder addProperties(
          int index, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto value) {
        if (propertiesBuilder_ == null) {
          if (value == null) {
            throw new NullPointerException();
          }
          ensurePropertiesIsMutable();
          properties_.add(index, value);
          onChanged();
        } else {
          propertiesBuilder_.addMessage(index, value);
        }
        return this;
      }
      public Builder addProperties(
          fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder builderForValue) {
        if (propertiesBuilder_ == null) {
          ensurePropertiesIsMutable();
          properties_.add(builderForValue.build());
          onChanged();
        } else {
          propertiesBuilder_.addMessage(builderForValue.build());
        }
        return this;
      }
      public Builder addProperties(
          int index, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder builderForValue) {
        if (propertiesBuilder_ == null) {
          ensurePropertiesIsMutable();
          properties_.add(index, builderForValue.build());
          onChanged();
        } else {
          propertiesBuilder_.addMessage(index, builderForValue.build());
        }
        return this;
      }
      public Builder addAllProperties(
          java.lang.Iterable<? extends fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto> values) {
        if (propertiesBuilder_ == null) {
          ensurePropertiesIsMutable();
          super.addAll(values, properties_);
          onChanged();
        } else {
          propertiesBuilder_.addAllMessages(values);
        }
        return this;
      }
      public Builder clearProperties() {
        if (propertiesBuilder_ == null) {
          properties_ = java.util.Collections.emptyList();
          bitField0_ = (bitField0_ & ~0x00000002);
          onChanged();
        } else {
          propertiesBuilder_.clear();
        }
        return this;
      }
      public Builder removeProperties(int index) {
        if (propertiesBuilder_ == null) {
          ensurePropertiesIsMutable();
          properties_.remove(index);
          onChanged();
        } else {
          propertiesBuilder_.remove(index);
        }
        return this;
      }
      public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder getPropertiesBuilder(
          int index) {
        return getPropertiesFieldBuilder().getBuilder(index);
      }
      public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder getPropertiesOrBuilder(
          int index) {
        if (propertiesBuilder_ == null) {
          return properties_.get(index);  } else {
          return propertiesBuilder_.getMessageOrBuilder(index);
        }
      }
      public java.util.List<? extends fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder> 
           getPropertiesOrBuilderList() {
        if (propertiesBuilder_ != null) {
          return propertiesBuilder_.getMessageOrBuilderList();
        } else {
          return java.util.Collections.unmodifiableList(properties_);
        }
      }
      public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder addPropertiesBuilder() {
        return getPropertiesFieldBuilder().addBuilder(
            fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.getDefaultInstance());
      }
      public fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder addPropertiesBuilder(
          int index) {
        return getPropertiesFieldBuilder().addBuilder(
            index, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.getDefaultInstance());
      }
      public java.util.List<fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder> 
           getPropertiesBuilderList() {
        return getPropertiesFieldBuilder().getBuilderList();
      }
      private com.google.protobuf.RepeatedFieldBuilder<
          fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder> 
          getPropertiesFieldBuilder() {
        if (propertiesBuilder_ == null) {
          propertiesBuilder_ = new com.google.protobuf.RepeatedFieldBuilder<
              fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProto.Builder, fr.kissy.hellion.definition.encoder.proto.PropertyDto.PropertyProtoOrBuilder>(
                  properties_,
                  ((bitField0_ & 0x00000002) == 0x00000002),
                  getParentForChildren(),
                  isClean());
          properties_ = null;
        }
        return propertiesBuilder_;
      }
      
      // @@protoc_insertion_point(builder_scope:SystemProto)
    }
    
    static {
      defaultInstance = new SystemProto(true);
      defaultInstance.initFields();
    }
    
    // @@protoc_insertion_point(class_scope:SystemProto)
  }
  
  private static com.google.protobuf.Descriptors.Descriptor
    internal_static_SystemProto_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_SystemProto_fieldAccessorTable;
  
  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\031Proto/Common/System.proto\032\033Proto/Commo" +
      "n/Property.proto\"\237\001\n\013SystemProto\022\037\n\004type" +
      "\030\001 \002(\0162\021.SystemProto.Type\022\"\n\nproperties\030" +
      "\002 \003(\0132\016.PropertyProto\"K\n\004Type\022\006\n\002AI\020\000\022\t\n" +
      "\005AUDIO\020\001\022\014\n\010GEOMETRY\020\002\022\013\n\007GRAPHIC\020\003\022\t\n\005I" +
      "NPUT\020\004\022\n\n\006PHYSIC\020\005B9\n)fr.kissy.hellion.d" +
      "efinition.encoder.protoB\tSystemDto\210\001\000"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
      new com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner() {
        public com.google.protobuf.ExtensionRegistry assignDescriptors(
            com.google.protobuf.Descriptors.FileDescriptor root) {
          descriptor = root;
          internal_static_SystemProto_descriptor =
            getDescriptor().getMessageTypes().get(0);
          internal_static_SystemProto_fieldAccessorTable = new
            com.google.protobuf.GeneratedMessage.FieldAccessorTable(
              internal_static_SystemProto_descriptor,
              new java.lang.String[] { "Type", "Properties", },
              fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.class,
              fr.kissy.hellion.definition.encoder.proto.SystemDto.SystemProto.Builder.class);
          return null;
        }
      };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
          fr.kissy.hellion.definition.encoder.proto.PropertyDto.getDescriptor(),
        }, assigner);
  }
  
  // @@protoc_insertion_point(outer_class_scope)
}
