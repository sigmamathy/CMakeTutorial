cmake_minimum_required(VERSION 3.18.0)

project(NewTest)

add_executable(${PROJECT_NAME} main.cpp)

# Add sub library mylib
add_subdirectory(mylib)
target_include_directories(${PROJECT_NAME} PRIVATE mylib/)
target_link_libraries(${PROJECT_NAME} mylib)