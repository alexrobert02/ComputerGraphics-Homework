# Assignment 2
### Using OpenGL library for drawing planar curves.

1. In this example, the OpenGL begin/end paradigm (GL_LINE_STRIP) was used for drawing polygonal lines corresponding to:
   1. the graph of the function: $|\sin x|\cdot e^{-\sin x}, x\in[0, 8\pi]$
   2. the graph of the Conchoid of Nicomedes:\
   $x=a\pm b\cos t, y=a\tan t\pm b\sin t, t\in(-\frac{\pi}{2}, \frac{\pi}{2})$.

2. As for assignment 1, add in the example program lines of code in order to draw the following graphs:
   1. The graph of the function $f(x) = \left\{ \begin{array}{rcl}1 & , & x=0 \\\frac{d(x)}{x} & , & 0\lt x\leq 100 \end{array} \right.$**,**\
      where $d(x)$ is the distance from $x$ to the nearest integer.
   2. The following curves are given by parametric equations (for each example, the values of various parameters, called $a$, $b$, etc., can be found inside the images):
      1. The trisectrix of Longchamps:\
         $\begin{array}{} x=\frac{a}{4\cos^{2}t-3}, & y=\frac{a\tan t}{4\cos^{2} t-3}, & t\in\left(-\frac{\pi}{2}, \frac{\pi}{2}\right) \setminus \left\{ \pm\frac{\pi}{6} \right\}  \end{array}$.\
         Hint: First, draw the graph of the trisectrix of Longchamps (please note that the image is not the graph!). Use no scaling, use GL_POINTS and vary the ratio of arithmetic progression. Then overlap your window on the image requested and notice some patterns, the geometric objects etc. If your image has some/many pixels in the middle it is still considered correct.
      2. The cycloid:\
         $\begin{array}{} x=a\cdot t-b\sin t, & y=a-b\cos t, & t\in \mathbb{R} \end{array}$.


3. Some curves are specified by polar equations: the polar coordinates are, where $t\in [a,b]$ and $r=f(t)$. The polar coordinates $(r,t)$ are transformed in cartesian coordinates as following $x=r\cos t$ and $y=r\sin t$.\
   Add in the example program lines of code in order to draw the following curves specified by polar equations:
   1. The lemniscate of Bernoulli: $\begin{array}{} r=\pm a\cdot \sqrt{2\cos 2t}, & t\in(-\frac{\pi}{4}, \frac{\pi}{4}) \end{array},$
   2. The logarithmic spiral: $ \begin{array}{} r=a\cdot e^{1+t}, & t\in(0, \infty) \end{array}.$

[![image017.gif](https://i.postimg.cc/PrV8Kv30/image017.gif)](https://postimg.cc/Whr31zP7)
[![image018.jpg](https://i.postimg.cc/y8J3G62x/image018.jpg)](https://postimg.cc/DSTzJhv3)
[![image019.gif](https://i.postimg.cc/GhmykxQk/image019.gif)](https://postimg.cc/nMNrx7Nz)
[![image020.gif](https://i.postimg.cc/kMcS6pxJ/image020.gif)](https://postimg.cc/mhPkKVXJ)
[![image021.gif](https://i.postimg.cc/gjNLCxYX/image021.gif)](https://postimg.cc/Lggsf6g2)
