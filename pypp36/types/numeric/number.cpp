#include "number.h"
//
//using namespace py::marshal;
typedef py::object pyObj;
typedef py::number num;
//
typedef PyObject *pyPtr;
//
num::number(
	pyPtr pyNumber
):	pyObj(pyNumber)
{
}
//cast operator
pyPtr num::asLongObj(){
	//creates new ref, copy of value held by _ptr
	return _ptr?PyNumber_Long(_ptr):0;
}
pyPtr num::asFloatObj(PyObject *o){
	//creates new ref, copy of value held by _ptr
	return _ptr?PyNumber_Float(_ptr):nullptr;
}
pyPtr num::operator +(const number& rhs){
	//|| asFloat(lhs) + asFloat(rhs);
	return PyNumber_Add(this->get(), rhs.get()); //preforms add in python
}
pyPtr num::operator -(const number& rhs){
	return PyNumber_Subtract(this->get(), rhs.get());
}
pyPtr num::operator *(const number& rhs) {
	return PyNumber_Multiply(this->get(), rhs.get());
}
//prefix ........ +o
//prefix negation -o

//L && R shift operators

//bitwise operations

//casting operators

//static pyPtr operator /(const pxpyNumber& rhs){
//    return PyNumber_Div(this->get(), rhs.get() );   //returns ref to new pyObject
//}
//pyPtr abs(){ return PyNumber_Absolute(_ptr); }