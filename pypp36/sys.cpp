#include "sys.h"
#include <Python.h>
//
using namespace py;
//
PyObject *sys::getObject(char *name) {
	return PySys_GetObject(name);
}
///
///@brief Set name in the sys module to v unless v is NULL, in which case name is deleted from the sys module.
///@return 0 on success, -1 on error
///
int sys::setObject(char *name, PyObject *v) {
	return PySys_SetObject(name, v);
}
///Reset sys.warnoptions to an empty list.
void sys::resetWarnOptions(){
	PySys_ResetWarnOptions();
}
///Append s to sys.warnoptions.
void sys::addWarnOption(wchar_t *s) {
	PySys_AddWarnOption(s);
}
///Append unicode to sys.warnoptions.
void sys::addWarnOptionUnicode(
	PyObject *unicode
) {

}
///Set sys.path to a list object of paths found in path which should be a list of paths separated with the platform’s search path delimiter(: on Unix, ; on Windows).
void sys::setPath(wchar_t *path) {
	Py_SetPath(path);
}
//namespace write{
//void stdout(const char *format, ...){}
//void stderr(const char *format, ...){}
//};