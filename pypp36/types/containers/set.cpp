#include "set.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::set pySet;
//
pySet::set(PyObject* dict)
:	pyObj(dict){
}
//virtual ~dict() {
//	//this data structure does not release the underlying PyObject,
//	//the calling programmer must call all approriate clean-up code
//}
//PyObject* operator[](const NString& key)const {
//	return _ptr ? PyDict_GetItemString(_ptr, key.c_str()) : nullptr;
//}
//PyObject* operator[](PyObject* key)const {
//	return _ptr ? PyDict_GetItem(_ptr, key) : nullptr;
//}
//static PyObject *make();    //PySet_New(PyObject *);
//static PyObject * makeFrozenSet(PyObject *);
Py_ssize_t pySet::size()const{
	return _ptr?PySet_Size(_ptr):0;
}
int pySet::clear(){
	return PySet_Clear(_ptr);
}
int pySet::contains(PyObject *key){
	return _ptr?PySet_Contains(_ptr, key):-1;
}
int pySet::discard(PyObject *key){
	return _ptr ? PySet_Discard(_ptr, key): -1;
}
int pySet::add(PyObject *key){
	return _ptr ? PySet_Add(_ptr, key): -1;
}
PyObject* pySet::pop(){
	return _ptr ? PySet_Pop(_ptr):nullptr;
}
#ifndef Py_LIMITED_API
//#define PySet_GET_SIZE(so) (((PySetObject *)(so))->used)
//int _nextEntry(Py_ssize_t *pos, PyObject **key, Py_hash_t *hash){}
//int _update(PyObject *iterable){
//    return PySet_Update(_ptr, iterable);
//}
#endif