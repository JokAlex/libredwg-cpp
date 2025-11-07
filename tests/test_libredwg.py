import pylibredwgcpp


LIBREDWG_DATADIR = "../src/external/libredwg/test/test-data/"


def test_example_2000():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2000.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2000
    document.write_dxf("./out_data/example_2000.dxf")


def test_example_2004():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2004.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2004
    document.write_dxf("./out_data/example_2004.dxf")


def test_example_2007():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2007.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2007
    document.write_dxf("./out_data/example_2007.dxf")


def test_example_2010():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2010.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2010
    document.write_dxf("./out_data/example_2010.dxf")


def test_example_2013():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2013.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2013
    document.write_dxf("./out_data/example_2013.dxf")


def test_example_2018():
    document = pylibredwgcpp.Document.open(LIBREDWG_DATADIR + "example_2018.dwg")
    assert document.version() == pylibredwgcpp.Version.R_2018
    document.write_dxf("./out_data/example_2018.dxf")
