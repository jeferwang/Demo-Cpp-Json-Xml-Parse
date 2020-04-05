cmake_minimum_required (VERSION 3.8)

#include_directories(${CMAKE_SOURCE_DIR}/deps/jsoncpp/include)
#link_directories(${CMAKE_SOURCE_DIR}/deps/jsoncpp/lib)

project ("Demo-Cpp-Json-Xml-Parse")
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo_json/libjsoncpp)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/demo_json SRC_DEMO_JSON)
add_executable(demo_json ${SRC_DEMO_JSON})
target_link_libraries(demo_json _lib_jsoncpp)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/demo_xml SRC_DEMO_XML)
add_executable(demo_xml ${SRC_DEMO_XML})