package com.example.javahookdemo;

import com.lody.whale.xposed.XC_MethodHook;
import com.lody.whale.xposed.XposedBridge;
import com.lody.whale.xposed.XposedHelpers;

public class Hooker {
    public static void toDo(ClassLoader classLoader) {
//        XposedHelpers.findAndHookMethod("android.widget.TextView", classLoader, "setText", CharSequence.class, new XC_MethodHook() {
//            @Override
//            protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
//                super.beforeHookedMethod(param);
//                XposedBridge.log("" + param.args[0]);
//                param.args[0] = param.args[0] + "Hooked!";
//            }
//
//            @Override
//            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
//                super.afterHookedMethod(param);
//                XposedBridge.log("" + param.args[0]);
//                param.args[0] = param.args[0] + "Hooked!";
//            }
//        });
        XposedHelpers.findAndHookMethod("com.example.nfh.MainActivity", classLoader, "stringFromJNI", new XC_MethodHook() {
            @Override
            protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                super.afterHookedMethod(param);
//                XposedBridge.log("" + param.args[0]);
//                param.args[0] = param.args[0] + "Hooked!";
                param.setResult(param.getResult() + "Hooked!");
            }
        });
    }
}
