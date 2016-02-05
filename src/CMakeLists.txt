cmake_minimum_required(VERSION 3.3)

set(SOURCE_FILES Skeleton.cpp gen/Printer.cpp gen/Parser.cpp gen/Lexer.cpp gen/Absyn.cpp main.cpp Environment.cpp Environment.h Scope.cpp Scope.h)
include_directories(gen)
add_subdirectory(gen)
add_executable(KRuleEngine ${SOURCE_FILES} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
#find_package(Qt5Qmldevtools-private REQUIRED)

qt5_use_modules(KRuleEngine Core Quick Qml)
#target_link_libraries(KRuleEngine ${Qt5Core_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Qml_LIBRARIES})
