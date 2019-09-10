cmake_minimum_required(VERSION 3.4.1)

project(badminton-demo)

message(STATUS "SOURCE DIR: ${CMAKE_SOURCE_DIR}")

message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/websocket
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libwebsockets-3.0.1/lib
    ${PROJECT_BINARY_DIR}/thirdparty/libwebsockets-3.0.1
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/jsoncpp-1.8.4/include
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS_ROOT)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/common SRCS_COMMON)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/websocket SRCS_WEBSOKET)

set(SRCS
    ${SRCS_ROOT}
    ${SRCS_COMMON}
    ${SRCS_WEBSOKET}
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libwebsockets-3.0.1)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/jsoncpp-1.8.4)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -Wno-delete-incomplete ${CMAKE_CXX_FLAGS}")

add_compile_options(-g -fPIC -Wno-deprecated-declarations -Wno-write-strings -Wno-varargs -Wno-format)

add_executable(badminton ${SRCS})

target_link_libraries(badminton websockets jsoncpp_lib_static)
