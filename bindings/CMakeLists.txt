add_library(pylibredwgcpp pylib.cpp)
target_link_libraries(pylibredwgcpp PRIVATE libredwg_cpp_lib)


include(GNUInstallDirs)

install(TARGETS pylibredwgcpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)