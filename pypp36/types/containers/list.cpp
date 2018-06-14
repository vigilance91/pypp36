#include "list.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::list li;
//
li::list(PyObject* list)
:	pyObj(list){
}
Py_ssize_t li::size()const{
	return _ptr?PyList_Size(_ptr):0;
}
PyObject* li::operator [](const unsigned index){
	//PyList_GetItem(PyObject *, Py_ssize_t);
	return _ptr?PyList_GetItem(_ptr, index):nullptr;
}
int li::setItem(Py_ssize_t index, PyObject *item) {
	return PyList_SetItem(_ptr, index, item);
}
//int insert(PyObject *, Py_ssize_t, PyObject *){ return PyList_Insert(_ptr, index, );}
int li::append(PyObject *item) {
	//assert(_ptr ^ item != 0)
	return PyList_Append(_ptr, item);
}
PyObject* li::getSlice(Py_ssize_t begin, Py_ssize_t end) {
	//decRef return?
	return _ptr?PyList_GetSlice(_ptr, begin, end):nullptr;
}
int li::setSlice(Py_ssize_t begin, Py_ssize_t end, PyObject *item) {
	return PyList_SetSlice(_ptr, begin, end, item);
}
int li::sort(){
	return PyList_Sort(_ptr);
}
int li::reverse(){
	return PyList_Reverse(_ptr);
}
PyObject *li::asTuple(PyObject* ptr){
	return ptr?PyList_AsTuple(ptr):nullptr;
}
//tuple asTuple(){return tuple(asTuple(_ptr) );}
//#ifndef Py_LIMITED_API
//PyObject* _extend(PyListObject *, PyObject *);
//#endif

/* Macro, trading safety for speed */
//#ifndef Py_LIMITED_API
//    #define PyList_GET_ITEM(op, i) (((PyListObject *)(op))->ob_item[i])
//    #define PyList_SET_ITEM(op, i, v) (((PyListObject *)(op))->ob_item[i] = (v))
//    #define PyList_GET_SIZE(op)    Py_SIZE(op)
//#endif