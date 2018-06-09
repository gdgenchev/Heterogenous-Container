cmake_minimum_required(VERSION 3.8)
project(Heterogeneous_Container)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES testhglist.cpp heterogeneous_list.cpp containers/container.h containers/dllist.cpp tests/UnitTestFramework.h tests/heterogeneous_list_tests.h containers/queue.cpp containers/stack.cpp condition.h iterator/elem.h iterator/iterator.h simple_containers/simple_stack.cpp simple_containers/simple_queue.cpp simple_containers/simple_dllist.cpp)
add_executable(Heterogeneous_Container ${SOURCE_FILES})
