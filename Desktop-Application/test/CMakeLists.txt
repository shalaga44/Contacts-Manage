file(GLOB test_SRCS  "./*/*.cpp")

add_executable(runUnitTests gtest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests)