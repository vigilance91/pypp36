//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file floatObject.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python float object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_FLOAT_OBJECT_H
#define PYPP_FLOAT_OBJECT_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "../object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python float object
///@ingroup py
///@{
///
struct floatObject sealed
:   public object   //px::py::numeric
{
    explicit floatObject(PyObject* pyFloat)
    :   object(pyFloat){   //numeric
    }
    //explicit longObject(long l)
    //:   pxpyObject(nullptr){
        //_ptr = fromLong(l);
    //}
    virtual ~floatObject(){
    }
    static double getMax(){
        return PyFloat_GetMax();
    }
    static double getMin(){
        return PyFloat_GetMin();
    }
    static PyObject *getInfo(){
        return PyFloat_GetInfo();
    }
    //
    //these functions return new references which much be decRef'ed before deallocation!
    //
    //static PyObject *fromString(PyObject*){
        //return Python float from string PyObject
    //    return PyFloat_FromString();
    //}
    static PyObject *fromDouble(double d){
        //return Python float from C double, new ref
        return PyFloat_FromDouble(d);
    }

    double asDouble(){
        //Extract C double from Python float, the macro version trades safety for speed
        return PyFloat_AsDouble(_ptr);
    }
#ifndef Py_LIMITED_API
    /* _PyFloat_{Pack,Unpack}{4,8}
    *
    * The struct and pickle (at least) modules need an efficient platform-
    * independent way to store floating-point values as byte strings.
    * The Pack routines produce a string from a C double, and the Unpack
    * routines produce a C double from such a string.  The suffix (4 or 8)
    * specifies the number of bytes in the string.
    *
    * On platforms that appear to use (see _PyFloat_Init()) IEEE-754 formats
    * these functions work by copying bits.  On other platforms, the formats the
    * 4- byte format is identical to the IEEE-754 single precision format, and
    * the 8-byte format to the IEEE-754 double precision format, although the
    * packing of INFs and NaNs (if such things exist on the platform) isn't
    * handled correctly, and attempting to unpack a string containing an IEEE
    * INF or NaN will raise an exception.
    *
    * On non-IEEE platforms with more precision, or larger dynamic range, than
    * 754 supports, not all values can be packed; on non-IEEE platforms with less
    * precision, or smaller dynamic range, not all values can be unpacked.  What
    * happens in such cases is partly accidental (alas).
    */

    /* The pack routines write 4 or 8 bytes, starting at p.  le is a bool
    * argument, true if you want the string in little-endian format (exponent
    * last, at p+3 or p+7), false if you want big-endian format (exponent
    * first, at p).
    * Return value:  0 if all is OK, -1 if error (and an exception is
    * set, most likely OverflowError).
    * There are two problems on non-IEEE platforms:
    * 1):  What this does is undefined if x is a NaN or infinity.
    * 2):  -0.0 and +0.0 produce the same string.
    */
    static int _pack4(double x, unsigned char *p, int le){
        return _PyFloat_Pack4(x, p, le);
    }
    static int _pack8(double x, unsigned char *p, int le){
        return _PyFloat_Pack8(x, p, le);
    }
    //needed for the old way for marshal to store a floating point number.
    //returns the string length copied into p, -1 on error.
    int _repr(double x, char *p, size_t len){
        return _PyFloat_Repr(x, p, len);
    }
    int _digits(char *buf, double v, int *signum){
        //Used to get the important decimal digits of a double
        return _PyFloat_Digits(buf, v, signum);
    }
    static void _digitsInit(){
        return _PyFloat_DigitsInit();
    }
    /* The unpack routines read 4 or 8 bytes, starting at p.  le is a bool
    * argument, true if the string is in little-endian format (exponent
    * last, at p+3 or p+7), false if big-endian (exponent first, at p).
    * Return value:  The unpacked double.  On error, this is -1.0 and
    * PyErr_Occurred() is true (and an exception is set, most likely
    * OverflowError).  Note that on a non-IEEE platform this will refuse
    * to unpack a string that represents a NaN or infinity.
    */
    static double _unpack4(const unsigned char *p, int le){
        return _PyFloat_Unpack4(p, le);
    }
    static double _unpack8(const unsigned char *p, int le){
        return _PyFloat_Unpack8(p, le);
    }

    //free list api
    static int _clearFreeList(){
        return PyFloat_ClearFreeList();
    }
    //PyObject *_formatAdvanced(
    //    Py_UNICODE *format_spec,
    //    Py_ssize_t format_spec_len
    //){
    //    //format the object based on the format_spec, as defined in PEP 3101
    //    return _PyFloat_FormatAdvanced(_ptr, format_spec, format_spec_len);
    //}
#endif /* Py_LIMITED_API */
};
///
///@}
///
NS_END
#endif