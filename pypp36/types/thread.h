//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
///
///@file thread.h
///@author Tyler R. Drury
///@copyright (C) May 30 2013-present, Tyler R. Drury. All Rights Reserved.
///@brief wrapper for Python thread object
///@warning Do to an issue with the Python Source, the gil is not released when importing the threading library, do not use.
///
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#ifndef PYPP_THREAD_H
#define PYPP_THREAD_H
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
#include "object.h"
//-~~--~-~-~~~-~--~~~-~~-~~~~~~~---~~--~-~-~~~-~--~~~-~~-~~~~~~~
PY_NS_BEGIN
///
///@brief Python Thread Type Wrapper
///@ingroup py
///@{
///
struct thread sealed
:   public object
{
    thread()
    :   object(nullptr){
    }
    virtual ~thread(){
    }
    //PyLockStatus acquire_lock_timed(
    //    PyThread_type_lock,
    //    PY_TIMEOUT_T microseconds,
    //    int intr_flag
    //);

    //static void release_lock(PyThread_type_lock);

    //static const size_t get_stacksize(void){
    //    return PyThread_get_stacksize();
    //}
    //static int set_stacksize(const size_t size){
    //    return Pythread_set_stacksize(size);
    //}
    //
    //Thread Local Storage (TLS) API
    static int
        create_key(void),
        set_key_value(int, void *);

    static void
        delete_key(int),
        delete_key_value(int),
        *get_key_value(int),            
        //Cleanup after a fork
        reInitTLS(void);
};
///
///@}
///
NS_END
#endif