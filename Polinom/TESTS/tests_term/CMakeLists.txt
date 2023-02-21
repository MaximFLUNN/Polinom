#new_app("TEST_term")
enable_testing()

add_executable(
    TEST_term
    test_main.cpp
    test_term.cpp
    "../../LIBS/lib_term/lib_term.cpp"
)
target_link_libraries(
    TEST_term
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TEST_term)