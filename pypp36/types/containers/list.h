//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file list.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python list object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_LIST_H
#define PYPP_LIST_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief python list type
///@ingroup py
///@{
///
struct list sealed
:   public py::object
{
	list(PyObject* list);
    virtual ~list(){
    }
    //lists created with this function MUST be decRef'ed before deconstruction
    //static PyObject* make//PyList_New(Py_ssize_t size){return PyList_new(size); }
	Py_ssize_t size()const;

	PyObject* operator [](const unsigned index);
    
	PyObject* getSlice(
		Py_ssize_t begin,
		Py_ssize_t end
	);

	int 
		//insert(PyObject *, Py_ssize_t, PyObject *){ return PyList_Insert(_ptr, index, );}
		setItem(
			Py_ssize_t index,
			PyObject *item
		),
		append(PyObject *item),
		setSlice(
			Py_ssize_t begin,
			Py_ssize_t end,
			PyObject *item
		),
		sort(),
		reverse();

	static PyObject *asTuple(PyObject* ptr);
    //tuple asTuple(){return tuple(asTuple(_ptr) );}
//#ifndef Py_LIMITED_API
        //PyObject* _extend(PyListObject *, PyObject *);
//#endif

/* Macro, trading safety for speed */
//#ifndef Py_LIMITED_API
//    #define PyList_GET_ITEM(op, i) (((PyListObject *)(op))->ob_item[i])
//    #define PyList_SET_ITEM(op, i, v) (((PyListObject *)(op))->ob_item[i] = (v))
//    #define PyList_GET_SIZE(op)    Py_SIZE(op)
//#endif
};
///
///@}
///
NS_END
#endif