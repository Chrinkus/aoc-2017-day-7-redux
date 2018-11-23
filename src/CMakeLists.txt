add_library(program STATIC program.cpp ${PROJECT_SOURCE_DIR}/include/program.h)
target_compile_features(program PRIVATE cxx_std_14)

add_library(tower STATIC tower.cpp ${PROJECT_SOURCE_DIR}/include/tower.h)
target_compile_features(tower PRIVATE cxx_std_14)
target_link_libraries(tower PRIVATE program)

add_executable(day7 main.cpp)
target_compile_features(day7 PRIVATE cxx_std_14)
target_link_libraries(day7 PUBLIC program)
