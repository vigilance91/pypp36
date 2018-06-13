///
///@file eval.h
///@author Tyler R. Drury
///@copyright (C) June 12 2018-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python eval interface
///
#ifndef PYPP_EVAL_H
#define PYPP_EVAL_H
//
#include "py.h"
//
PY_NS_BEGIN
///
///@namespace eval
///@brief namespace for python eval interface
///@ingroup py
///@{
///
namespace eval
{
	//PyObject 
		//*code(
		//	PyObject *co,
		//	PyObject *globals,
		//	PyObject *locals
		//),
		//*codeEx(
		//	PyObject *co,
		//	PyObject *globals,
		//	PyObject *locals
		//),
		//*frame(
		//	PyFrameObject *f,
		//),
		//*frameEx(
		//	PyFrameObject *f,
		//);
	//int mergeComplierFlags(PyComplerFlags *cf);
	
	///
	///@brief Interpreter Reflection
	///
	namespace get
	{
		extern PyObject
			///
			///@brief Returns the builtins in the current execution frame, or the interpreter of the thread state if no frame is currently executing.
			///@return borrowed reference, dictionary
			///
			*builtins(),
			///
			///@brief the local variables in the current execution frame, or NULL if no frame is currently executing.
			///@return borrowed reference, dictionary
			///
			*locals(),
			///
			///@brief Return a dictionary of the global variables in the current execution frame, or NULL if no frame is currently executing.
			///@return borrowed reference, dictionary
			///
			*globals();
		/////
		/////@brief Return the current thread state’s frame, which is NULL if no frame is currently executing.
		/////@return borrowed reference
		/////
		//PyFrameObject* frame() {

		//}
		//int lineNumber(PyFrameObject *frame){
		//	return PyFrame_GetLineNumber(frame);
		//}
		///Return the name of func if it is a function, class or instance object, else the name of funcs type.
		extern const char*
			funcName(PyObject *func),
			///
			///@brief Return a description string, depending on the type of func.
			///@return includes “()” for functions and methods, ” constructor”, ” instance”, and ” object”.
			///@note Concatenated with the result of PyEval_GetFuncName(), the result will be a description of func.
			///
			*funcDesc(PyObject *func);
	};
};
///
///@}
///
NS_END
#endif