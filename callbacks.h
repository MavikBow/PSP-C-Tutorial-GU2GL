#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

int exit_callback(int arg1, int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp){   
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupCallbacks(){
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if (thid >= 0){
    sceKernelStartThread(thid, 0, NULL);
    }
}