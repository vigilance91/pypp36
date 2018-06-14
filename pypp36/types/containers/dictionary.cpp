#include "dictionary.h"
//#include <Python.h>
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::dictionary dict;

dict::dictionary(PyObject* dict)
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

///index operator dict['key']
PyObject* dict::operator[](const NString& key)const {
	return _ptr ? PyDict_GetItemString(_ptr, key.c_str()) : nullptr;
}
///index operator dict[PyObject*], as python objects which as hashable can be dictionary keys
PyObject* dict::operator[](PyObject* key)const{
	return _ptr ? PyDict_GetItem(_ptr, key) : nullptr;
}
PyObject* dict::gKeys()const {
	return _ptr ? PyDict_Keys(_ptr) : nullptr;
}
PyObject* dict::gValues()const {
	return _ptr ? PyDict_Values(_ptr) : nullptr;
}
///number of entries within dictionary
Py_ssize_t dict::size()const {
	return _ptr ? PyDict_Size(_ptr) : 0;
}
///these methods return -1 on error, 0 on failure and 1 on success
int dict::update(PyObject* other) {
	return PyDict_Update(_ptr, other);
}
///does this dictionary contain keys that are only strings
int dict::hasOnlyStringKeys()const {
	return _PyDict_HasOnlyStringKeys(_ptr);
}
///combine contents of
int dict::merge(PyObject *other, int or ) {
	return PyDict_Merge(_ptr, other, or );
}
///check if key exists within dictionary
int dict::contains(PyObject* key)const {
	return PyDict_Contains(_ptr, key);
}