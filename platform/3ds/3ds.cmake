# ---------------------------------------------------------------------------------------------------------------
#  Toolchain de CMake para la Nintendo 3DS con devkitARM (lo usa preparar_3ds.sh para compilar SDL2). Hace lo mismo
#  que el 3DS.cmake del paquete de devkitPro: el compilador, el ARM11 de la consola y libctru.
# ---------------------------------------------------------------------------------------------------------------
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR armv6k)
set(NINTENDO_3DS TRUE)

set(DEVKITPRO $ENV{DEVKITPRO})
set(DEVKITARM $ENV{DEVKITARM})
set(CMAKE_C_COMPILER   ${DEVKITARM}/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${DEVKITARM}/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER ${DEVKITARM}/bin/arm-none-eabi-gcc)
set(CMAKE_AR     ${DEVKITARM}/bin/arm-none-eabi-gcc-ar     CACHE FILEPATH "")
set(CMAKE_RANLIB ${DEVKITARM}/bin/arm-none-eabi-gcc-ranlib CACHE FILEPATH "")

set(W3D_ARCH_3DS "-march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft")
set(CMAKE_C_FLAGS_INIT   "${W3D_ARCH_3DS} -D__3DS__ -I${DEVKITPRO}/libctru/include")
set(CMAKE_CXX_FLAGS_INIT "${W3D_ARCH_3DS} -D__3DS__ -I${DEVKITPRO}/libctru/include")
set(CMAKE_ASM_FLAGS_INIT "${W3D_ARCH_3DS}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${W3D_ARCH_3DS} -specs=3dsx.specs -L${DEVKITPRO}/libctru/lib")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH ${DEVKITARM} ${DEVKITPRO}/libctru)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
