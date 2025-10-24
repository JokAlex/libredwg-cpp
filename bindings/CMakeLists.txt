add_subdirectory(pybind11)
pybind11_add_module(pylibredwgcpp pylib.cpp)
target_link_libraries(pylibredwgcpp PRIVATE libredwg_cpp)

set_target_properties(pylibredwgcpp PROPERTIES INSTALL_RPATH "$ORIGIN/../../")

include(GNUInstallDirs)

install(TARGETS pylibredwgcpp EXPORT pylibredwgcpp_export
    COMPONENT libredwg_cpp
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}/dist-packages"
)
