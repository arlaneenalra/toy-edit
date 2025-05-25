
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/include/version.h.in"
        "${CMAKE_BINARY_DIR}/include/version.h"
        @ONLY
)
add_executable(toy-edit
        main.cpp)

target_include_directories(toy-edit
        PUBLIC ${CMAKE_BINARY_DIR}/include
        PUBLIC ${PROJECT_SOURCE_DIR}/src/include
)
