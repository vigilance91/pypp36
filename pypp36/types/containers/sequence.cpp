#include "sequence.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::sequence seq;

seq::sequence(PyObject* pySequence)
:	object(pySequence){
}

PyObject* seq::operator [](const unsigned& index){
	return _ptr?PySequence_GetItem(_ptr, index):nullptr;
}
PyObject* seq::getSlize(Py_ssize_t i1, Py_ssize_t i2) {
	return _ptr?PySequence_GetSlice(_ptr, i1, i2):nullptr;
}
//int setItem(Py_ssize_t i, PyObject* o){ return PySequence_SetItem(_ptr, i, o); }
//int deleteItem(Py_ssize_t i){ return PySequence_delItem(_ptr, i); }
//you are responsible for Py_DECREF'ing the return
//PyObject* concat(){}
//return size of sequence, or -1 on failure
Py_ssize_t seq::size(){
	return _ptr ? PySequence_Size(_ptr) : 0;
}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//"casting" operators
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//convert to tuple
//pyTuple asTuple(){ return PySequence_Tuple(_ptr); }
//convert to list
//pyList asList(){ return PySequence_List(_ptr); }
//
//explicit pyTuple operator(){}
//explicit pyList operator(){}