cmake_minimum_required(VERSION 3.3)
set(SOURCE_FILES 
        Skeleton.cpp
        gen/Printer.cpp
        gen/Parser.cpp
        gen/Lexer.cpp
        gen/Absyn.cpp
        main.cpp
        Environment.cpp
        Environment.h
        Scope.cpp
        Scope.h
        QmlVisitor.h
        private/qqmljsast.cpp
        private/qqmljsastfwd_p.h
        private/qqmljsast_p.h
        private/qqmljsastvisitor.cpp
        private/qqmljsastvisitor_p.h
        private/qqmljsengine_p.cpp
        private/qqmljsengine_p.h
        private/qqmljsglobal_p.h
        private/qqmljsgrammar.cpp
        private/qqmljsgrammar_p.h
        private/qqmljskeywords_p.h
        private/qqmljslexer.cpp
        private/qqmljslexer_p.h
        private/qqmljsmemorypool_p.h
        private/qqmljsparser.cpp
        private/qqmljsparser_p.h)
include_directories(gen)

add_executable(KRuleEngine ${SOURCE_FILES} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)

target_link_libraries(KRuleEngine ${Qt5Core_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Qml_LIBRARIES}) 
