# отключаем создание ZERO проекта при сборке CMake
set(CMAKE_SUPPRESS_REGENERATION true)

# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(Polinom)

# устанавливаем автоматическую инициализацию С++20
set(CMAKE_CXX_STANDARD 20)   

# подключение модуля FetchContent
include(FetchContent)

# скачивания архива гугл тестов
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# отключаем возможность изменять параметры компилятора/линковщика родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# гарантируем, что именованные зависимости были заполнены
FetchContent_MakeAvailable(googletest)

# затем следует список инструкций для подключения проектов из подкаталогов
include(LIBS/lib_cmake_funcs/function.cmake)    # подхватываем функции, реализованные в файле function.cmake

add_subdirectory(LIBS/lib_monom)
add_subdirectory(LIBS/lib_polinom)
add_subdirectory(LIBS/lib_list)
add_subdirectory(LIBS/lib_term)
add_subdirectory(LIBS/lib_xiaoexpr)
add_subdirectory(LIBS/lib_color)

add_subdirectory(TESTS/tests_monom)
add_subdirectory(TESTS/tests_polinom)
add_subdirectory(TESTS/tests_list)
add_subdirectory(TESTS/tests_term)
add_subdirectory(TESTS/tests_xiaoexpr)

add_subdirectory(APPS/application_monom)
add_subdirectory(APPS/application_polinom)
add_subdirectory(APPS/application_list)
add_subdirectory(APPS/application_term)
add_subdirectory(APPS/application_xiaoexpr)





