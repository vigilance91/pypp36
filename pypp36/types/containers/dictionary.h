//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//pxpy\\dictionary.h, by Tyler R. Drury (C) May 30, 2013, All Rights Reserved
///
///@file dictionary.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python set object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_DICTIONARY_H
#define PYPP_DICTIONARY_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python Dictionary Type
///@ingroup py
///@{
///
struct dictionary
:	public py::object
{
	dictionary(PyObject* dict);
	
	virtual ~dictionary() {
		//this data structure does not release the underlying PyObject,
		//the calling programmer must call all approriate clean-up code
	}
	///index operator dict['key']
	PyObject* operator[](const NString& key)const;
	///index operator dict[]
	PyObject* operator[](PyObject* key)const;
	
	PyObject
		///return all keys
		*gKeys()const,
		///return all values
		*gValues()const;

	///number of entries within dictionary
	Py_ssize_t size()const;
	//
	//these methods return -1 on error, 0 on failure and 1 on success
	//
	int update(PyObject* other),
		///does this dictionary contain keys that are only strings
		hasOnlyStringKeys()const,
		///combine contents of
		merge(PyObject *other, int or ),
		///check if key exists within dictionary
		contains(PyObject* key)const;
};
///
///@}
///
NS_END
#endif