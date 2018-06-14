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
    number(PyObject* pyNumber)
    :   object(pyNumber){
    }
    ~number(){
    }
    //cast operator
    PyObject *asLongObj(){
        //creates new ref, copy of value held by _ptr
        return PyNumber_Long(_ptr);
    }
    PyObject *asFloatObj(PyObject *o){
        //creates new ref, copy of value held by _ptr
        return PyNumber_Float(_ptr);
    }
    PyObject* operator +(const number& rhs){
        //|| asFloat(lhs) + asFloat(rhs);
        return PyNumber_Add(this->get(), rhs.get() ); //preforms add in python
    }
    PyObject* operator -(const number& rhs){
        return PyNumber_Subtract(this->get(), rhs.get() );
    }
    PyObject* operator *(const number& rhs){
        return PyNumber_Multiply(this->get(), rhs.get() );
    }
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