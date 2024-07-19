# Assignment 6
### 3D Viewing.

1. The program **t6p1.cpp** realizes various 3D views.\
   The OpenGL functions *glOrtho* and *glFrustum* are used to specify parallel and perspective projections. Their parameters are: **l**, **r**, **b**, **t**, **n**, **f**.\
   The points (l, b, -n) and (r, t, -n) specify the points from the view plane (back clipping plane) that correspond to the lower left and upper right corners of the window.\
   The **f** parameter denotes the distance from the eye (the origin O) to the back clipping plane.
    1. In the program one can notice the use of display lists:
       1. The display lists are generated with the function *glGenLists*,
       2. The display lists are created with the functions *glNewList* and *glEndList*,
       3. The display lists are executed with the function *glCallList*.

       In the program **t6p1.cpp** we can view 3 types of 3D objects that are specified using display lists.

   2. The normalization transformation is performed by setting the current projection matrix with the function *glMatrixMode* and the parameter *GL_PROJECTION*.

   3. Notice the order of the transformations!


2. Using the program t6p1.cpp:
    1. Identify the orientation of faces of different colors (using the keyboard),
    2. Identify the projection types that have been used to create the images 1,2, and 3,
    3. Add lines of code to obtain these images.

[![image001.gif](https://i.postimg.cc/YScbXgCs/image001.gif)](https://postimg.cc/gxDVjxRV)
