cmake_minimum_required (VERSION 3.8)

#include_directories(${CMAKE_SOURCE_DIR}/deps/jsoncpp/include)
#link_directories(${CMAKE_SOURCE_DIR}/deps/jsoncpp/lib)

project ("Demo-Cpp-Json-Xml-Parse")

aux_source_directory(${CMAKE_SOURCE_DIR}/src/demo_json SRC_DEMO_JSON)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo_json/libjsoncpp)
add_executable(demo_json ${SRC_DEMO_JSON})
target_link_libraries(demo_json _lib_jsoncpp)

