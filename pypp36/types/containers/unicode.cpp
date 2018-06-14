#include "unicode.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::unicode uni;

uni::unicode(PyObject* dict)
:	pyObj(dict){
}
//virtual ~dict() {
//	//this data structure does not release the underlying PyObject,
//	//the calling programmer must call all approriate clean-up code
//}
