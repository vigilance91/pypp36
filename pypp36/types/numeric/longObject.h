//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file longObject.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python long object
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_LONG_OBJECT_H
#define PYPP_LONG_OBJECT_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "../object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python long object
///@ingroup py
///@{
///
struct longObject sealed
:   public object   //px::py::numeric
{
    explicit longObject(PyObject* pyLong)
    :   object(pyLong){   //numeric
    }
    //explicit longObject(long l)
    //:   pxpyObject(nullptr){
        //_ptr = fromLong(l);
    //}
    virtual ~longObject(){
    }
    static PyObject *fromLong(long l){
        //creates new python long object
        return PyLong_FromLong(l);
    }
    static PyObject *fromUnsignedLong(unsigned long){
    }
    //static PyObject *fromSize_t(size_t size){
        //return PyLong_FromSize_t(size);   //new ref
    //}
    //static PyObject *fromSsize_t(Py_ssize_t size){
        //return PyLong_FromSsize_t(size);
    //}
    //static PyObject *fromDouble(double d){
        //return PyLong_FromDouble(d);
    //}

    long asLong(){
        return PyLong_AsLong(_ptr);
    }
    //long PyLong_AsLongAndOverflow(int *overflow){
        //return PyLong_AsLongAndOverflow(_ptr, overflow);
    //}
    
    //Py_ssize_t asSsize_t(){
        //return PyLong_AsSsize_t(_ptr);
    //}
    size_t asSize_t(){
        return PyLong_AsSize_t(_ptr);
    }
    unsigned long asUnsignedLong(){
        return PyLong_AsUnsignedLong(_ptr);
    }
    unsigned long asUnsignedLongMask(){
        return PyLong_AsUnsignedLongMask(_ptr);
    }
    static PyObject *getInfo(){
        return PyLong_GetInfo();   //new ref
    }
   /* _PyLong_Frexp returns a double x and an exponent e such that the
   true value is approximately equal to x * 2**e.  e is >= 0.  x is
   0.0 if and only if the input is 0 (in which case, e and x are both
   zeroes); otherwise, 0.5 <= abs(x) < 1.0.  On overflow, which is
   possible if the number of bits doesn't fit into a Py_ssize_t, sets
   OverflowError and returns -1.0 for x, 0 for e. */
#ifndef Py_LIMITED_API
    //double _frexp(Py_ssize_t *e){
        //return _PyLong_Frexp(_ptr, e);
    //}
#endif

    double asDouble(){
        return PyLong_AsDouble(_ptr);
    }
    //static PyObject *fromVoidPtr(void *ptr){
        //return PyLong_FromVoidPtr(ptr);
    //}
    //void *asVoidPtr(){
        //return PyLong_AsVoidPtr(_ptr);
    //}

#ifdef HAVE_LONG_LONG
    //static PyObject *fromLongLong(PY_LONG_LONG ll){
    //    return PyLong_FromLongLong(ll);
    //}
    //static PyObject *fromUnsignedLongLong(unsigned PY_LONG_LONG ull){
    //    return PyLong_FromUnsignedLongLong(ull);
    //}
    //getters
    PY_LONG_LONG asLongLong(){
        return PyLong_AsLongLong(_ptr);
    }
    unsigned PY_LONG_LONG asUnsignedLongLong(){
        return PyLong_AsUnsignedLongLong(_ptr);
    }
    unsigned PY_LONG_LONG asUnsignedLongLongMask(){
        return PyLong_AsUnsignedLongLongMask(ptr);
    }
    PY_LONG_LONG asLongLongAndOverflow(int *overflow){
        return PyLong_AsLongLongAndOverflow(_ptr, overflow);
    }
#endif /* HAVE_LONG_LONG */

    //static PyObject * fromString(char *str, char **ary, int i){
        //return PyLong_FromString(str, ary, i);
    //}
#ifndef Py_LIMITED_API
    static PyObject * fromUnicode(
        /*wchar_t*/Py_UNICODE *puo,
        Py_ssize_t size,
        int i
    ){
        return PyLong_FromUnicode(puo, size, i);
    }
#endif

#ifndef Py_LIMITED_API
    /* _PyLong_Sign.  Return 0 if v is 0, -1 if v < 0, +1 if v > 0.
       v must not be NULL, and must be a normalized long.
       There are no error cases.
    */
    int _sign(){
        return _PyLong_Sign(_ptr);
    }
    /* _PyLong_NumBits.  Return the number of bits needed to represent the
       absolute value of a long.  For example, this returns 1 for 1 and -1, 2
       for 2 and -2, and 2 for 3 and -3.  It returns 0 for 0.
       v must not be NULL, and must be a normalized long.
       (size_t)-1 is returned and OverflowError set if the true result doesn't
       fit in a size_t.
    */
    size_t _numBits(){
        return _PyLong_NumBits(_ptr);
    }
    /* _PyLong_DivmodNear.  Given integers a and b, compute the nearest
       integer q to the exact quotient a / b, rounding to the nearest even integer
       in the case of a tie.  Return (q, r), where r = a - q*b.  The remainder r
       will satisfy abs(r) <= abs(b)/2, with equality possible only if q is
       even.
    */
    //PyObject * _divModNear(PyObject *po){
    //    return _PyLong_DivmodNear(_ptr, po);
    //}

    /* _PyLong_FromByteArray:  View the n unsigned bytes as a binary integer in
       base 256, and return a Python long with the same numeric value.
       If n is 0, the integer is 0.  Else:
       If little_endian is 1/true, bytes[n-1] is the MSB and bytes[0] the LSB;
       else (little_endian is 0/false) bytes[0] is the MSB and bytes[n-1] the
       LSB.
       If is_signed is 0/false, view the bytes as a non-negative integer.
       If is_signed is 1/true, view the bytes as a 2's-complement integer,
       non-negative if bit 0x80 of the MSB is clear, negative if set.
       Error returns:
       + Return NULL with the appropriate exception set if there's not
         enough memory to create the Python long.
    */
    //static PyObject *_fromByteArray(
	   // const unsigned char* bytes,
    //    size_t n,
	   // int little_endian,
    //    int is_signed
    //){
    //    return _PyLong_FromByteArray(bytes, n, little_endian, is_signed);
    //}

    /* _PyLong_AsByteArray: Convert the least-significant 8*n bits of long
       v to a base-256 integer, stored in array bytes.  Normally return 0,
       return -1 on error.
       If little_endian is 1/true, store the MSB at bytes[n-1] and the LSB at
       bytes[0]; else (little_endian is 0/false) store the MSB at bytes[0] and
       the LSB at bytes[n-1].
       If is_signed is 0/false, it's an error if v < 0; else (v >= 0) n bytes
       are filled and there's nothing special about bit 0x80 of the MSB.
       If is_signed is 1/true, bytes is filled with the 2's-complement
       representation of v's value.  Bit 0x80 of the MSB is the sign bit.
       Error returns (-1):
       + is_signed is 0 and v < 0.  TypeError is set in this case, and bytes
         isn't altered.
       + n isn't big enough to hold the full mathematical value of v.  For
         example, if is_signed is 0 and there are more digits in the v than
         fit in n; or if is_signed is 1, v < 0, and n is just 1 bit shy of
         being large enough to hold a sign bit.  OverflowError is set in this
         case, but bytes holds the least-signficant n bytes of the true value.
    */
    //int _asByteArray(
	   // unsigned char* bytes, size_t n,
	   // int little_endian, int is_signed
    //){
    //    return PyLong_AsByteArray(_ptr, bytes, n, little_endian, is_signed);
    //}

    //_PyLong_Format: Convert the long to a string object with given base,
    //appending a base prefix of 0[box] if base is 2, 8 or 16. */
    //PyObject *_PyLong_Format(PyObject *aa, int base);

    //Format the object based on the format_spec, as defined in PEP 3101
    //(Advanced String Formatting)
    //PyObject *_PyLong_FormatAdvanced(
    //    PyObject *obj,
    //    Py_UNICODE *format_spec,
    //    Py_ssize_t format_spec_len
    //);
#endif /* Py_LIMITED_API */

    //These aren't really part of the long object, but they're handy. The
    //functions are in Python/mystrtoul.c.
    //PyAPI_FUNC(unsigned long) PyOS_strtoul(char *, char **, int);
    //PyAPI_FUNC(long) PyOS_strtol(char *, char **, int);
};
///
///@}
///
NS_END
#endif