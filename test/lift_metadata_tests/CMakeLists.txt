
set (HEADER_FILES function_traits_tests.h
                  static_for_tests.h)
set (SOURCE_FILES function_traits_tests.cpp
                  static_for_tests.cpp)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(lift_metadata_test ${HEADER_FILES}
                                  ${SOURCE_FILES})