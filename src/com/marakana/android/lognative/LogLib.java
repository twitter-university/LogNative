
package com.marakana.android.lognative;

import android.util.Log;

public class LogLib {
    public static void logJ(int priority, String tag, String msg) {
        Log.println(priority, tag, msg);
    }

    public static void logN(int priority, String tag, String msg) {
        throw new UnsupportedOperationException("Implement me as a native method!");
    }
}
