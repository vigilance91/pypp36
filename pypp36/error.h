//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file error.h
///@author Tyler R. Drury
///@copyright (C) June 12 2018-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python error interface
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_ERROR_H
#define PYPP_ERROR_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "py.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//typedef PyObject* pyPtr;
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@namespace error
///@ingroup py
///@{
///
namespace error
{
	///
	extern void
		printEx(int set_sys_last_var),
		print(),
		normalizeException(),
		///Clear the error indicator. If the error indicator is not set, there is no effect.
		clear(),
		///Retrieve the error indicator into three variables whose addresses are passed
		fetch(),
		///
		///@brief Set the error indicator from the three objects. If the error indicator is already set, it is cleared first
		///@note If the objects are NULL, the error indicator is cleared.
		///@warning Do not pass a NULL type and non-NULL value or traceback. The exception type should be a class. Do not pass an invalid exception type or value. (Violating these rules will cause subtle problems later).
		///
		restore(
			PyObject *type,
			PyObject *value,
			PyObject *traceback
		);
//		PyErr_Restore(type, value, traceback);
	//}
		///
		///
		///@return borrowed reference
		///
	//extern PyObject
		//*occurred();
	///
	//extern int exceptionMatches(){}
	
	//void  {
	//	PyErr_Clear();
	//}

	//}
	
	namespace set
	{
		///
		extern void
			string(),
			///
			object(),
			///shorthand for PyErr_SetObject(type, Py_None).
			none(PyObject* type);
		///
		///@breif convenience function to raise an exception when a C library function has returned an error and set the C variable errno.It constructs a tuple object whose first item is the integer errno value and whose second item is the corresponding error message(gotten from strerror()), and then calls PyErr_SetObject(type, object).
		///@return Alwways NULL, so a wrapper function around a system call can write return PyErr_SetFromErrno(type); when the system call returns an error.
		///
		extern PyObject
			*fromErrno(PyObject *type),
				//return PyErr_SetFromErrno(type);
			*fromErrnoWithFilenameObject(
				PyObject *type,
				PyObject *filenameObject
			),
			*importError(
				PyObject *msg,
				PyObject *name,
				PyObject *path
			);
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
	};
	//PyObject *format(){}
	///shorthand for PyErr_SetString(PyExc_TypeError, message), where message indicates that a built-in operation was invoked with an illegal argument, mostly intended for internal use
	extern int badArgument();
	///
	///@brief shorthand for PyErr_SetNone(PyExc_MemoryError).
	///@return always NULL, so an object allocation function can write return PyErr_NoMemory(), when it runs out of memory.
	///
	extern PyObject *noMemory();
		//return PyErr_NoMemory();
	//}
	namespace warn
	{

	};
};
///
///@}
///
NS_END
#endif