//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file number.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python number object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_NUMBER_H
#define PYPP_NUMBER_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "../object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//bitwiseInterface
    //<<
    //>>
    //|
    //&
    //^
    //!
    //~
    //compound
    //<<=
    //>>=
    //|=
    //&=
    //^=
    //!=
    //~=
//};

///
///@brief Python Number wrapper
///@ingroup py
///@{
///
struct number sealed
:   public object
{
	number(PyObject* pyNumber);
    virtual ~number(){
    }
    //cast operator
	PyObject *asLongObj();
	PyObject *asFloatObj(PyObject *o);
	//overloaded arithmetic operators
	PyObject* operator +(const number& rhs);
	PyObject* operator -(const number& rhs);
	PyObject* operator *(const number& rhs);
    //prefix ........ +o
    //prefix negation -o

    //L && R shift operators

    //bitwise operations

    //casting operators

    //static PyObject* operator /(const pxpyNumber& rhs){
    //    return PyNumber_Div(this->get(), rhs.get() );   //returns ref to new pyObject
    //}
    //PyObject* abs(){ return PyNumber_Absolute(_ptr); }
};
///
///@}
///
NS_END
#endif