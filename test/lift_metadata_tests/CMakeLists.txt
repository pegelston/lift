set (HEADER_FILES function_traits_tests.h)
set (SOURCE_FILES function_traits_tests.cpp)

include_directories("${PROJECT_SOURCE_DIR}/include/lift_metadata")

add_executable(lift_metadata_test ${HEADER_FILES}
                                  ${SOURCE_FILES})