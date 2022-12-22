#include <iostream>
#include <GLFW/glfw3.h>
#include <NewTestConfig.h>
#ifdef USE_MYLIB
#include <math.hpp>
#endif

int main(int argc, char** argv)
{
    std::cout << argv[0] << " Version " << NEWTEST_VERSION_MAJOR << '.' << NEWTEST_VERSION_MINOR << '\n';
#ifdef USE_MYLIB
    std::cout << "Area = " << mylib::HeronFormula(3, 4, 5) << '\n';
#endif

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1600, 900, "Hello World", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}