# Assignment 7
### Shaders.

Shaders are programs which run on the GPU, participating in the rendering of frames. This homework shows how to work with 2 kinds of shaders: Vertex Shaders and Fragment Shaders.\
Vertex Shaders are run once per vertex, and allow changing vertex properties (such as position and colour).\
Fragment Shaders are run at least once per pixel (more than once if multiple objects are overlapping or if multisampling is enabled); pixel properties, such as colour, can be finely tuned here. Properties set in the Vertex Shaders per-vertex are automatically assigned to fragments through interpolation.

The tasks for this homework are:
1. Read and understand the code.
2. Working preferably in the Vertex Shader, make the cubes move in a circular (circle or ellipse) trajectory on the screen. They are already bouncing up and down.
3. Working preferably in the Fragment Shader, make the colour of each pixel change depending on the x, y or/and z coordinates of that pixel, and time. You may work on a single colour channel, for clarity.

See the animation below for a possible output.

[![cubes.gif](https://i.postimg.cc/nrB3fGc5/cubes.gif)](https://postimg.cc/q6Bs8nKX)
