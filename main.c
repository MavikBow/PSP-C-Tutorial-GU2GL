#include "callbacks.h"

#define GUGL_IMPLEMENTATION
#include "gu2gl.h"

// PSP Module Info

PSP_MODULE_INFO("Context Sample", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int running = 1;

// GE LIST
static unsigned int __attribute__((aligned(16))) list[262144];



int main(){
    setupCallbacks();

    guglInit(list);

    while(running){
        guglStartFrame(list, GL_FALSE);

        glClearColor(0xFF00F0F0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        guglSwapBuffers(GL_TRUE, GL_FALSE);
    }

    guglTerm();

    sceKernelExitGame();
    return 0;
}