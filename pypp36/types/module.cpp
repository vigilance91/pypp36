#include "module.h"
//
typedef py::object pyObj;
typedef py::module mod;
//
mod mod::import(
	const NString& name/* UTF-8 encoded string, */
){
	return mod(name);
}
//caller is responsible for decRef()'ing these objects
mod::module(const NString& name)
:	object(PyImport_ImportModule(name.c_str()))
{
	//if(!_ptr){

	//}
}

PyObject* mod::getDict(){
	return _ptr?PyModule_GetDict(_ptr):nullptr;
}
NString mod::getName(){
	//#ifdef _DEBUG
	NString ret= _ptr? NString(PyModule_GetName(_ptr)):"";
	return ret;
	//#else
	//return NString(PyModule_GetName(_ptr) );        
	//#endif
}
NString mod::getFilename()const{
	NString ret = "";	//_ptr?NString(PyModule_GetFileName(_ptr)) : "";
	return ret;
}
PyObject* mod::getFilenameObject()const{
	return nullptr;
	//return _ptr?PyModule_GetFileNameObject(_ptr):nullptr;
}
#ifndef Py_LIMITED_API
void mod::clear()const{
	if(_ptr){
		_PyModule_Clear(_ptr);
	}
}
#endif
struct PyModuleDef* mod::getDef()const{
	return _ptr?PyModule_GetDef(_ptr):nullptr;
}
void* mod::getState()const{
	return _ptr?PyModule_GetState(_ptr):nullptr;
}