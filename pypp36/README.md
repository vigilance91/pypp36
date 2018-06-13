# pypp

Python++ is a minimalist C++ 2017 compatible static link library providing a modern, lightweight wrapper for embedding the Python Interpreter C API within a compiled windows console application.

---

Developed by [Tyler R. Drury]()

---

## Dependencies

* x64 Windows OS
* Visual Studios 2017/MSVC 2017 compiler
* Python 3.6

---

## Use

Along with a copy of python36.dll, the file pypp36.lib should be included within the project.
    
Then, from the top of your project's main file, include the line

    #include "pypp36.h";
    
Finally clean, re-build and run.

---

## Download

Latest Binaries, Static Libraries and Source Code can be found at
[Vigil Studios]() or from the [GitHub Repo](), if you wish to contribute.

---

## Contributors
   Tyler R. Drury
   

---

## Related Projects

Similar projects for various platforms can also be found here

* [pyppSerializer]()   a C++ python console application for serialization of JSON and/or XML files
* [pxParser-py]()     python package containing the defaco standard px parser module
* [pxParser]()   a trivial C++ console application implementing pxParser-py
* [rpgAlpha]()  a rpg game built using DirectX10, python and the px engine


---

## References and Resources

* [Official Python Home](https://www.python.org/)
* [Official Python 3 C API Reference](https://docs.python.org/3/c-api/intro.html)
* [Official Python++ Reference]()

---