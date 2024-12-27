# ComplexTest

## Project Overview

This project is a C++ console application that defines a `Complex` class to represent complex numbers in the form `(re, im)`, where `re` is the real part and `im` is the imaginary part, both of type `double`. The class includes various methods and operators to perform arithmetic operations on complex numbers, as well as functions to calculate and manipulate the components of complex numbers.

## Features

The `Complex` class includes the following features:

### Constructors:
- **Default constructor** with parameters `(Re = 0, Im = 0)`.
- **Copy constructor**.

### Setters:
- `SetRe(double re)` – Sets the real part of the complex number.
- `SetIm(double im)` – Sets the imaginary part of the complex number.
- `SetComplex(double re, double im)` – Sets both the real and imaginary parts at once.

### Getters:
- `GetRe()` – Returns the real part of the complex number.
- `GetIm()` – Returns the imaginary part of the complex number.

### Arithmetic Operators:
- Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`) operators are defined to operate on complex numbers in the form `(a1, b1) ± (a2, b2)`.
- Compound assignment operators: `+=`, `-=` , `*=` , `/=`.

### Type Conversion:
- Cast operator to convert a complex number to a `double`.

### Mathematical Functions:
- `Modulo()` – Returns the modulus (magnitude) of the complex number, calculated as `sqrt(re^2 + im^2)`.

### Input and Output:
- Overloaded input operator (`>>`) to read two numbers separated by whitespace.
- Overloaded output operator (`<<`) to print the complex number in the form `(re, im)`.

## Example Usage

In this program, we define a complex number `(4, 3)` and read another complex number from the user input. The program calculates and displays the sum, difference, product, and quotient of the two complex numbers, as well as the modulus of the resulting numbers.
