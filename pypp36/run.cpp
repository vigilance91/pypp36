#include "run.h"
//
using namespace py::run;
//
//interactive::one(FILE *fp, const char *filename){
//}
//interactive::oneFlags(FILE *fp, const char *filename){
//}
//interactive::loop(FILE *fp, const char *filename){
//}
//interactive::loopFlags(FILE *fp, const char *filename){
//}
//setInputHook
//setReadLineCB
//
//

///
///@namespace any
///@brief Python interface for executing any file
///
//int any::file(FILE *f, const char*filename){}
//	any::fileFlags(){}
//any::fileEX(){}
//any::fileEXFlags(){}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
const bool simple::string(const char*cmd) {
	//assert !null
	//try{
	int r = PyRun_SimpleString(
		cmd
		////inline test string
		//	"from time import time, ctime\n"
		//	"print('Today is', ctime(time()))\n"
	);
	//ensure no errors occured during execution
	PyObject *pyErr = PyErr_Occurred();

	if (pyErr != NULL) {
		//if(PyErr_ExceptionMatches()){
		//do stuff for specific type of exception
		//}
		//err
		PyErr_Clear();	//clears exception state, continueing with processing scripts

		return false;
	}

	return r == 0;
	//}
	//catch(exception& e){
	//}
	//catch(...){
	//}
	//return false;
}
//simple::stringFlags(const char*cmd, PyCOmpilerFlags *flags)
//
//simple::file(FILE *fp, const char*filename),
//simple::fileEx(FILE *fp, const char*filename),
//simple::fileExFlags(FILE *fp, const char*filename);

//PyObject 
//*string(
//const char *str, int start, PyObject *globals
//),
//*stringFlags(
//const char *str, int start, PyObject *globals
//),
//*file(
//const char *str, int start, PyObject *globals
//),
//*fileFlags(
//const char *str, int start, PyObject *globals
//),
//*fileExFlags(
//const char *str, int start, PyObject *globals
//);
//};
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//PyObject *compile::stringFlags(const char *str, const char*filename, int start, PyCompilerFlags* flags){
//}
//PyObject *compile::stringExFlags(const char *str, const char*filename, int start, PyCompilerFlags* flags){
//}
//PyObject *compile::stringObject(const char *str, const char*filename, int start, PyCompilerFlags* flags, int opimize){
//}
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//namespace parser {
//	namespace parseSimple {
//		//PyObject
//		//*string(const char *str, int start),
//		//*stringFlags(const char *str, int start),
//		//*stringFlagsFilename(const char *str, int start),
//		//
//		//*file(FILE *fp, const char *filename, int start),
//		//*fileFlags(FILE *fp, const char *filename, int start);
//	};
//};