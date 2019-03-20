cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../distribution)

add_library(lib_whale SHARED IMPORTED)
set_target_properties(lib_whale PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/whale/lib/${ANDROID_ABI}/libwhale.so)

add_library( native-lib
        SHARED
        native-lib.cpp
        util.c)

target_include_directories(native-lib PRIVATE
        ${distribution_DIR}/whale/include)

find_library( log-lib log )

target_link_libraries( native-lib
        lib_whale
        ${log-lib} )