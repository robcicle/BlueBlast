cmake_minimum_required(VERSION 3.28)
project(BlueBlast)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
add_executable(BlueBlast ${SOURCES})

include_directories(src)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(BlueBlast PRIVATE SFML::Graphics)

add_custom_command(TARGET BlueBlast POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:BlueBlast>/data)

add_custom_command(TARGET BlueBlast POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data ${CMAKE_BINARY_DIR}/data)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT BlueBlast)