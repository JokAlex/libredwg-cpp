set(DWG_LOGGING ${CMAKE_CURRENT_LIST_DIR}/../../external/libredwg/src/logging.h)
set(ORIGINAL_LOGGING ${CMAKE_BINARY_DIR}/reserv_dwg_logging.h)
set(CUSTOM_LOGGING ${CMAKE_CURRENT_LIST_DIR}/logging.h)

if(NOT EXISTS ${ORIGINAL_LOGGING})
    file(COPY_FILE ${DWG_LOGGING} ${ORIGINAL_LOGGING})
else()
    file(COPY_FILE ${ORIGINAL_LOGGING} ${DWG_LOGGING})
endif()

file(APPEND ${DWG_LOGGING} "\n#include <custom_logging.h>\n")

target_sources(redwg PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dwg_logging.c)

target_include_directories(redwg 
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}
)
