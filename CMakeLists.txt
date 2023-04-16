cmake_minimum_required(VERSION 3.22)
project(font)


add_subdirectory(extern/glad)
add_subdirectory(extern/freetype)

configure_file(include/root_directory.h.in include/root_directory.h)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(font main.cpp text_renderer.cpp)
target_include_directories(font PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(font PUBLIC ${PROJECT_BINARY_DIR}/include)
target_link_libraries(font PUBLIC glad freetype glfw OpenGL)
target_compile_definitions(font PRIVATE GLFW_INCLUDE_NONE)


add_custom_command(TARGET font POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_LIST_DIR}/resources/
    ${PROJECT_BINARY_DIR}/resources/
    COMMENT "Copy resources to build tree")