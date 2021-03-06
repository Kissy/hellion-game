// Copyright � 2008-2009 Intel Corporation
// All Rights Reserved
//
// Permission is granted to use, copy, distribute and prepare derivative works of this
// software for any purpose and without fee, provided, that the above copyright notice
// and this statement appear in all copies.  Intel makes no representations about the
// suitability of this software for any purpose.  THIS SOFTWARE IS PROVIDED "AS IS."
// INTEL SPECIFICALLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, AND ALL LIABILITY,
// INCLUDING CONSEQUENTIAL AND OTHER INDIRECT DAMAGES, FOR THE USE OF THIS SOFTWARE,
// INCLUDING LIABILITY FOR INFRINGEMENT OF ANY PROPRIETARY RIGHTS, AND INCLUDING THE
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  Intel does not
// assume any responsibility for any errors which may appear in this software nor any
// responsibility to update it.

#include "Defines.h"
#include <windows.h>
#include <tchar.h>

#include "Framework.h"

int APIENTRY _tWinMain(HINSTANCE hInstanceExe, HINSTANCE, PTSTR pszCmdLine, int nCmdShow) {
    #ifndef DEBUG_BUILD
    //try
    #endif
    {
        // Start framework
        Framework* framework = new Framework();
        if (framework->Initialize() == boost::system::errc::success) {
            framework->Execute();
            framework->Shutdown();
            delete framework;
        }
        MSG Msg;
        while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }
    }
    #ifndef DEBUG_BUILD
    //catch (...) {
    //}
    #endif
    return 0;
}
