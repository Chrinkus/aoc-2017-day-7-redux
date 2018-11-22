add_library(find_diff STATIC find_diff.h)
set_target_properties(find_diff PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(find_diff PRIVATE cxx_std_14)

add_executable(day7 main.cpp)
target_compile_features(day7 PRIVATE cxx_std_14)
target_link_libraries(day7 PUBLIC find_diff)
