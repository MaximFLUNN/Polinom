#new_app("TEST_monom")
enable_testing()

add_executable(
    TEST_monom
    test_main.cpp
    test_monom.cpp
    "../../LIBS/lib_monom/lib_monom.cpp"
    "../../LIBS/lib_term/lib_term.cpp"
)
target_link_libraries(
    TEST_monom
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TEST_monom)