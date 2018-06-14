//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file set.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python set object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_SET_H
#define PYPP_SET_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python Set Type Wrapper
///@ingroup py
///@{
///

struct set sealed
:   public object
{
	set(PyObject* pySet);

    virtual ~set(){
    }
            
    //static PyObject *make();    //PySet_New(PyObject *);
    //static PyObject * makeFrozenSet(PyObject *);
	Py_ssize_t size()const;
	
	int clear(),
		contains(PyObject *key),
		discard(PyObject *key),
		add(PyObject *key);

	PyObject* pop();

#ifndef Py_LIMITED_API
    //#define PySet_GET_SIZE(so) (((PySetObject *)(so))->used)
    //int _nextEntry(Py_ssize_t *pos, PyObject **key, Py_hash_t *hash){}
    //int _update(PyObject *iterable){
    //    return PySet_Update(_ptr, iterable);
    //}
#endif
};
///
///@}
///
NS_END
#endif