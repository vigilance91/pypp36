//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file tuple.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python tuple object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_TUPLE_H
#define PYPP_TUPLE_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@brief Python Tuple Type Wrapper
///@ingroup py
///@{
///
struct tuple sealed
:   public object
{
	tuple(PyObject* pyTuple);
    
    virtual ~tuple(){
    }
    //PyAPI_FUNC(PyObject *) PyTuple_New(Py_ssize_t size);
	Py_ssize_t size()const;

	PyObject //getItem
		*operator [](const Py_ssize_t index)const;
	
	int
		setItem(Py_ssize_t size, PyObject* ob);
	
	PyObject
		*getSlice(Py_ssize_t begin, Py_ssize_t end);
    //#ifndef Py_LIMITED_API
    //int _resize(PyObject **, Py_ssize_t){
    //}
    //#endif
    //PyObject* pack(Py_ssize_t, ...){PyTuple_Pack();}
    //#ifndef Py_LIMITED_API
    //void _MaybeUntrack(){
        //_PyTuple_MaybeUntrack(_ptr);
    //}
    //#endif

    /* Macro, trading safety for speed */
    //#ifndef Py_LIMITED_API
    //#define PyTuple_GET_ITEM(op, i) (((PyTupleObject *)(op))->ob_item[i])
    //#define PyTuple_GET_SIZE(op)    Py_SIZE(op)
    ///* Macro, *only* to be used to fill in brand new tuples */
    //#define PyTuple_SET_ITEM(op, i, v) (((PyTupleObject *)(op))->ob_item[i] = v)
    //#endif

	static int clearFreeList(void);
};
///
///@}
///
NS_END
#endif