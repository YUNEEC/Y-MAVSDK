#!/bin/bash

set -ex

#
# Prerequisites
#
# o Android SDK
# o Android NDK
# o CMake (included in Android SDK)
#
# Install via sdkmanager: https://developer.android.com/studio/command-line/sdkmanager
#
# o sdkmanager --install "cmake;3.10.2.4988404" "platform-tools" "platforms;android-30" "ndk;23.0.7599858"
#

export ANDROID_SDK_HOME=${ANDROID_SDK_HOME:=/home/yhzheng/Android/Sdk}
export ANDROID_SDK_ROOT=${ANDROID_SDK_HOME}
export ANDROID_SDK=${ANDROID_SDK_HOME}

export ANDROID_NDK_HOME=${ANDROID_NDK_HOME:=${ANDROID_SDK_HOME}/ndk/23.0.7599858}
export ANDROID_NDK_ROOT=${ANDROID_NDK_HOME}
export ANDROID_NDK=${ANDROID_NDK_HOME}

export ANDROID_CMAKE_BIN=${ANDROID_SDK}/cmake/3.10.2.4988404/bin/cmake

export TARGET_ARCH=${TARGET_ARCH:=armeabi-v7a}
export ANDROID_ABI=${TARGET_ARCH}
export ANDROID_PLATFORM=${ANDROID_PLATFORM:=android-21}
#export ANDROID_STL=c++_static
#export ANDROID_CPP_FEATURES="rtti exceptions"

# needed to compile openssl
export PATH=${ANDROID_NDK_HOME}/toolchains/llvm/prebuilt/linux-x86_64/bin:${PATH}

if [ x"$1" == x"clean" ] ; then
  if [ -d $TARGET_ARCH ] ; then
    rm -rf $TARGET_ARCH
  fi
else
  if [ ! -d $TARGET_ARCH ] ; then
    mkdir $TARGET_ARCH
  fi

  cd $TARGET_ARCH && $ANDROID_CMAKE_BIN -DCMAKE_BUILD_TYPE=Release -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DBUILD_MAVSDK_SERVER=ON \
      -DANDROID_ABI=$ANDROID_ABI \
      -DANDROID_PLATFORM=$ANDROID_PLATFORM \
      -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
    ../../ && make
fi
