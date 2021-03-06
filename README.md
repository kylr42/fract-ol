# fract-ol
Exploring the wonderful world of fractals with the 42 mlx library.

![fract-ol](/images/julia_set1.png)

## Overview
A fractal is a never-ending pattern. Fractals are infinitely complex patterns that are self-similar across different scales. They are created by repeating a simple process over and over in an ongoing feedback loop. Driven by recursion, fractals are images of dynamic systems – the pictures of Chaos. Geometrically, they exist in between our familiar dimensions. Fractal patterns are extremely familiar, since nature is full of fractals. For instance: trees, rivers, coastlines, mountains, clouds, seashells, hurricanes, etc. Abstract fractals – such as the Mandelbrot Set – can be generated by a computer calculating a simple equation over and over

## Features

* Differents availables fractals: Mandelbrot | Julia | Mandelbar
* Mannualy change parameters (See below)

## Installation

Run `make`. An executable will compile. Currently only tested on OS X.

## How to run program?

You can run the project with the following command:

```
./fractol [Julia / Mandelbrot / Mandelbar]
```


For example, you can specify Julia fractal:

```
./fractol Julia
```


![fract-ol](/images/julia_set2.png)

## Keys

`For all fractal :`

* Move : <kbd>Arrows</kbd> 
* Reset : <kbd>R</kbd> 
* Change zoom : <kbd><</kbd> or <kbd>></kbd> or <kbd>Move cursor</kbd>

`Julia Only :`

* Directly change julia parameters : <kbd>+</kbd> or <kbd>-</kbd>

![fract-ol](/images/mandelbrot_set.png)
