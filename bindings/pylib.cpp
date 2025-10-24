#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <libredwg_cpp/document.hpp>
#include <libredwg_cpp/error.hpp>

PYBIND11_MODULE(pylibredwgcpp, m) {
  m.doc() = "Python bindings for libredwg-cpp";

  pybind11::class_<libredwg::Document>(m, "Document")
      .def_static("open", &libredwg::Document::open,
                  pybind11::arg("path_to_dwg"))
      .def("write_dxf", &libredwg::Document::writeDxf,
           pybind11::arg("path_to_dxf"))
      .def("version", &libredwg::Document::version);

  auto libredwgErrorHandle =
      pybind11::register_exception<libredwg::Error>(m, "Error");
  pybind11::register_exception<libredwg::IOError>(m, "IOError",
                                                  libredwgErrorHandle);
  pybind11::register_exception<libredwg::ParseError>(m, "ParseError",
                                                     libredwgErrorHandle);
  pybind11::register_exception<libredwg::UnsupportedError>(
      m, "UnsupportedError", libredwgErrorHandle);
  pybind11::register_exception<libredwg::ValidationError>(m, "ValidationError",
                                                          libredwgErrorHandle);
  pybind11::register_exception<libredwg::InternalError>(m, "InternalError",
                                                        libredwgErrorHandle);

  pybind11::enum_<libredwg::Version>(m, "Version")
      .value("Invalid", libredwg::Version::INVALID)
      .value("R_1_1", libredwg::Version::R_1_1)
      .value("R_1_2", libredwg::Version::R_1_2)
      .value("R_1_3", libredwg::Version::R_1_3)
      .value("R_1_4", libredwg::Version::R_1_4)
      .value("R_2_0", libredwg::Version::R_2_0)
      .value("R_2_10", libredwg::Version::R_2_10)
      .value("R_2_21", libredwg::Version::R_2_21)
      .value("R_2_22", libredwg::Version::R_2_22)
      .value("R_2_4", libredwg::Version::R_2_4)
      .value("R_2_5", libredwg::Version::R_2_5)
      .value("R_2_6", libredwg::Version::R_2_6)
      .value("R_9", libredwg::Version::R_9)
      .value("R_10", libredwg::Version::R_10)
      .value("R_11", libredwg::Version::R_11)
      .value("R_12", libredwg::Version::R_12)
      .value("R_13", libredwg::Version::R_13)
      .value("R_14", libredwg::Version::R_14)
      .value("R_2000", libredwg::Version::R_2000)
      .value("R_2002", libredwg::Version::R_2002)
      .value("R_2004", libredwg::Version::R_2004)
      .value("R_2007", libredwg::Version::R_2007)
      .value("R_2010", libredwg::Version::R_2010)
      .value("R_2013", libredwg::Version::R_2013)
      .value("R_2018", libredwg::Version::R_2018)
      .value("R_AFTER", libredwg::Version::R_AFTER)
      .export_values();
}
