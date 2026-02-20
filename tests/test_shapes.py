import libredwg_cpp


LIBREDWG_DATADIR = "../src/external/libredwg/test/test-data/2000/"


def test_arc():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Arc.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/arc.dxf")


def test_ellipse():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Ellipse.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/ellipse.dxf")


def test_construction_line():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "ConstructionLine.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/construction_line.dxf")


def test_point():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Point.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/point.dxf")


def test_line():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Line.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/line.dxf")


def test_multiline():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Multiline.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/multiline.dxf")


def test_polyline():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Polyline.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/polyline.dxf")


def test_polygon():
    document = libredwg_cpp.Document.open(LIBREDWG_DATADIR + "Polygon.dwg")
    assert document.version() == libredwg_cpp.Version.R_2000
    document.write_dxf("./out_data/polygon.dxf")
