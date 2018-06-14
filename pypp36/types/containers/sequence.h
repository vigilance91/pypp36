//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file sequence.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python sequence object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_SEQUENCE_H
#define PYPP_SEQUENCE_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "../object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python Sequence Type Wrapper
///@ingroup py
///@{
///
struct sequence sealed
:   public object
{
	sequence(PyObject* pySequence);
    
	virtual ~sequence(){
    }
    
	PyObject
		*operator [](const unsigned& index),
		*getSlize(Py_ssize_t i1, Py_ssize_t i2);
    //int setItem(Py_ssize_t i, PyObject* o){ return PySequence_SetItem(_ptr, i, o); }
    //int deleteItem(Py_ssize_t i){ return PySequence_delItem(_ptr, i); }
    //you are responsible for Py_DECREF'ing the return
    //PyObject* concat(){}
    //return size of sequence, or -1 on failure
	Py_ssize_t size();
    //-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
    //"casting" operators
    //-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
    //pxpyTuple asTuple(){ return PySequence_Tuple(_ptr); }
    //pxpyList asList(){ return PySequence_List(_ptr); }

    //explicit pxpyTuple operator(){}
    //explicit pxpyList operator(){}
};
///
///@}
///
NS_END
#endif