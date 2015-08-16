set (METADATA_HEADER_FILES function_traits.h
                           static_for.h)

add_custom_target (lift_metadata 
                   SOURCES ${METADATA_HEADER_FILES})