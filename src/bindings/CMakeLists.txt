pybind11_add_module(pylibredwgcpp pylib.cpp)
target_link_libraries(pylibredwgcpp PRIVATE libredwg_cpp)

find_program(PYBIND11_STUBGEN_EXEC pybind11-stubgen)

set(PYTHON_INTERFACE_FILES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../python")

if(PYBIND11_STUBGEN_EXEC)
    add_custom_command(
        TARGET pylibredwgcpp
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E env
        PYTHONPATH=$<TARGET_FILE_DIR:pylibredwgcpp>
        ${PYBIND11_STUBGEN_EXEC} pylibredwgcpp --output-dir ${PYTHON_INTERFACE_FILES_DIR}
        WORKING_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        COMMENT "Generating .pyi stub with pybind11-stubgen into source directory"
    )
else()
  message(WARNING "pybind11-stubgen not found, using pre-generated stub from source directory.")
endif()

# =============================================================================
# Installation

if(BUILD_PYPROJECT)
    set_target_properties(pylibredwgcpp PROPERTIES INSTALL_RPATH "$ORIGIN/../lib/")

    install(TARGETS pylibredwgcpp DESTINATION pylibredwgcpp)
    install(FILES "${PYTHON_INTERFACE_FILES_DIR}/pylibredwgcpp.pyi" DESTINATION ${CMAKE_INSTALL_PREFIX}/pylibredwgcpp)
    install(FILES "${PYTHON_INTERFACE_FILES_DIR}/__init__.py" DESTINATION ${CMAKE_INSTALL_PREFIX}/pylibredwgcpp)
else()
    include(GNUInstallDirs)
    set(BINDINGS_INSTALL_PATH "${CMAKE_INSTALL_LIBDIR}/python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}/dist-packages")

    set_target_properties(pylibredwgcpp PROPERTIES INSTALL_RPATH "$ORIGIN/../../")

    install(TARGETS pylibredwgcpp EXPORT pylibredwgcpp_export
        COMPONENT libredwg_cpp
        LIBRARY DESTINATION ${BINDINGS_INSTALL_PATH}
    )

    install(FILES "${PYTHON_INTERFACE_FILES_DIR}/pylibredwgcpp.pyi"
        COMPONENT libredwg_cpp
        DESTINATION ${BINDINGS_INSTALL_PATH}
    )
endif()
