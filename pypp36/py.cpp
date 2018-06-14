//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "py.h"
#include <Python.h>
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//using namespace py;
namespace pg = py::_get;
namespace ps = py::_set;
namespace prog = py::program;
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
void py::init(){
	//_prog=
	Py_Initialize();
}
//void initEx(int initsigs){
//Py_InitializeEx(initsigs);
//}

///is a running instanse of the Python interpreter already running
bool py::isInitialized() {
	return Py_IsInitialized();
}
///finalize interpreter, deallocating all resources and disabling any further calls to python functions
void py::finailze(){
	//deallocat _prog
	//_prog = 0;
	Py_Finalize();
	//!Py_FinalizeEx() ? :{
	//err << "Fatal error: could not close python interpreter properly";
	//exit(-1);
	//}:;	//else do nothing
}
//process control
void py::fatalError(const char* msg) {
	Py_FatalError(msg);
}
///Exit the current process. This calls Py_Finalize() and then calls the standard C library function exit(status).
void py::exit(int status) {
	Py_Exit(status);
}
///
///@brief Register a cleanup function to be called by Py_Finalize(). 
///@arg func will be called with no arguments and should return no value.
///@note At most 32 cleanup functions can be registered. The cleanup function registered last is called first. Each cleanup function will be called at most once. Since Python’s internal finalization will have completed before the cleanup function, no Python APIs should be called by func.
///@return when successful returns 0; on failure, returns -1
///
int py::atExit(void(*func)()) {
	return Py_AtExit(func);
}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
int ps::standardStreamEncoding(char *encoding, char *errors){
	return Py_SetStandardStreamEncoding(encoding, errors);
}
void ps::programName(wchar_t *name) {
	Py_SetProgramName(name);
}
void ps::path(const wchar_t* p) {
	Py_SetPath(p);
}
void ps::pythonHome(wchar_t *home) {
	return Py_SetPythonHome(home);
}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
wchar_t* execPrefix() {
	return Py_GetExecPrefix();
}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
wchar_t *prog::name(){
	return Py_GetProgramName();
}
wchar_t* prog::fullPath(){
	return Py_GetProgramFullPath();
}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
wchar_t* path(){
	return Py_GetPath();
}
///python version
const char* pg::version(){
	return Py_GetVersion();
}
const char* pg::platform(){
	return Py_GetPlatform();
}
const char* pg::copyright(){
	return Py_GetCopyright();
}
///compiler version used to build python
const char* pg::complier(){
	return Py_GetCompiler();
}
const char* pg::buildInfo(){
	return Py_GetBuildInfo();
}
wchar_t* pg::pythonHome(){
	return Py_GetPythonHome();
}