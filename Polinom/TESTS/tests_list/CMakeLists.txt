#new_app("TEST_list")
enable_testing()

add_executable(
    TEST_list
    test_main.cpp
    test_list.cpp
    "../../LIBS/lib_list/lib_list.cpp"
)
target_link_libraries(
    TEST_list
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TEST_list)