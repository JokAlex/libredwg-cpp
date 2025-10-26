set(SOURCES
    ./document.cpp
)

set(LIBREDWG_LIBONLY ON)
add_subdirectory(libredwg)

add_library(libredwg_cpp ${SOURCES})
target_link_libraries(libredwg_cpp PUBLIC redwg)

set_target_properties(libredwg_cpp PROPERTIES INSTALL_RPATH "$ORIGIN")

include(GenerateExportHeader)
set(export_file_name "libredwg_cpp_export_shared.hpp")
generate_export_header(libredwg_cpp EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/include/${export_file_name}")

set(LIBREDWG_CPP_PUBLIC_HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

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

install(TARGETS libredwg_cpp EXPORT mylib_export
    RUNTIME COMPONENT libredwg_cpp
    LIBRARY COMPONENT libredwg_cpp NAMELINK_COMPONENT libredwg_cpp-dev
    ARCHIVE COMPONENT libredwg_cpp-dev
    PUBLIC_HEADER COMPONENT libredwg_cpp-dev
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
