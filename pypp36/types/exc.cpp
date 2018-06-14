#include "exc.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::exception e;
//
typedef PyObject *pyPtr;
//
e::exception(pyPtr ex)
:	pyObj(ex)
{
}
//
PyObject *e::getTraceback(){
	return _ptr?PyException_GetTraceback(this->_ptr):nullptr;
}
int e::setTraceback(PyObject *tb){
	return (_ptr && tb) ? PyException_SetTraceback(this->_ptr, tb):-1;
}
PyObject *e::getContext(){
	return _ptr?PyException_GetContext(this->_ptr):nullptr;
}
//
PyObject *e::getCause(){
	return _ptr?PyException_GetCause(this->_ptr):nullptr;
}
//
void e::setCause(PyObject *cause){
	if(_ptr && cause){
		PyException_SetCause(this->_ptr, cause);
	}
}