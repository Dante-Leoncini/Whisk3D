# Android 2.3 (API 10) en un ARMv6 (armeabi): el NDK r15c es el ultimo que compila para los dos (ver README.md).
# La plataforma android-9 es la de la 2.3 (r15c no trae una android-10 aparte).
APP_ABI := armeabi
APP_PLATFORM := android-9
APP_STL := c++_static
NDK_TOOLCHAIN_VERSION := clang
APP_OPTIM := release
