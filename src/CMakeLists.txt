# Copyright (C) 2016 Pelagicore
#
# You may use this file under the terms of the GPLv3 license.
# See the file LICENSE from this package for details.
#
# SPDX-License-Identifier: GPL-3.0
cmake_minimum_required(VERSION 3.3)
set(SOURCE_FILES 
        qrulevisitor.cpp
        gen/Printer.C
        gen/Parser.C
        gen/Lexer.C
        gen/Absyn.C
        main.cpp
        QmlVisitor.cpp
        output/QRuleOutput.cpp
        output/xmloutputformatter.cpp
        retType/RetTypeUInt.cpp
        retType/RetTypeString.cpp
        retType/RetTypeBool.cpp
        nodewrapper.cpp
        qruleengine.cpp
        )
include_directories(.)

add_executable(QRuleEngine ${SOURCE_FILES} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED COMPONENTS Private)
find_package(Qt5Quick REQUIRED COMPONENTS Private)
include_directories(${Qt5Qml_PRIVATE_INCLUDE_DIRS})
target_link_libraries(QRuleEngine ${Qt5Core_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Qml_LIBRARIES})
