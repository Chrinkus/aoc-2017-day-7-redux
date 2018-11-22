find_package(Catch2 REQUIRED)

add_executable(tests tests-main.cpp
                     tests-find_diff.cpp)
target_link_libraries(tests PUBLIC Catch2::Catch2)
target_link_libraries(tests PUBLIC find_diff)

include(CTest)
include(Catch)
catch_discover_tests(tests)
