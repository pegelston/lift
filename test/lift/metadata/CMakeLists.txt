
set (HEADER_FILES function_traits_test.h
                  static_for_test.h)

set (SOURCE_FILES function_traits_test.cpp
                  static_for_test.cpp)

include_directories("${PROJECT_SOURCE_DIR}/artifacts/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(test_metadata ${HEADER_FILES}
                             ${SOURCE_FILES})

target_link_libraries(test_metadata ${CMAKE_SOURCE_DIR}/artifacts/lib/gtest.lib
                                    ${CMAKE_SOURCE_DIR}/artifacts/lib/gtest_main.lib)                             
                             
add_test(TestMetadata test_metadata)