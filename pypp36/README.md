# pypp36

Python++ is a minimalist C++ 2017 compatible static link library providing a modern, lightweight wrapper for embedding the Python Interpreter C API within a compiled windows console application.

---

Developed by [Tyler R. Drury](https://vigilance91.github.io/)

---

## Dependencies

* x64 Windows OS
* Visual Studios 2017/MSVC 2017 compiler
* Python 3.6 (64-bit)

---

## Use

Along with a copy of python36.dll, the file pypp36.lib should be included with the project.
    
Then, from the top of your project's main file, include the line

    #include "pypp36.h";
    
Finally clean, re-build and run.

See [pypp-cli](https://github.com/vigilance91/pypp-cli) for more in-depth walk-through of starting a Python embedded C++ application.

---

## Download

Latest Binaries, Static Libraries and Source Code can be found at
[here](https://vigilance91.github.io/) or from the GitHub Repo [here](https://github.com/vigilance91/pypp36),
if you wish to contribute.

---

## Contributors
   Tyler R. Drury
   

---

## References and Resources

* [Official Python Home](https://www.python.org/)
* [Official Python 3 C API Reference](https://docs.python.org/3/c-api/intro.html)
* [Official Python++ Reference](https://vigilance91.github.io/pypp36/index.html)

---