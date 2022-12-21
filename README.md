configure and build with cmake using command line

For Windows, use `project.bat`:

    project cfg
    project

Or in other operating system:

    cd out
    cmake .. -DGLFW_BUILD_DOCS=OFF
    make
    ./NewTest