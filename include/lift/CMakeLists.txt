set (FRAMEWORK_HEADER_FILES application.h
                            call.h
                            factory.h
                            function_traits.h
                            index_tuple.h
                            object.h
                            object_repository.h
                            parameter_expander.h
                            static_for.h)
                  
add_custom_target (lift_framework 
                   SOURCES ${FRAMEWORK_HEADER_FILES})