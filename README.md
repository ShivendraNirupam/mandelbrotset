# 🌀 Mandelbrot Set Visualizer using SDL2

A mesmerizing visualization of the Mandelbrot Set using C++ and SDL2.  
This project renders the intricate fractal pattern based on complex number iterations, bringing mathematical beauty to life through code.

![Mandelbrot Set Output](./mandelbrot.png)

---

## 🔬 Mathematical Background

The Mandelbrot Set is defined in the complex plane and revolves around the iterative function:

\[
z_{n+1} = z_n^2 + c
\]

- **Where:**
  - \( z_0 = 0 \)
  - \( c \in \mathbb{C} \) is a complex number (each pixel maps to one)
  - We iterate the formula and check whether the magnitude of \( z_n \) escapes to infinity.

- A point `c` belongs to the Mandelbrot Set if the limit of the sequence `zₙ = zₙ₋₁² + c` does not diverge.  
- That is: `lim |zₙ| ≤ 2` as `n → ∞`.


- In the code:
  - We compute up to 500 iterations.
  - If the squared magnitude (norm) of \( z \) exceeds 10, we consider it to have **escaped**.
  - Otherwise, the point is **inside** the Mandelbrot Set.

---

## ⚙️ How It Works

- The 2D screen maps the region of the complex plane from **-2 to 2** on both axes.
- Each pixel's coordinate is converted to a complex number \( c \).
- The function \( z_{n+1} = z_n^2 + c \) is iterated.
- The number of iterations before escaping is used to determine pixel color.

---

## 🛠️ Compilation Instructions

Make sure you have **SDL2** installed.  
Then run the following command in your terminal:

```bash
g++ mandelbrot.cpp -o main $(sdl2-config --cflags --libs)
