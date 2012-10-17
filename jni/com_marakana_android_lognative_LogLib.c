#define NULL    ((void *)0)
#include "com_marakana_android_lognative_LogLib.h"
#include <android/log.h>

static void ThrowExceptionByClassName(JNIEnv *env, const char *name, const char *message) {
  jclass class = (*env)->FindClass(env, name);
  if (class != NULL) {
      (*env)->ThrowNew(env, class, message);
      (*env)->DeleteLocalRef(env, class);
  }
}

JNIEXPORT void JNICALL Java_com_marakana_android_lognative_LogLib_logN
  (JNIEnv *env, jclass clazz, jint priority, jstring tag, jstring msg) {
	if (priority != ANDROID_LOG_VERBOSE &&
		priority != ANDROID_LOG_DEBUG &&
		priority != ANDROID_LOG_INFO &&
		priority != ANDROID_LOG_WARN &&
		priority != ANDROID_LOG_ERROR) {
		ThrowExceptionByClassName(env, "java/lang/IllegalArgumentException", "Invalid priority");
	} else if (tag == NULL) {
		ThrowExceptionByClassName(env, "java/lang/NullPointerException", "Tag must not be null");
	} else if ((*env)->GetStringLength(env, tag) == 0) {
		ThrowExceptionByClassName(env, "java/lang/IllegalArgumentException", "Tag must not be empty");
	} else if (msg == NULL) {
		ThrowExceptionByClassName(env, "java/lang/NullPointerException", "Msg must not be null");
	} else if ((*env)->GetStringLength(env, msg) == 0) {
		ThrowExceptionByClassName(env, "java/lang/IllegalArgumentException", "Msg must not be empty");
	} else {
		const char *cTag = (*env)->GetStringUTFChars(env, tag, NULL);
		if (cTag) {
			const char *cMsg = (*env)->GetStringUTFChars(env, msg, NULL);
			if (cMsg) {
				__android_log_write(priority, cTag, cMsg);
				(*env)->ReleaseStringUTFChars(env, msg, cMsg);
			}
			(*env)->ReleaseStringUTFChars(env, tag, cTag);
		}
	}
}
