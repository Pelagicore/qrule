# Copyright (C) 2016 Pelagicore
#
# You may use this file under the terms of the GPLv3 license.
# See the file LICENSE from this package for details.
#
# SPDX-License-Identifier: GPL-3.0
cmake_minimum_required(VERSION 3.3)
project(KRuleEngine)

if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)
