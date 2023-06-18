## Features
* Render different fractals: mandelbrot, julia, tricorn
* Different color schemes (rotated and linear)
* Smooth and linear coloring

### Planned features
* Calculate values with OpenCL
* Selective anti-aliasing
* Chunked rendering to buffer while moving around

## Compiling and running
Run `make`. An executable will compile. Runs on OS X and Linux.

Run it with `./fractol [fractal]`. Possible fractals are: `Mandelbrot`, `Julia`,
`Tricorn`. Cycle color-schemes with `C` or `P`.Zoom in and out with the
mousewheel.Reset with `R`.Stop `Julia` with `S` and Move it with `M`.
And move around with `Arrows`.

## License
This project is licensed under the GNU General Public License 3.
