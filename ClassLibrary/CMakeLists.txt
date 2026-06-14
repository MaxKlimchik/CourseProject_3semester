cmake_minimum_required(VERSION 3.10)
project(SpellCheckService)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/libs)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Собираем динамическую библиотеку
add_library(spellcheck_lib SHARED
    libs/Service.cpp
    libs/NearestPrime.cpp
    libs/SC_SimpleFactory.cpp
    libs/SC_Bloom_filter.cpp
    libs/SC_HT_Chain.cpp
    libs/SC_HT_DoubleHash.cpp
    libs/SC_HT_Linear.cpp
    libs/MurmurHash3.cpp
    libs/Dictionary_RU.cpp
    libs/hash_function.cpp
)

target_compile_definitions(spellcheck_lib PRIVATE SPELLCHECK_LIB_EXPORTS)

add_executable(console_version_app
    tests/console_version_app.cpp
)
target_link_libraries(console_version_app spellcheck_lib)

add_executable(load_time_tests
    tests/load_time_tests.cpp
)
target_link_libraries(load_time_tests spellcheck_lib)

add_executable(check_dict_tests
    tests/check_dict_tests.cpp
)
target_link_libraries(check_dict_tests spellcheck_lib)

add_custom_command(TARGET console_version_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:spellcheck_lib>
        $<TARGET_FILE_DIR:console_version_app>
)

add_custom_command(TARGET load_time_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:spellcheck_lib>
        $<TARGET_FILE_DIR:load_time_tests>
)

add_custom_command(TARGET check_dict_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:spellcheck_lib>
        $<TARGET_FILE_DIR:check_dict_tests>
)

file(COPY ${CMAKE_SOURCE_DIR}/dictionaries DESTINATION ${CMAKE_BINARY_DIR})