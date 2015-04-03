#Functions and Implementations

1. In include/draw.h, DrawLine(PointT2d p1, PointT2d p2,Type**,Type i1,Type i2) : Paint a straight segment between point1 and point2. And interpolate values on the line. Point p1 has type i1 while p2 has type i2.

2. In include/draw.h, Polygon is a class that maintains data structure of simple polygon. The Draw(Type**) method can paint it using up-down interpolation.

3. include/bmpio.h provides I/O operations with bmp files.

4. include/basic_geometry.h provides basic support for geometry. PointT is a class of 3d point, of which coordinate are double. PointT2d is a class of 2d point, of which coordinate are integers. Both of them support basic arithmetic operations.

#Other processes

In main.cpp, I use Gauss() to implement anti-aliasing.

#Samples

See in result/.
