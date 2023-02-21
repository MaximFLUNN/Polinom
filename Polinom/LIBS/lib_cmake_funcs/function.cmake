# чтобы написание cmake-листов было проще, мы вынесли несколько повторяющихся наборов команд в функции,
# с помощью которых можно создавать проект, в котором новая статическая библиотека подхватывает старые,
# а исполняемый проект подхватывает всё

# в случае более сложных взаимосязей предлагается самостоятельно писать cmake-листы на основе предложенных
# разобранных примеров, больше читать здесь - https://ps-group.github.io/cxx/cmake_cheatsheet
# + https://neerc.ifmo.ru/wiki/index.php?title=CMake_Tutorial
# + https://habr.com/ru/post/330902/

# функция, создающая и подключающая библиотеку
function(new_lib TARGET)
    file(GLOB TARGET_SRC "*.c*")        # добавляем в переменную TARGET_SRC все файлы с расширением .c и .cpp
    file(GLOB TARGET_HD "*.h*")         # добавляем в переменную TARGET_HD все файлы с расширением .h и .hpp
    
	# cоздаем СТАТИЧЕСКУЮ библиотеку с именем из переменной ${TARGET},
    # в неё добавляются файлы из переменных ${TARGET_SRC} (исходный код) и ${TARGET_HD} (хедеры);
	# если заменить «STATIC» на «SHARED», то получим библиотеку динамическую. 
	add_library(${TARGET} STATIC ${TARGET_SRC} ${TARGET_HD})
    
	# ${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
	
	# добавляем созданную библиотеку к списку имеющихся
    get_property ( INCLUDE_DIRS GLOBAL PROPERTY INC_DIR)
	get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
	list(APPEND LIB_LIST ${TARGET})
    list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
    set_property ( GLOBAL PROPERTY INC_DIR ${INCLUDE_DIRS})
    set_property ( GLOBAL PROPERTY LIBS_P ${LIB_LIST}) 
endfunction()

# функция, создающая приложение (исполняемый проект)
function(new_app TARGET)
    file(GLOB TARGET_SRC "*.c*")              # добавляем в переменную TARGET_SRC все файлы с расширением .c и .cpp
    file(GLOB TARGET_HD "*.h*")               # добавляем в переменную TARGET_HD все файлы с расширением .h и .hpp
    
	# создаём исполняемый проект,
	# в него добавляются файлы из переменных ${TARGET_SRC} (исходный код) и ${TARGET_HD} (хедеры);
	add_executable(${TARGET} ${TARGET_SRC} ${TARGET_HD})
    
	# добавляем зависимость от всех имеющихся библиотек
    get_property ( INCLUDE_DIRS GLOBAL PROPERTY INC_DIR)
    target_include_directories(${TARGET} PUBLIC ${INCLUDE_DIRS})
    get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
	target_link_libraries(${TARGET} ${LIB_LIST})    
endfunction()

function(add_depend TARGET LIB INCLUDE_DIR)
	# добавляем пути поиска заголовков, от которых зависит создаваемый проект (альтернативный способ)
    #get_property ( INCLUDE_DIRS GLOBAL PROPERTY INC_DIR)
    target_include_directories(${TARGET} PUBLIC ${INCLUDE_DIR})
	
	# линкуем к проекту имеющиеся библиотеки, от которых он зависит (альтернативный способ)
    #get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
	target_link_libraries(${TARGET} ${LIB}) 
endfunction()
