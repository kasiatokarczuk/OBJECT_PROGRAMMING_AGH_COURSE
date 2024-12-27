# DLL Library Project

## Project Overview

This project demonstrates the creation and usage of a Dynamic-Link Library (DLL) in C++ with a Windows Console Application. The project consists of two main components:

1. **testDll**: A DLL containing exported classes such as `Date`, `Time`, and `DateTime`, along with relevant methods. These classes are designed to manage date and time-related information.
2. **test**: A console application that utilizes the `testDll` library to demonstrate how to work with the exported classes and methods.

## Key Features

- **Dynamic-Link Library (DLL)**: The `testDll` project exposes several classes that can be used in other applications. The classes include:
  - `Date`: Represents a specific date with private members for day, month, and year.
  - `Time`: Represents time with private members for hours, minutes, and seconds.
  - `DateTime`: Combines the functionality of `Date` and `Time` into a unified class.

- **Exported Classes and Methods**: Classes and methods are exported from the DLL using `__declspec(dllexport)` and imported in the console application using `__declspec(dllimport)`.

- **Console Application**: The `test` project demonstrates how to use the `testDll` library by creating instances of the `Date`, `Time`, and `DateTime` classes and printing their values.

- **Post-Build Events**: The project includes post-build events to copy the necessary DLL and header files to the appropriate directories, ensuring proper linking between the console application and the DLL.



