#include "eval.h"
#include <Python.h>
//
using namespace py::eval;
//
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


PyObject *get::builtins() {
	//return dict(PyEval_GetBuiltins());
	return PyEval_GetBuiltins();
}
	///
	///@brief the local variables in the current execution frame, or NULL if no frame is currently executing.
	///@return borrowed reference, dictionary
	///
PyObject *get::locals(){
	//return dict(PyEval_GetLocals());
	return PyEval_GetLocals();
}
	///
	///@brief Return a dictionary of the global variables in the current execution frame, or NULL if no frame is currently executing.
	///@return borrowed reference, dictionary
	///
PyObject *get::globals(){
	//return dict(PyEval_GetGlobals());
	return PyEval_GetGlobals();
}
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
const char* get::funcName(PyObject *func) {
	return PyEval_GetFuncName(func);
}
///
///@brief Return a description string, depending on the type of func.
///@return includes “()” for functions and methods, ” constructor”, ” instance”, and ” object”.
///@note Concatenated with the result of PyEval_GetFuncName(), the result will be a description of func.
///
const char* get::funcDesc(PyObject *func) {
	return PyEval_GetFuncDesc(func);
}