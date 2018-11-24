find_package(Catch2 REQUIRED)

add_executable(tests tests-main.cpp
                     tests-find_diff.cpp
                     tests-program.cpp
                     tests-tower.cpp)
target_compile_features(tests PRIVATE cxx_std_17)
target_link_libraries(tests PUBLIC Catch2::Catch2)
target_link_libraries(tests PUBLIC program)
target_link_libraries(tests PUBLIC tower)

include(CTest)
include(Catch)
catch_discover_tests(tests)
