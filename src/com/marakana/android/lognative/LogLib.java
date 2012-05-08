
package com.marakana.android.lognative;

import android.util.Log;

public class LogLib {
    public static void logJ(int priority, String tag, String msg) {
        Log.println(priority, tag, msg);
    }

    public native static void logN(int priority, String tag, String msg);

    static {
        System.loadLibrary("com_marakana_android_lognative_LogLib");
    }
}
