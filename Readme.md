
# FdF

##### (Version: 2)

  

## 1. Summary

This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

  

Version: 2

###### #wireframe #projection #fdf #fdf42 #conic #conic_projection #world_bending #42 #School42

  

<br/>

  
## 2. Preview

![conical projection](https://imgur.com/xG2HHhZ.png)

![isometric projection](https://imgur.com/8MzbZmb.png)

![with the menu](https://imgur.com/nCxHupl.png)


## 3. Resources


### Understanding MinilibX:


[man](https://github.com/qst0/ft_libgfx/blob/master/man_mlx.md)

[Guide and links](https://github.com/qst0/ft_libgfx)

[Documentation](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html)

[A bit more indepth](https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx)

[Small guide](https://github.com/VBrazhnik/FdF/wiki)

---

### Keyboard key codes:

Linux: [X11](https://code.woboq.org/qt5/include/X11/keysymdef.h.html)

MacOS: [Cocoa/Carbon](https://github.com/phracker/MacOSX-SDKs/blob/master/MacOSX10.6.sdk/System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers/Events.h)

  

<br>

  

---

### Drawing a line:

[Bresenham’s algorithm](https://web.archive.org/web/20180127114507/http://graphics.idav.ucdavis.edu/education/GraphicsNotes/Bresenhams-Algorithm.pdf)

[Generalised algorithm](https://web.archive.org/web/20040929015146/https://www.cs.umd.edu/class/fall2003/cmsc427/bresenham.html)

---

### Colours:

***DO NOT AVERAGE COLOURS:***

"[Computer Color is broken](https://www.youtube.com/watch?v=LKnqECcg6Gw)"

To understand more see this [thread](https://graphicdesign.stackexchange.com/questions/113884/calculating-average-of-two-rgb-values) and [this one](https://stackoverflow.com/questions/22607043/color-gradient-algorithm).

---

### Computer Graphics

Understanding matrix multiplication:

[matrixmultiplication](http://matrixmultiplication.xyz/)

Understanding Computer Graphics and Coordinates:

[Scratchapixel](https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/math-operations-on-points-and-vectors)

[Matrix Projection](https://jsantell.com/3d-projection/)

[More matrix Projection](https://www.songho.ca/opengl/gl_projectionmatrix.html)

[Killer matrix Projection examples](https://www.mathematik.uni-marburg.de/~thormae/lectures/graphics1/graphics_6_2_eng_web.html)
  
[orthogonal projection matrix plainly explained](https://blog.demofox.org/2017/03/31/orthogonal-projection-matrix-plainly-explained/) 
  
  
  

Step by step (without matrices):

[(Korean) Velog Link](https://velog.io/@24siefil/FdF-Graphics)


<br/>

### More Resources:


[42Guide](https://tangible-harbor-c59.notion.site/FT_Cursus-98f688bd250a4601b6e55ac699d17cb0)

## 4. Explanation:

I decided to use matrices to put things on the screen because I knew I would have better support,
more resources and that the bonus would use them.

Note that there are 2 types of matrix storage:

```
Row Major Matrix              Column Major Matrix

[_00, _01, _02, _03]          [_00, _10, _20, _30]
[_10, _11, _12, _13]          [_01, _11, _21, _31]
[_20, _21, _22, _23]          [_02, _12, _22, _32]
[_30, _31, _32, _33]          [_03, _13, _23, _33]
```

I use Row Major on my program.

World transform Matrix I used:

```

┏                                                                                             ┓
┃  cos(a)cos(b)      cos(a)sin(b)sin(g)-sin(a)cos(g)    cos(a)sin(b)cos(g)+sin(a)sin(g)    0  ┃
┃                                                                                             ┃
┃  sin(a)(-cos(b))   -sin(a)sin(b)sin(g)-cos(a)cos(g)   cos(a)sin(g)-sin(a)sinb(b)cos(g)   0  ┃
┃                                                                                             ┃
┃    - S sin(b)               S cos(b)sin(g)                    S cos(b)cos(g)             0  ┃
┃                                                                                             ┃
┃         0                          0                                  0                  1  ┃
┗                                                                                             ┛

```

Where `a` is rotation on `z`, `b` is rotation on `y`, `g` is rotation on `x` 

and `S` is the scaling of `z`.

It comes from multiplying z scaling matrix with R(z) R(y) R(x) rotation matrices:

[Matrix multiplication](https://www.wolframalpha.com/input?i2d=true&i=%7B%7B1%2C0%2C0%2C0%7D%2C%7B0%2C-1%2C0%2C0%7D%2C%7B0%2C0%2Cs%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D%7B%7Bcos%5C%2840%29a%5C%2841%29%2C-sin%5C%2840%29a%5C%2841%29%2C0%2C0%7D%2C%7Bsin%5C%2840%29a%5C%2841%29%2Ccos%5C%2840%29a%5C%2841%29%2C0%2C0%7D%2C%7B0%2C0%2C1%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D%7B%7Bcos%5C%2840%29b%5C%2841%29%2C0%2Csin%5C%2840%29b%5C%2841%29%2C0%7D%2C%7B0%2C1%2C0%2C0%7D%2C%7B-sin%5C%2840%29b%5C%2841%29%2C0%2Ccos%5C%2840%29b%5C%2841%29%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D%7B%7B1%2C0%2C0%2C0%7D%2C%7B0%2Ccos%5C%2840%29g%5C%2841%29%2C-sin%5C%2840%29g%5C%2841%29%2C0%7D%2C%7B0%2Csin%5C%2840%29g%5C%2841%29%2Ccos%5C%2840%29g%5C%2841%29%2C0%7D%2C%7B0%2C0%2C0%2C1%7D%7D)
  
Note that I inverted y on the first matrix. You might not need to do that. Changing that value yields a completely different matrix.

For Isometric projection angles see: https://en.wikipedia.org/wiki/Isometric_projection#Overview

### Conic projection
---

That is the biggest throw off of the entire pdf assignment. 

You can't imagine how long I spent looking. There is no conic projection. I mean, there is, but... it only applies to spheres being projected onto a plane.

This is a diagram of the available projections:




![list of Graphical projections](https://imgur.com/dUiuB4O.png)


So when you do an isometric projection by matrices you are automatically doing the bonus parallel projection


To achieve what I like to call "world bending" or this: 


![world bending](https://imgur.com/kyEFF8X.png)


You first should read the links on resources to understand better what is happening. However my implementation didn't use matrices like [this example](https://stackoverflow.com/questions/51596272/warp-curve-all-vertices-around-a-pivot-point-axis-three-js-glsl) does. I just transformed the `z` coordinates.


```
x = abs((int)inputpoint.x);

//range should be between 0.015 and 0.005
vv = (x * x) * (range);
outpt.x = inputpoint.x;
outpt.y = inputpoint.y;
outpt.z = inputpoint.z + vv;
```

