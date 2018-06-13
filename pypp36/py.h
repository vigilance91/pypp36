//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file py.h
///@author Tyler R. Drury
///@copyright (C) June 11 2018-present, Tyler R. Drury, All Rights Reserved
///@version 0.1.0
///@brief python c api, C++ wrapper for fast, modern Python development
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_H
#define PYPP_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//generate compiler error if not using C++ to compile
#ifndef __cplusplus
	#error invalid compiler, C++ compiler required
#endif
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include <Python.h>
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//#define PX_PY_API(returnType) inline returnType
#define PY_NS_BEGIN namespace py {
#define NS_END };
//
//#define PY_OBJ_CALL(...) PyObject_##__FUNCTION__(_ptr, __VA_ARGS__);
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@namespace py
///@brief Python API namespace
///@defgroup py Python C++ Interface Wrapper
///@ingroup py
///@{
///
namespace py
{
	//int _prog=0;

	///initilize interpreter
	extern void
		init(),
		finailze(),
		fatalError(const char* msg),
		exit(int status);
		//initEx(int initsigs){
			//Py_InitializeEx(initsigs);
		//}

	///is a running instanse of the Python interpreter already running
	extern bool isInitialized();
	///finalize interpreter, deallocating all resources and disabling any further calls to python functions
	
	
	///
	///@brief Register a cleanup function to be called by Py_Finalize(). 
	///@arg func will be called with no arguments and should return no value.
	///@note At most 32 cleanup functions can be registered. The cleanup function registered last is called first. Each cleanup function will be called at most once. Since Python’s internal finalization will have completed before the cleanup function, no Python APIs should be called by func.
	///@return when successful returns 0; on failure, returns -1
	///
	extern int atExit(void(*func)());
	//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
	namespace program
	{
		extern wchar_t
			*name(),
			*fullPath();
	};
	///
	///@brief interface for setting values within the executing interpreter instance
	///
	namespace set
	{
		extern int standardStreamEncoding(char *encoding, char *errors);
		
		extern void
			programName(wchar_t *name),
			path(const wchar_t* p),
			pythonHome(wchar_t *home);
	};
	//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
	///
	///@brief interface for setting values for the executing interpreter instance
	///
	namespace get {
		extern wchar_t
			*path(),
			*execPrefix(),
			*pythonHome();

		namespace program{
			extern wchar_t
				*name(),
				*fullPath();
		};
		///python version
		extern const char
			*version(),
			*platform(),
			*copyright(),
			*complier(),
			*buildInfo();
	};
};
///
///@}
///
#endif