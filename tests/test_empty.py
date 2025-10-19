import pylibredwgcpp


def test_empty():
    document = pylibredwgcpp.Document.open("./data/empty.dwg")
    document.write_dxf("./out_data/empty.dxf", pylibredwgcpp.SaveOptions())
    