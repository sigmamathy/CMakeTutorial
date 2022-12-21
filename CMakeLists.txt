cmake_minimum_required(VERSION 3.18.0)

project(NewTest)

# Download Git submodules
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodule as needed
    option(GIT_SUBMODULE "Check submodule during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}.")
        endif()
    endif()
endif()

# Check submodules
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not download! GIT_SUBMODULE was turned off or failed.")
endif()

# Main output
add_executable(${PROJECT_NAME} main.cpp)
# Add subprojects and external submodules
add_subdirectory(mylib)
add_subdirectory(external/glfw)

# include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC mylib
    PUBLIC external/glfw/include
)

# link directories
target_link_directories(${PROJECT_NAME}
    PRIVATE mylib
    PRIVATE external/glfw
)

# link libraries
target_link_libraries(${PROJECT_NAME}
    mylib
    glfw
)