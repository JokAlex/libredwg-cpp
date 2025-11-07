"""
Python bindings for libredwg-cpp
"""

from __future__ import annotations
import typing

__all__: list[str] = [
    "Document",
    "Error",
    "IOError",
    "InternalError",
    "ParseError",
    "UnsupportedError",
    "ValidationError",
    "Version",
]

class Document:
    @staticmethod
    def open(path_to_dwg: str) -> Document: ...
    def version(self) -> Version: ...
    def write_dxf(self, path_to_dxf: str) -> None: ...

class Error(Exception):
    pass

class IOError(Error):
    pass

class InternalError(Error):
    pass

class ParseError(Error):
    pass

class UnsupportedError(Error):
    pass

class ValidationError(Error):
    pass

class Version:
    """
    Members:

      Invalid

      R_1_1

      R_1_2

      R_1_3

      R_1_4

      R_2_0

      R_2_10

      R_2_21

      R_2_22

      R_2_4

      R_2_5

      R_2_6

      R_9

      R_10

      R_11

      R_12

      R_13

      R_14

      R_2000

      R_2002

      R_2004

      R_2007

      R_2010

      R_2013

      R_2018

      R_AFTER
    """

    Invalid: typing.ClassVar[Version]  # value = <Version.Invalid: 0>
    R_10: typing.ClassVar[Version]  # value = <Version.R_10: 15>
    R_11: typing.ClassVar[Version]  # value = <Version.R_11: 18>
    R_12: typing.ClassVar[Version]  # value = <Version.R_11: 18>
    R_13: typing.ClassVar[Version]  # value = <Version.R_13: 21>
    R_14: typing.ClassVar[Version]  # value = <Version.R_14: 23>
    R_1_1: typing.ClassVar[Version]  # value = <Version.R_1_1: 1>
    R_1_2: typing.ClassVar[Version]  # value = <Version.R_1_2: 2>
    R_1_3: typing.ClassVar[Version]  # value = <Version.R_1_3: 3>
    R_1_4: typing.ClassVar[Version]  # value = <Version.R_1_4: 4>
    R_2000: typing.ClassVar[Version]  # value = <Version.R_2000: 25>
    R_2002: typing.ClassVar[Version]  # value = <Version.R_2002: 27>
    R_2004: typing.ClassVar[Version]  # value = <Version.R_2004: 31>
    R_2007: typing.ClassVar[Version]  # value = <Version.R_2007: 34>
    R_2010: typing.ClassVar[Version]  # value = <Version.R_2010: 36>
    R_2013: typing.ClassVar[Version]  # value = <Version.R_2013: 38>
    R_2018: typing.ClassVar[Version]  # value = <Version.R_2018: 40>
    R_2_0: typing.ClassVar[Version]  # value = <Version.R_2_0: 6>
    R_2_10: typing.ClassVar[Version]  # value = <Version.R_2_10: 7>
    R_2_21: typing.ClassVar[Version]  # value = <Version.R_2_21: 8>
    R_2_22: typing.ClassVar[Version]  # value = <Version.R_2_22: 9>
    R_2_4: typing.ClassVar[Version]  # value = <Version.R_2_4: 10>
    R_2_5: typing.ClassVar[Version]  # value = <Version.R_2_5: 11>
    R_2_6: typing.ClassVar[Version]  # value = <Version.R_2_6: 12>
    R_9: typing.ClassVar[Version]  # value = <Version.R_9: 13>
    R_AFTER: typing.ClassVar[Version]  # value = <Version.R_AFTER: 42>
    __members__: typing.ClassVar[
        dict[str, Version]
    ]  # value = {'Invalid': <Version.Invalid: 0>, 'R_1_1': <Version.R_1_1: 1>, 'R_1_2': <Version.R_1_2: 2>, 'R_1_3': <Version.R_1_3: 3>, 'R_1_4': <Version.R_1_4: 4>, 'R_2_0': <Version.R_2_0: 6>, 'R_2_10': <Version.R_2_10: 7>, 'R_2_21': <Version.R_2_21: 8>, 'R_2_22': <Version.R_2_22: 9>, 'R_2_4': <Version.R_2_4: 10>, 'R_2_5': <Version.R_2_5: 11>, 'R_2_6': <Version.R_2_6: 12>, 'R_9': <Version.R_9: 13>, 'R_10': <Version.R_10: 15>, 'R_11': <Version.R_11: 18>, 'R_12': <Version.R_11: 18>, 'R_13': <Version.R_13: 21>, 'R_14': <Version.R_14: 23>, 'R_2000': <Version.R_2000: 25>, 'R_2002': <Version.R_2002: 27>, 'R_2004': <Version.R_2004: 31>, 'R_2007': <Version.R_2007: 34>, 'R_2010': <Version.R_2010: 36>, 'R_2013': <Version.R_2013: 38>, 'R_2018': <Version.R_2018: 40>, 'R_AFTER': <Version.R_AFTER: 42>}
    def __eq__(self, other: typing.Any) -> bool: ...
    def __getstate__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __index__(self) -> int: ...
    def __init__(self, value: typing.SupportsInt) -> None: ...
    def __int__(self) -> int: ...
    def __ne__(self, other: typing.Any) -> bool: ...
    def __repr__(self) -> str: ...
    def __setstate__(self, state: typing.SupportsInt) -> None: ...
    def __str__(self) -> str: ...
    @property
    def name(self) -> str: ...
    @property
    def value(self) -> int: ...
