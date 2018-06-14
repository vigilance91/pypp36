#include "object.h"
//
//using namespace py::marshal;
typedef py::object obj;
//
typedef PyObject *pyPtr;
//
obj(pyPtr ptr = nullptr)   //dealloc = nullptr //assign to &pxpy::decRef for (this) to deallocate
:	_ptr(ptr)
{
	//copy construct pointer,
	//does not take ownership,
	//incRef wrapper to take ownership
}
//object(object&& rhs)   //dealloc = nullptr //assign to &pxpy::decRef for (this) to deallocate
//:	_ptr(std::move(rhs._ptr)){
//	//efficiently move a pointer to a python object to another instances
//	//after executing,
//	//the original obj._ptr is invalid but not null or undefined,
//	//but since obj is a temporary r-value it does not matter as it will be deallocated after its internals have been moved
//}
//object& object::operator=(object&& rhs){
//	if(this->_ptr){
//	}
//this->_ptr = std::move(rhs._ptr);
//return *this;
//}

PyObject* obj::get()const{
	return _ptr;
}
PyObject* obj::getAttrString(
	const NString& str
)const{
	return _ptr ? PyObject_GetAttrString(_ptr, str.c_str()) : nullptr;
}
PyObject* obj::getAttr(
	PyObject* attr
)const{
	return _ptr ? PyObject_GetAttr(_ptr, attr) : nullptr;
}
int obj::setAttrString(
	const NString& str,
	PyObject* value
){
	PyObject_SetAttrString(_ptr, str.c_str(), value);
}
int obj::hasAttrString(
	const NString& str
)const{
	return PyObject_HasAttrString(_ptr, str.c_str());
}
int obj::setAttr(
	PyObject* key,
	PyObject* value
){
	return PyObject_SetAttr(_ptr, key, value);
}
int obj::hasAttr(
	PyObject* attr
)const{
	return PyObject_HasAttr(_ptr, attr);
}
int obj::isCallable()const{
	return PyCallable_Check(_ptr);
}
void obj::clearWeakRefs(){
	if(_ptr){
		PyObject_ClearWeakRefs(_ptr);
	}
}
///
void obj::incRef(){
	Py_INCREF(_ptr);
}
void obj::xIncRef(){
	Py_XINCREF(_ptr);
}
void obj::decRef(){
	Py_DECREF(_ptr);
}
void obj::xDecRef() {
	Py_XDECREF(_ptr);
}
void obj::clear(){
	if(_ptr){
		Py_CLEAR(_ptr);
	}
}
//postfix operator++(){
//short-hand for incRef
//}
//postfix operator--(){
//short-hand for decRef
//}
// PyObject* operator ()(char *method, char *format, ...){
//     va_list vaargs;
//     va_start(vaargs, format);
//     
//     PyObject * ret = PyObject_CallMethod(_ptr, method, format, vaargs);

//     va_end(vaargs);

//     return ret;
// }