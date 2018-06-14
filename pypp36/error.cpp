#include "error.h"
//
namespace err = py::error;
namespace eSet = err::set;
//namespace eWarn = err::warn;
//
//typedef PyObject *pyObjPtr;
//
void err::printEx(int set_sys_last_var) {

}
void err::print(){
}
///
///
///@return borrowed reference
///
//PyObject *occurred(){}
///
//int exceptionMatches(){}
//void normalizeException(){}
///Clear the error indicator. If the error indicator is not set, there is no effect.
void err::clear() {
	PyErr_Clear();
}
///Retrieve the error indicator into three variables whose addresses are passed
void err::fetch(){
}
///
///@brief Set the error indicator from the three objects. If the error indicator is already set, it is cleared first
///@note If the objects are NULL, the error indicator is cleared.
///@warning Do not pass a NULL type and non-NULL value or traceback. The exception type should be a class. Do not pass an invalid exception type or value. (Violating these rules will cause subtle problems later).
///
void err::restore(
	PyObject *type,
	PyObject *value,
	PyObject *traceback
) {
	PyErr_Restore(type, value, traceback);
}

///
void eSet::string(){
}
///
void eSet::object(){
}

void eSet::none(PyObject* type) {
}

PyObject *eSet::fromErrno(PyObject *type) {
	return nullptr;
}
		//return PyErr_SetFromErrno(type);
PyObject *eSet::fromErrnoWithFilenameObject(
	PyObject *type,
	PyObject *filenameObject
) {
	return nullptr;
}
PyObject *eSet::importError(
	PyObject *msg,
	PyObject *name,
	PyObject *path
) {
	return nullptr;
}
	/////
	/////@brief convenience function to raise WindowsError.
	/////@details If called with ierr of 0, the error code returned by a call to GetLastError() is used instead. It calls the Win32 function FormatMessage() to retrieve the Windows description of error code given by ierr or GetLastError(), then it constructs a tuple object whose first item is the ierr value and whose second item is the corresponding error message (gotten from FormatMessage()), and then calls PyErr_SetObject(PyExc_WindowsError, object). 
	/////@return Always NULL, so a wrapper function around a system call can write return PyErr_SetFromErrno(type); when the system call returns an error.
	/////@note Availability: Windows
	/////
	//PyObject* fromWindowsErr(int ierr){

	//}
	/////
	/////@brief Similar to PyErr_SetFromWindowsErr(), with an additional parameter specifying the exception type to be raised.
	/////@return Always NULL, so a wrapper function around a system call can write return PyErr_SetFromErrno(type); when the system call returns an error.
	/////@note Availability: Windows
	/////
	//PyObject* excFromWindowsErr(PyObject *type, int ierr){

	//}
//
//
//
//PyObject *err::format(){
//}
///shorthand for PyErr_SetString(PyExc_TypeError, message), where message indicates that a built-in operation was invoked with an illegal argument, mostly intended for internal use
int err::badArgument(){
	return PyErr_BadArgument();
}
///
///@brief shorthand for PyErr_SetNone(PyExc_MemoryError).
///@return always NULL, so an object allocation function can write return PyErr_NoMemory(), when it runs out of memory.
///
PyObject *err::noMemory(){
	return PyErr_NoMemory();
}
//namespace warn
//{
//
//};