add_subdirectory(pybind11)
pybind11_add_module(pylibredwgcpp pylib.cpp)
target_link_libraries(pylibredwgcpp PRIVATE libredwg_cpp)


include(GNUInstallDirs)

install(TARGETS pylibredwgcpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
