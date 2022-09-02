# Copyright (c) Stanford University, The Regents of the University of
#               California, and others.
#
# All Rights Reserved.
#
# See Copyright-SimVascular.txt for additional details.
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject
# to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
# IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
# OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14.0)
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Set common settings
PROJECT(SMF)
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
SET(CODE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Code/Source")
SET(CODE_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Code/Header")
#-----------------------------------------------------------------------------

include(FetchContent)

## Build Projects ##
#-----------------------------------------------------------------------------
FetchContent_Declare(
  Eigen
  URL "https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip"
)

FetchContent_MakeAvailable(Eigen)
FetchContent_GetProperties(Eigen BINARY_DIR Eigen_BINARY_DIR)

#MESSAGE("Build Directory of Eigen = ${Eigen_BINARY_DIR}")
FIND_PACKAGE(Eigen3 REQUIRED PATHS ${Eigen_BINARY_DIR})

#ADD_EXECUTABLE(SMF ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
SET(headers
    "${CODE_HEADER_DIR}/chol.h"
    "${CODE_HEADER_DIR}/read.h")
#    "${CODE_HEADER_DIR}/model.h"
#    "${CODE_HEADER_DIR}/read.h"
#    "${CODE_HEADER_DIR}/read_phase.h"
#    "${CODE_HEADER_DIR}/setting.h")

SET(sources
    "${CODE_SOURCE_DIR}/chol.cpp"
    "${CODE_SOURCE_DIR}/read.cpp"
    "${CODE_SOURCE_DIR}/main.cpp")

INCLUDE_DIRECTORIES(${CODE_HEADER_DIR})
ADD_EXECUTABLE(SMF ${sources})
#INCLUDE_DIRECTORIES(${CODE_HEADER_DIR})
#TARGET_INCLUDE_DIRECTORIES(SMF PRIVATE ${headers})
TARGET_LINK_LIBRARIES(SMF Eigen3::Eigen)
