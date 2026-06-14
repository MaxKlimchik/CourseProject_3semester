cmake_minimum_required(VERSION 3.19)
project(SpellCheckService LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SpellCheckService
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    UI_text.h
)

add_library(spellcheck_lib SHARED
    ../ClassLibrary/libs/Service.cpp
    ../ClassLibrary/libs/NearestPrime.cpp
    ../ClassLibrary/libs/SC_SimpleFactory.cpp
    ../ClassLibrary/libs/SC_Bloom_filter.cpp
    ../ClassLibrary/libs/SC_HT_Chain.cpp
    ../ClassLibrary/libs/SC_HT_DoubleHash.cpp
    ../ClassLibrary/libs/SC_HT_Linear.cpp
    ../ClassLibrary/libs/MurmurHash3.cpp
    ../ClassLibrary/libs/Dictionary_RU.cpp
    ../ClassLibrary/libs/hash_function.cpp
)

target_link_libraries(SpellCheckService
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_link_libraries(SpellCheckService PRIVATE spellcheck_lib)

target_include_directories(SpellCheckService PRIVATE
    ${CMAKE_SOURCE_DIR}/../ClassLibrary/libs
)

add_custom_command(TARGET SpellCheckService POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:spellcheck_lib>
        $<TARGET_FILE_DIR:SpellCheckService>
    )

install(TARGETS SpellCheckService
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SpellCheckService
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
file(COPY ${CMAKE_SOURCE_DIR}/../ClassLibrary/dictionaries DESTINATION ${CMAKE_BINARY_DIR})
