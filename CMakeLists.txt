cmake_minimum_required(VERSION 3.18.0)

project(NewTest VERSION 1.0)

# Main output
add_executable(${PROJECT_NAME} main.cpp)

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

# Add sublibraries (optional)
option(USE_MYLIB "An simple utility library for multi purpose." ON)
if (USE_MYLIB)
    add_subdirectory(mylib)
    list(APPEND EXTRA_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/mylib")
    list(APPEND EXTRA_LIB_DIRS mylib)
    list(APPEND EXTRA_LINKS mylib)
endif()

# Configuration setup
configure_file(NewTestConfig.h.in NewTestConfig.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Add external submodules
add_subdirectory(external/glfw)

# include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
)

# link directories
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw
    ${EXTRA_LIB_DIRS}
)

# link libraries
target_link_libraries(${PROJECT_NAME}
    glfw
    ${EXTRA_LINKS}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/NewTestConfig.h" DESTINATION include)