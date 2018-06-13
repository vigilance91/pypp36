//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file sys.h
///@author Tyler R. Drury
///@copyright (C) June 12 2018-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python error interface
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_SYS_H
#define PYPP_SYS_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "py.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//typedef PyObject* pyPtr;
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@namespace sys
///@brief Interface for Python sys module
///@ingroup py
///@{
///
namespace sys
{
	///
	///@return Borrowed reference, the object name from the sys module or NULL if it does not exist, without setting an exception.
	///
	extern PyObject *getObject(char *name);
	///
	///@brief Set name in the sys module to v unless v is NULL, in which case name is deleted from the sys module.
	///@return 0 on success, -1 on error
	///
	extern int setObject(char *name, PyObject *v);
		///Reset sys.warnoptions to an empty list.
	extern void
		resetWarnOptions(),
		///Append s to sys.warnoptions.
		addWarnOption(wchar_t *s),
		///Append unicode to sys.warnoptions.
		addWarnOptionUnicode(
			PyObject *unicode
		),
		///Set sys.path to a list object of paths found in path which should be a list of paths separated with the platform’s search path delimiter(: on Unix, ; on Windows).
		setPath(wchar_t *path);
	//namespace write{
		//void stdout(const char *format, ...){}
		//void stderr(const char *format, ...){}
	//};
};
///
///@}
///
NS_END
#endif