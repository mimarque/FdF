
# FdF

##### (Version: 2)

  

## 1. Summary

This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

  

Version: 2

#wireframe #projection #fdf #fdf42

  

<br/>

  

## 2. Resources


### Understanding MinilibX:


[man](https://github.com/qst0/ft_libgfx/blob/master/man_mlx.md)

[Guide and links](https://github.com/qst0/ft_libgfx)

[Documentation](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html)

[A bit more indepth](https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx)

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

  
  
  
  
  
  

Step by step:

[(Korean) Velog Link](https://velog.io/@24siefil/FdF-Graphics)

  
  

Rotation Matrix I used:

```

┏                                                                                        ┓
┃  cos(a)cos(b)   cos(a)sin(b)sin(g)-sin(a)cos(g)   cos(a)sin(b)cos(g)+sin(a)sin(g)   0  ┃
┃                                                                                        ┃
┃  sin(a)cos(b)   sin(a)sin(b)sin(g)+cos(a)cos(g)   sin(a)sin(b)cos(g)-cos(a)sin(g)   0  ┃
┃                                                                                        ┃
┃    -sin(b)               cos(b)sin(g)                       cos(b)cos(g)            0  ┃
┃                                                                                        ┃
┃       0                        0                                  0                 1  ┃
┗                                                                                        ┛

```

Where `a` is rotation on `z`, `b` is rotation on `y`, `g` is rotation on `x`

  

For Isometric projection angles see: https://en.wikipedia.org/wiki/Isometric_projection#Overview

  

<br/>
