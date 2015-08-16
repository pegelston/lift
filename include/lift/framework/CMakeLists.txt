set (FRAMEWORK_HEADER_FILES application.h
                            call.h
                            factory.h
                            object_repository.h)
                  
add_custom_target (lift_framework 
                   SOURCES ${FRAMEWORK_HEADER_FILES})