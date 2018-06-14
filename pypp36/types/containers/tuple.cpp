#include "tuple.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::tuple tup;
//
tup::tuple(PyObject* pyTuple)
:	object(pyTuple) {
}
//
Py_ssize_t tup::size()const {
	return PyTuple_Size(_ptr);
}
//getItem
PyObject* tup::operator [](
	const Py_ssize_t index
)const{
	if(index >= this->size() || index < 0){
		return nullptr;
	}
	return _ptr ? PyTuple_GetItem(_ptr, index):nullptr;
}
//
int tup::setItem(
	Py_ssize_t size,
	PyObject* ob
){
	return PyTuple_SetItem(_ptr, size, ob);
}
PyObject* tup::getSlice(
	Py_ssize_t begin,
	Py_ssize_t end
){
	//if end < being, the list returned by the tuple will be reversed
	return _ptr?PyTuple_GetSlice(_ptr, begin, end):nullptr;
}
//#ifndef Py_LIMITED_API
//int _resize(PyObject **, Py_ssize_t){
//}
//#endif
//PyObject* pack(Py_ssize_t, ...){PyTuple_Pack();}
//#ifndef Py_LIMITED_API
//void _MaybeUntrack(){
//_PyTuple_MaybeUntrack(_ptr);
//}
//#endif

/* Macro, trading safety for speed */
//#ifndef Py_LIMITED_API
//#define PyTuple_GET_ITEM(op, i) (((PyTupleObject *)(op))->ob_item[i])
//#define PyTuple_GET_SIZE(op)    Py_SIZE(op)
///* Macro, *only* to be used to fill in brand new tuples */
//#define PyTuple_SET_ITEM(op, i, v) (((PyTupleObject *)(op))->ob_item[i] = v)
//#endif

int tup::clearFreeList(void){
	return PyTuple_ClearFreeList();
}