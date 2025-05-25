
add_subdirectory(libtester)

add_executable(toy-test-lib-tester
        testLibTester.cpp
)

target_link_libraries(toy-test-lib-tester
        libtester
)

add_test(TestLibTester ${CMAKE_CURRENT_BINARY_DIR}/toy-test-lib-tester)

# target_include_directories(toy-edit-tests
#         PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
#         PUBLIC ${PROJECT_BINARY_DIR}/src/include
#         PUBLIC ${PROJECT_SOURCE_DIR}/src/include
# )