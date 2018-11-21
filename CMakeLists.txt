cmake_minimum_required(VERSION 3.1...3.12)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Day7Redux VERSION 1.0
                  DESCRIPTION "Reviewing the hardest challenge of 2017"
                  LANGUAGES CXX)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(src)
#add_subdirectory(test)

#enable_testing()
#add_test(NAME MyTest COMMAND Test)
