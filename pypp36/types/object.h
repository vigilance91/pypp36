//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file object.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python object interface
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_OBJECT_H
#define PYPP_OBJECT_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "../py.h"
#include "utils\\types.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief python attribute interface for getting and setting object values
///@ingroup py
///@{
///
struct iAttribute
{
    PyObject
        *getAttrString(const NString& str)const,
        *getAttr(PyObject *attr)const;
   
    virtual int
        setAttrString(const NString& str, PyObject* value) = 0,
        hasAttrString(const NString& str)const = 0,
        setAttr(PyObject* key, PyObject* value) = 0,
        hasAttr(PyObject* attr)const = 0;
};
//struct iCallable{};
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@brief generic python object wrapper, abstract base class
///@ingroup py
///@{
///
class object
//:   public pxpyAttributeInterface
{
protected:
    //if this object was created using new or copy,
    //_ptr should be Py_DECREF'ed, otherwise, the interpriter
    //is responsible for destorying the underlaying PyObject
    PyObject *_ptr;

    typedef void (py::object::*DeallocaterType)(void);

    //const DeallocaterType _dealloc; //can not change after instansiation

	object(PyObject* ptr = nullptr);   //dealloc = nullptr //assign to &pxpy::decRef for (this) to deallocate
    
	//object(object&& rhs)   //dealloc = nullptr //assign to &pxpy::decRef for (this) to deallocate
	//:	_ptr(std::move(rhs._ptr)){
	//	//efficiently move a pointer to a python object to another instances
	//	//after executing,
	//	//the original obj._ptr is invalid but not null or undefined,
	//	//but since obj is a temporary r-value it does not matter as it will be deallocated after its internals have been moved
	//}
	//object& object::operator=(object&& rhs){
	//	if(this->_ptr){
	//	}
		//this->_ptr = std::move(rhs._ptr);
		//return *this;
	//}
public:
    virtual ~object(){
        //if(_ptr && _dealloc)
            //(*this).(*_dealloc)();
    }
	//move assignment


    PyObject
		*get()const,
		*getAttrString(const NString& str)const,
		*getAttr(PyObject* attr)const;
    
	int 
		setAttrString(
			const NString& str,
			PyObject* value
		),
		hasAttrString(
			const NString& str
		)const,
		setAttr(
			PyObject* key,
			PyObject* value
		),
		hasAttr(PyObject* attr)const,
		isCallable()const;

    void clearWeakRefs(),
		///
		///@brief increment the reference count for object o.
		///@note _ptr must not be NULL. If it is unsure whether NULL, use xIncRef().
		///
		incRef(),
		///Increment the reference count, if _ptr is NULL, call has no effect
		xIncRef(),
		///
		///@brief Decrement the reference count
		///@note _ptr must not be NULL. If it is unsure whether NULL, use xDecRef().
		///
		decRef(),
		xDecRef(),
		clear();
    //postfix operator++(){
        //short-hand for incRef
    //}
    //postfix operator--(){
        //short-hand for decRef
    //}
   // PyObject* operator ()(char *method, char *format, ...){
   //     va_list vaargs;
   //     va_start(vaargs, format);
   //     
   //     PyObject * ret = PyObject_CallMethod(_ptr, method, format, vaargs);

   //     va_end(vaargs);

   //     return ret;
   // }
};
///
///@}
///
NS_END
#endif