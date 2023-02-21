#new_app("TEST_xiaoexpr")
enable_testing()

add_executable(
    TEST_xiaoexpr
    test_main.cpp
    test_xiaoexpr.cpp
    "../../LIBS/lib_xiaoexpr/lib_xiaoexpr.cpp"
)
target_link_libraries(
    TEST_xiaoexpr
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TEST_xiaoexpr)