# Assignment 4
### Drawing 2D graphical primitives in raster graphics.

1. Design and implement a class CartesianGrid that draws a square 2D Cartesian grid having the following features:
   1. The number of rows/columns are parameters of the grid,
   2. Pixels, having a circular shape (or other shapes - e.g.,
squared - but the circular ones will be graded to the fullest), should be painted at the grid vertices (a grid vertex is the intersection between a row and a column),
   3. Pixels should not intersect,
   4. An (i,j) pixel should be displayed by calling a method writePixel
having at least 2 integer arguments: the column i and the row j.


2. Implement one of the course algorithms for displaying a line segment whose endpoints have integer coordinates (see the image).\
Those solutions that implement the algorithm *ScanConvertSegments3* (by providing suitable changes to it, so the computation of the pixel coordinates does not use the pixel coordinates computed by the algorithm of the course) will be graded to the fullest.


3. At course hours, it was presented an algorithm for drawing a circle having the center at the origin and the radius having an integer value. That algorithm first generates the pixels in the second octant and then, by using the symmetries with respect to O, Ox, Oy, and the bisectrix, all the pixels of the circle. Modify the algorithm such that it generates only the pixels in the first octant and then use a technique for drawing thick primitives in order to obtain the image. Those solutions that implement the algorithm *ScanConvertCircle4* (by providing suitable changes to it and explaining these changes) will be graded to the fullest.

[![image001.gif](https://i.postimg.cc/QdGDvPkQ/image001.gif)](https://postimg.cc/jLXB7M12)
[![image002.gif](https://i.postimg.cc/5NF171v9/image002.gif)](https://postimg.cc/gndfjCN1)
