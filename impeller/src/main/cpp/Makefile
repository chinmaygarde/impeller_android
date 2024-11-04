ANDROID_NDK:=~/Library/Android/sdk/ndk/27.0.12077973
ANDROID_ABI:=arm64-v8a

main:
	cmake -B build 																										\
		-DCMAKE_SYSTEM_NAME=Android 																		\
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON 															\
		-DCMAKE_SYSTEM_VERSION=21 																			\
		-DANDROID_PLATFORM=android-21 																	\
		-DANDROID_ABI=${ANDROID_ABI} 																	  \
		-DCMAKE_ANDROID_ARCH_ABI=${ANDROID_ABI} 												\
		-DANDROID_NDK=${ANDROID_NDK} 																		\
		-DCMAKE_ANDROID_NDK=${ANDROID_NDK} 															\
		-DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake \
		-GNinja 																												\
