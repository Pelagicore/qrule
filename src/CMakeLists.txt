cmake_minimum_required(VERSION 3.3)
set(SOURCE_FILES 
        krulevisitor.cpp
        gen/Printer.cpp
        gen/Parser.cpp
        gen/Lexer.cpp
        gen/Absyn.cpp
        main.cpp
        QmlVisitor.cpp
        output/KRuleOutput.cpp
        output/xmloutputformatter.cpp
        environment/Environment.cpp
        environment/EnvironmentVerifierQml.cpp
        )
include_directories(.)

add_executable(KRuleEngine ${SOURCE_FILES} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)

target_link_libraries(KRuleEngine ${Qt5Core_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Qml_LIBRARIES})
