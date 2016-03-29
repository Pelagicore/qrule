cmake_minimum_required(VERSION 3.3)
set(SOURCE_FILES 
        krulevisitor.cpp
        gen/Printer.C
        gen/Parser.C
        gen/Lexer.C
        gen/Absyn.C
        main.cpp
        QmlVisitor.cpp
        output/KRuleOutput.cpp
        output/xmloutputformatter.cpp
        retType/RetTypeUInt.cpp
        retType/RetTypeString.cpp
        retType/RetTypeBool.cpp
        QMLChildren.cpp
        nodewrapper.cpp
        )
include_directories(.)

add_executable(KRuleEngine ${SOURCE_FILES} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED COMPONENTS Private)
find_package(Qt5Quick REQUIRED COMPONENTS Private)
include_directories(${Qt5Qml_PRIVATE_INCLUDE_DIRS})
target_link_libraries(KRuleEngine ${Qt5Core_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Qml_LIBRARIES})
