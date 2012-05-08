LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := com_marakana_android_lognative_LogLib.c
LOCAL_MODULE := com_marakana_android_lognative_LogLib
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)
