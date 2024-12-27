# Segment and Point Class Project

This project implements classes for `Point` and `Segment` to handle basic geometric operations such as moving, rotating, and calculating properties of points and line segments in a 2D space.

## Classes Overview

### `Point`
The `Point` class represents a point in a 2D coordinate system with `x` and `y` coordinates. The class includes the following features:
- **Constructors**: Default constructor and copy constructor.
- **Setters and Getters**: Methods to set and get the `x` and `y` coordinates.
- **Movement**: Ability to move the point by a vector or another point.
- **Rotation**: Ability to rotate the point around the origin (0, 0) by a given angle in radians.

### `Segment`
The `Segment` class represents a line segment defined by two `Point` objects. The class includes the following features:
- **Constructors**: Default constructor, copy constructor, and constructor using two `Point` objects.
- **Setters and Getters**: Methods to set and get the endpoints of the segment.
- **Movement**: Ability to move the entire segment by a vector or another point.
- **Rotation**: Ability to rotate the segment by a given angle (in degrees) around its center.
- **Operator Overloading**: Overloaded `<<` and `>>` operators for easy input and output of `Point` and `Segment` objects.

## Usage

1. The program initializes a segment with two points.
2. The user can input the coordinates for the segment's endpoints.
3. The user can rotate the segment by specifying an angle in degrees.
4. The segment can be displayed before and after rotation.