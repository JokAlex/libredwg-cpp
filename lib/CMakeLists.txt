set(SOURCES
    ./document.cpp
)

add_library(libredwg_cpp ${SOURCES})
target_include_directories(libredwg_cpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

include(GenerateExportHeader)
set(export_file_name "libredwg_cpp_export_shared.hpp")

generate_export_header(libredwg_cpp EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/include/${export_file_name}")


include(GNUInstallDirs)

install(TARGETS libredwg_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)