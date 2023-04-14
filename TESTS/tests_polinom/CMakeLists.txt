#new_app("TEST_polinom")
enable_testing()

add_executable(
    TEST_polinom
    test_main.cpp
    test_polinom.cpp
    "../../LIBS/lib_term/lib_term.cpp"
    "../../LIBS/lib_monom/lib_monom.cpp"
    "../../LIBS/lib_xiaoexpr/lib_xiaoexpr.cpp"
    "../../LIBS/lib_polinom/lib_polinom.cpp"
)
target_link_libraries(
    TEST_polinom
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TEST_polinom)