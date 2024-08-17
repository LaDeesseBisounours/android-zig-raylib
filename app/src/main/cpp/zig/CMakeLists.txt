#build output, this is actually required for at least one build artifact (see add_custom_command)
set(ZIG_BIN "/home/mariezen/.local/share/zig-linux-x86_64-0.13.0/zig")
set(ZIG_LIB "${CMAKE_CURRENT_BINARY_DIR}/libzig.so")

if (CMAKE_ANDROID_ARCH_ABI STREQUAL "armeabi-v7a")
    set(ZIG_TARGET "arm-linux")
    message(STATUS "Target is ${ZIG_TARGET}")
elseif(CMAKE_ANDROID_ARCH_ABI STREQUAL "arm64-v8a")
    set(ZIG_TARGET "aarch64-linux")
    message(STATUS "Target is ${ZIG_TARGET}")
elseif(CMAKE_ANDROID_ARCH_ABI STREQUAL "x86")
    set(ZIG_TARGET "i386-linux")
    message(STATUS "Target is ${ZIG_TARGET}")
elseif(CMAKE_ANDROID_ARCH_ABI STREQUAL "x86_64")
    set(ZIG_TARGET "x86_64-linux")
    message(STATUS "Target is ${ZIG_TARGET}")
else()
    message(FATAL_ERROR "ERROR no valid target selected, CMAKE_ANDROID_ARCH_ABI = ${CMAKE_ANDROID_ARCH_ABI}")
endif()


#custom target required to run custom command
#buildingzig is now a target that depends on our build
add_custom_target(buildingzig
        DEPENDS ${ZIG_LIB}
)

#custom command that contains the code to run
#OUTPUT can be one or many files (one may be sufficient in any case) #COMMAND command must use bash -c and SINGLE QUOTES and cd to the zig directory and finally run the command
#using double quotes or not using cd will break everything
#we call zig build with option -Doutput_dir which is a custom option to specify where zig build should output its 
#libraries etc (see build.zig for more details)
add_custom_command(
        OUTPUT ${ZIG_LIB}
        COMMENT
        "Compiling zig module"
        COMMAND
        echo "building ${ZIG_LIB}"
        COMMAND
        bash -c 'cd ${CMAKE_CURRENT_SOURCE_DIR} && ${ZIG_BIN} build -Doutput_dir=\"${CMAKE_CURRENT_BINARY_DIR}\" -Dtarget=\"${ZIG_TARGET}\"'
)

#Finally we create a target for our library, GLOBAL is required for the target to be accessible at higher levels
add_library(myziglib SHARED IMPORTED GLOBAL)
#create dependency between our target and zig actually building it
add_dependencies(myziglib buildingzig)
#tell cmake where the actual library is
set_property(TARGET myziglib PROPERTY IMPORTED_LOCATION "${ZIG_LIB}")
