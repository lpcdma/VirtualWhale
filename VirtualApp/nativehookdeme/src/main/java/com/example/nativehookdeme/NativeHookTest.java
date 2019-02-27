package com.example.nativehookdeme;

public class NativeHookTest {
    static {
        System.loadLibrary("native-lib");
    }
    public static native void toDo() ;
}
