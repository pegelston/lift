
set (HEADER_FILES function_traits_test.h
                  static_for_test.h)

set (SOURCE_FILES function_traits_test.cpp
                  static_for_test.cpp)

include_directories("${PROJECT_SOURCE_DIR}/gtest/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(test_metadata ${HEADER_FILES}
                             ${SOURCE_FILES})
                             
add_test(TestMetadata test_metadata)