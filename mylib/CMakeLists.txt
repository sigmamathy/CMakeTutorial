add_library(mylib math.cpp)

install(TARGETS mylib DESTINATION lib)
install(FILES math.hpp DESTINATION include)