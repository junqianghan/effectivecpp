cmake_minimum_required(VERSION 3.5)
project(effectivecpp)

set(CMAKE_CXX_STANDARD 11)
SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
#set(SOURCE_FILES 32.cpp common.cpp)
#add_executable(main ${SOURCE_FILES})



#add_executable(01 01.cpp)
#add_executable(03 03.cpp)
#add_executable(04 04.cpp)
#add_executable(05 05.cpp)
#add_executable(06 06.cpp)
#add_executable(07 07.cpp)
#add_executable(09 09.cpp)
#add_executable(10 10.cpp)
#add_executable(11 11.cpp)
#add_executable(12 12.cpp)
#add_executable(14 14.cpp)
#add_executable(15 15.cpp)
#add_executable(21 21.cpp)
#add_executable(22 22.cpp)
#add_executable(24 24.cpp)

#add_executable(sort sort.cpp)
#add_executable(main main.cpp)
#
#
#
#add_executable(BinaryTree BinaryTree.cpp common.cpp)

#add_executable(merge_sort merge_sort.cpp)
add_executable(LRU LRU.cpp)
add_executable(string_hash stringhash.cpp)
add_executable(main main.cpp)
add_executable(CPPDeconstruction CPPDeconstruction.cpp)