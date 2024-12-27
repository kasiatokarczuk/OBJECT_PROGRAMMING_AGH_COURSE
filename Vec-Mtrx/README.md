# Matrix and Vector Operations Project

This project implements a **Matrix** and **Vector** class in C++, providing functionalities for basic linear algebra operations such as addition, subtraction, scalar multiplication, dot product, and matrix-vector or matrix-matrix multiplication. The project also includes operator overloading for ease of use.

## Overview

The project consists of the following files:

- **Matrix.h**: Header file for the Matrix class.
- **Matrix.cpp**: Implementation of the Matrix class.
- **Vector.h**: Header file for the Vector class.
- **Vector.cpp**: Implementation of the Vector class.
- **Vec-Mtrx.cpp**: Main program file demonstrating the usage of the Matrix and Vector classes.

## Features

### Vector Class

The **Vector** class provides the following functionalities:

#### Construction and Destruction

- Default and parameterized constructors.
- Copy constructor.
- Destructor to free allocated memory.

#### Operators

- Addition (`+`, `+=`) with another vector or a scalar.
- Subtraction (`-`, `-=`) with another vector or a scalar.
- Unary minus (`-`).
- Multiplication (`*`, `*=`) with a scalar.
- Scalar product (`*`) between two vectors.
- Equality and inequality comparison (`==`, `!=`).
- Indexing (`[]`).
- Casting to a `double*` pointer.

#### Input/Output

- Stream input (`>>`) and output (`<<`).

### Matrix Class

The **Matrix** class provides the following functionalities:

#### Construction and Destruction

- Default and parameterized constructors.
- Copy constructor.
- Destructor to free allocated memory.

#### Operators

- Assignment (`=`).
- Multiplication (`*`) with another matrix or a vector.
- Equality and inequality comparison (`==`, `!=`).
- Indexing (`[]`).
- Casting to a `Vector*` pointer.