//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file unicode.h
///@author Tyler R. Drury
///@copyright (C) May 30, 2013-2018, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python module object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_UNICODE_H
#define PYPP_UNICODE_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@brief Python unicode object
///@details repressents a unicode string in python, use as keys to dictionaries
///@ingroup py
///@{
///
struct unicode sealed
:   public object
{
	unicode(PyObject* pyUnicode);
    
    virtual ~unicode(){
    }
    //
    //operator +(){
        //PyUnicode_Concat(_ptr,
    //}
    //WString asUnicode()const{
    //}
    //
    //casting
    //
    //operator WString(){ return PyUnicode_AsUnicode(_ptr); }
};
///
///@}
///
NS_END
#endif