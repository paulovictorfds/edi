cmake_minimum_required(VERSION 3.0)
project(Testes-EDI)

set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Link runTests with what we want to test and the GTest and pthread library
<<<<<<< HEAD
add_executable(runTestsArrayList2 testArrayList2.cpp)
add_executable(runTestsLinkedList2 testLinkedList2.cpp)
add_executable(runTestsDoublyLinkedList2 testDoublyLinkedList2.cpp)
add_executable(runTestsArrayStack2 testArrayStack2.cpp)

target_link_libraries(runTestsArrayList2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsLinkedList2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsDoublyLinkedList2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsArrayStack2 ${GTEST_LIBRARIES} pthread)
=======
# add_executable(runTestsArrayList testArrayList.cpp)
add_executable(runTestsArrayList2 testArrayList2.cpp)
add_executable(runTestsLinkedList2 testLinkedList2.cpp)
add_executable(runTestsDoublyLinkedList2 testDoublyLinkedList2.cpp)

# target_link_libraries(runTestsArrayList ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsArrayList2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsLinkedList2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsDoublyLinkedList2 ${GTEST_LIBRARIES} pthread)
>>>>>>> cc2a3745af9d889b4e36717d2ec1b80fb041011b
