
set (HEADER_FILES application_test.h)

set (SOURCE_FILES application_test.cpp)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(test_framework ${HEADER_FILES}
                              ${SOURCE_FILES})