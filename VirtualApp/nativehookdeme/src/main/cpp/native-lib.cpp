//
// Created by lpcdm on 2019/2/27.
//
#include <jni.h>
#include <whale.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>

#include <android/log.h>
#include <unistd.h>

#include "util.h"

#define MODULE_NAME  "LOGXX"
#define LOGD(...) __android_log_print(ANDROID_LOG_ERROR, MODULE_NAME, __VA_ARGS__)

char *(*Origin_getenv)(const char *);

char *Hooked_getenv(const char *name) {
    if (!strcmp(name, "lody")) {
        return strdup("are you ok?");
    }
    char *(*O)(const char *) = Origin_getenv;
    return O(name);
}

int (*old___android_log_buf_write)(int bufID, int prio, const char *tag, const char *msg);

int new___android_log_buf_write(int bufID, int prio, const char *tag, const char *msg) {
    LOGD("org log %s : $s", tag, msg);
    return  old___android_log_buf_write(bufID, prio, tag, msg);
}

//_ZNK3art20OatQuickMethodHeader7ToDexPcEPNS_9ArtMethodEjb
int (*old_ToDexPc)(void *thiz, void *a2, unsigned int a3, int a4);
int new_ToDexPc(void *thiz, void *a2, unsigned int a3, int a4) {
    LOGD("TestHook");
    return old_ToDexPc(thiz, a2, a3, 0);
}


extern "C" JNIEXPORT void JNICALL
Java_com_example_nativehookdeme_NativeHookTest_toDo(
        JNIEnv *env,
        jclass type) {
//#if defined(__APPLE__)
//    void *handle = dlopen("libc.dylib", RTLD_NOW);
//#else
//    void *handle = dlopen("libc.so", RTLD_NOW);
//#endif
//    assert(handle != nullptr);
//    void *symbol = dlsym(handle, "getenv");
//    assert(symbol != nullptr);
//    WInlineHookFunction(
//            symbol,
//            reinterpret_cast<void *>(Hooked_getenv),
//            reinterpret_cast<void **>(&Origin_getenv)
//    );
////    WImportHookFunction(
////            "_getenv",
////            reinterpret_cast<void *>(Hooked_getenv),
////            reinterpret_cast<void **>(&Origin_getenv)
////    );
//
//    const char *val = getenv("lody");
//    LOGD("out ==> %s pid ==> %d", val, getpid());

//    void *my_handle = WDynamicLibOpen("libart.so");
//    assert(my_handle != nullptr);
//    void *my_symbol = WDynamicLibSymbol(my_handle, "_ZNK3art20OatQuickMethodHeader7ToDexPcEPNS_9ArtMethodEjb");
//    assert(my_symbol != nullptr);
//    LOGD("my_symbol ==> %p" , my_symbol);
//    WInlineHookFunction(
//            my_symbol,
//            reinterpret_cast<void *>(new_ToDexPc),
//            reinterpret_cast<void **>(&old_ToDexPc)
//    );

//    unsigned long addr = 0;
//    find_name(getpid(), "_ZNK3art20OatQuickMethodHeader7ToDexPcEPNS_9ArtMethodEjb", "libart.so", &addr);
//    void *symbol = (void*)(addr - 1);
//    assert(symbol != nullptr);
//    LOGD("symbol ==> %p" , symbol);
//    WInlineHookFunction(
//            symbol,
//            reinterpret_cast<void *>(new_ToDexPc),
//            reinterpret_cast<void **>(&old_ToDexPc)
//    );
}

