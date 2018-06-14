//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file module.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python module object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_MODULE_OBJECT_H
#define PYPP_MODULE_OBJECT_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//#define PXPY_API(returnType) inline returnType
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief module object interface
///@ingroup py
///@{
///
class module
:   public object
{
public:
    //this method calls PyImport_ImportModule,
    //it is owned by the runing interpriter
    //and does not need to be decRef()'ed
    static module import(
        const NString& name/* UTF-8 encoded string, */
    );
    //caller is responsible for decRef()'ing these objects
	explicit module(const NString& name);

	virtual ~module(){
	}
	//
	NString
		getName(),
		getFilename()const;
    
	PyObject
		*getDict(),	///< get module's dictionary
		*getFilenameObject()const;

	struct PyModuleDef
		*getDef()const;

	void
		*getState()const;

#ifndef Py_LIMITED_API
	void clear()const;
#endif
};
///
///@}
///
NS_END
#endif