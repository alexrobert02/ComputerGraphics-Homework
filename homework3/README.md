# Assignment 3
### Fractals.

The term ***fractal*** has been generalized to include objects outside of Mandelbrot's original definition.\
By ***fractal object*** we will understand any object that has the property of self-similarity.\
The objects obtained in the following are approximations of an ideal fractal object, being obtained in a finite number of iterations.\
Below, 1 and 3 are examples, 2 and 4 are problems to be solved.

1. The ***Julia-Fatou set*** is obtained by using an iterative process.
Starting from $z\in \mathbb{C}$, we obtain the complex numbers $(z_{n})_{n\geq 0}$ as following: $z_{n+1}=z^{2}_{n}+c$, where $c\in \mathbb{C}$.\
A complex number $x\in \mathbb{C}$ belongs to the Julia-Fatou set $J_{c}$ if, starting with $z_{0}=x$, the following conditions are **not**
fulfilled: $(\exist z\in \mathbb{C})(\displaystyle \lim_{n \to \infty} z_n=z)$ or $\displaystyle \lim_{n \to \infty} |z_n|=\infty$.\
The program **t3p1.cpp** generates 2 approximations of the Julia-Fatou set corresponding to the values c1 and c2 for $c\in \mathbb{C}$; values indicated in the images below.\
The 2 conditions from above were used in the program as $(\exist n_0\gt 0)(z_{n_0}=z_{n_0+1})$ and $(\exist n_0\geq 0)(\exist M\gt 0)(|z_{n_0}|\gt M)$ i.e., in a finite number of iterations $n_0$, it is tested if the sequence $z_n$ becomes constant or $|z_n|$ exceeds $M$ (whose value is chosen big enough).\
If after the completion of $n_0$ iterations no condition becomes true then the respective point belongs to the Julia-Fatou set and it was painted red in the figure.


2. The ***Mandelbrot set*** is also obtained by using an iterative process.\
A number $c\in \mathbb{C}$ belongs to the Mandelbrot set $M$ if $\displaystyle \lim_{n \to \infty} |z_n|\neq \infty$, where the sequence $(z_n)_{n\geq 0}$ is obtained as following: $z_0=0+0i$ and $z_{n+1}=z^2_n+c, \forall n \geq 0$.

   1. It is requested to build the Mandelbrot set, using the contraposition $((P\implies Q)\iff(\neg Q\implies \neg P))$ of the following property of the Mandelbrot set: if the complex number $c$ belongs to the Mandelbrot set then $|z_n|\leq 2,\forall n\geq 0$. In conclusion, the iterative process stops if $|z_n|$ exceeds 2.

   2. It is requested to make a classification of the points not belonging to the Mandelbrot set, by painting them with different colors in function of the number of iterations that was necessary to detect their nonmembership.


3. The program **t3p3.cpp** generates recursively fractals built using the ***Turtle graphics***.
In Turtle graphics the images are obtained by moving a cursor on the screen; the cursor is moving according to some commands (relative to its position on the screen) move forward and draw, turn left or right with a certain angle):

   1. The Koch snowflake (or the Koch island),

   2. Binary trees,
   
   3. Fractal tree,
   
   4. The Hilbert curve.


4. It is requested to draw the following pictures (by using the Turtle graphics): 1, 2, 3.\
   Draw all the levels, not only the levels showed in the images.

[![image018.gif](https://i.postimg.cc/VNrFMrMW/image018.gif)](https://postimg.cc/nsx7fL3X)
[![image019.gif](https://i.postimg.cc/jjp4hx40/image019.gif)](https://postimg.cc/ns1mFtW0)\
[![image020.gif](https://i.postimg.cc/x1FRcykd/image020.gif)](https://postimg.cc/XrdFP5kM)\
[![image021.gif](https://i.postimg.cc/hPsMqqcT/image021.gif)](https://postimg.cc/8jFLh9Fz)\
[![image022.jpg](https://i.postimg.cc/VkNgfHkT/image022.jpg)](https://postimg.cc/4mrVwPtb)\
[![image023.jpg](https://i.postimg.cc/prYCTw8N/image023.jpg)](https://postimg.cc/QKC1Yn0S)\
[![image024.jpg](https://i.postimg.cc/G3kqqyfM/image024.jpg)](https://postimg.cc/K48PYRxL)\
[![image025.jpg](https://i.postimg.cc/Dyn5Dzk7/image025.jpg)](https://postimg.cc/z32nH8GQ)\
[![image026.gif](https://i.postimg.cc/C5VJwhRH/image026.gif)](https://postimg.cc/dk4GBKmL)
