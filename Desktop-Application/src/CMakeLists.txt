file(GLOB core_SRCS  "./*/*.cpp" "./*/*.h")
PROJECT(ContactsManager)

add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)
