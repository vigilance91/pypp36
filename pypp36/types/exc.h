//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file exc.h
///@author Tyler R. Drury
///@copyright (C) June 12 2018-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python exception interface
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_EXC_H
#define PYPP_EXC_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//typedef PyObject* pyPtr;
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@brief python execption type wrapper
///@ingroup py
///@{
///
struct exception
:	public object
{
	explicit exception(PyObject* ex);

	virtual ~exception(){
	}
	///
	///@brief Return the traceback associated with the exception as a new reference, as accessible from Python through __traceback__
	///@return new reference, If there is no traceback associated, this returns NULL.
	///
	int setTraceback(PyObject *tb);

	PyObject
		///
		*getTraceback(),
		///get execption context
		*getContext(),
		///Return the exception's cause (either an exception instance, or None, set by raise ... from ...) associated with the exception as a new reference, as accessible from Python through __cause__.
		*getCause();
	///
	///@brief Set the cause associated with the exception to cause.Use NULL to clear it.There is no type check to make sure that cause is either an exception instance or None.
	///@note This steals a reference to cause.
	///
	void setCause(PyObject *cause);
};

//	typedef PyExc_BaseException BaseException;
//	typedef PyExc_Exception Exception;
//	typedef PyExc_ArithmeticError ArithmeticError;
//	typedef PyExc_LookupError LookupError;
//	typedef PyExc_AssertionError AssertionError;
//	typedef PyExc_AttributeError AttributeError;
//	typedef PyExc_BlockingIOError BlockingIOError;
//	typedef PyExc_BrokenPipeError BrokenPipeError;
//	typedef PyExc_ChildProcessError ChildProcessError;
//	typedef PyExc_ConnectionError ConnectionError;
//	typedef PyExc_ConnectionAbortedError ConnectionAbortedError;
//	typedef PyExc_ConnectionRefusedError ConnectionRefusedError;
//	typedef PyExc_ConnectionResetError ConnectionResetError;
//	typedef PyExc_FileExistsError FileExistsError;
//	typedef PyExc_FileNotFoundError FileNotFoundError;
//	typedef PyExc_EOFError EOFError;
//	typedef PyExc_FloatingPointError FloatingPointError;
//	typedef PyExc_ImportError ImportError;
//	typedef PyExc_IndexError IndexError;
//	typedef PyExc_InterruptedError InterruptedError;
//	typedef PyExc_IsADirectoryError IsADirectoryError;
//	typedef PyExc_KeyError KeyError;
//	typedef PyExc_KeyboardInterrupt KeyboardInterrupt;
//	typedef PyExc_MemoryError MemoryError;
//	typedef PyExc_NameError NameError;
//	typedef PyExc_NotADirectoryError NotADirectoryError;
//	typedef PyExc_NotImplementedError NotImplementedError;
//	typedef PyExc_OSError OSError;
//	typedef PyExc_OverflowError OverflowError;
//	typedef PyExc_PermissionError PermissionError;
//	typedef PyExc_ProcessLookupError ProcessLookupError;
//	typedef PyExc_ReferenceError ReferenceError;
//	typedef PyExc_RuntimeError RuntimeError;
//	typedef PyExc_SyntaxError SyntaxError;
//	typedef PyExc_SystemError SystemError;
//	typedef PyExc_TimeoutError TimeoutError;
//	typedef PyExc_SystemExit SystemExit;
//	typedef PyExc_TypeError TypeError;
//	typedef PyExc_ValueError ValueError;
//	typedef PyExc_ZeroDivisionError;
// version3.3+
//PyExc_ChildProcessError,
//PyExc_ConnectionError,
//PyExc_ConnectionAbortedError,
//PyExc_ConnectionRefusedError,
//PyExc_ConnectionResetError,
//PyExc_FileExistsError,
//PyExc_FileNotFoundError,
//PyExc_InterruptedError,
//PyExc_IsADirectoryError,
//PyExc_NotADirectoryError,
//PyExc_PermissionError,
///
///@}
///
NS_END
#endif