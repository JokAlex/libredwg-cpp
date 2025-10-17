set(SOURCES
    ./document.cpp
)

set(LIBREDWG_LIBONLY ON)
add_subdirectory(libredwg)

add_library(libredwg_cpp ${SOURCES})
target_link_libraries(libredwg_cpp PRIVATE redwg)

include(GenerateExportHeader)
set(export_file_name "libredwg_cpp_export_shared.hpp")
generate_export_header(libredwg_cpp EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/include/${export_file_name}")

SET(LIBREDWG_CPP_PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(libredwg_cpp
    PUBLIC
        $<BUILD_INTERFACE:${LIBREDWG_CPP_PUBLIC_HEADERS_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libredwg/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/libredwg/src>
)


include(GNUInstallDirs)

install(TARGETS libredwg_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${LIBREDWG_CPP_PUBLIC_HEADERS_DIR}/libredwg_cpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
