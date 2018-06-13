//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file run.h
///@author Tyler R. Drury
///@copyright (C) June 13 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief Python interface for executing commands
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_RUN_H
#define PYPP_RUN_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@namespace run
///@brief executing string and files as commands through the python interpreter
///@ingroup py
///@{
///
namespace run{
	///
	///@namespace interactive
	///@brief python interactive session interface
	///
	namespace interactive {
		//one(FILE *fp, const char *filename)
		//oneFlags(FILE *fp, const char *filename)
		//loop(FILE *fp, const char *filename)
		//loopFlags(FILE *fp, const char *filename)
	};
	//setInputHook
	//setReadLineCB
	//
	//

	///
	///@namespace any
	///@brief Python interface for executing any file
	///
	namespace any{
		//int file(FILE *f, const char*filename)
		//	fileFlags(),
			//fileEX(),
			//fileEXFlags();
	};
	//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
	///
	///@namespace simple
	///@brief python interface for the execution of simple statements via string or file
	///
	namespace simple{
		extern const bool string(const char*cmd);
		//stringFlags(const char*cmd, PyCOmpilerFlags *flags)
		//
		//file(FILE *fp, const char*filename),
		//fileEx(FILE *fp, const char*filename),
		//fileExFlags(FILE *fp, const char*filename);
	};
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
};
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@namespace compile
///@brief generating python compiled strings
///
namespace compile{
	//PyObject 
		//*stringFlags(const char *str, const char*filename, int start, PyCompilerFlags* flags),
		//*stringExFlags(const char *str, const char*filename, int start, PyCompilerFlags* flags),
		//*stringObject(const char *str, const char*filename, int start, PyCompilerFlags* flags, int opimize);
};
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@namespace parser
///@brief python string and file parser interface
///
namespace parser{
	namespace parseSimple{
		//PyObject
			//*string(const char *str, int start),
			//*stringFlags(const char *str, int start),
			//*stringFlagsFilename(const char *str, int start),
			//
			//*file(FILE *fp, const char *filename, int start),
			//*fileFlags(FILE *fp, const char *filename, int start);
	};
};
NS_END
///
///@}
///
#endif