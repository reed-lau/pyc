#include <Python.h> 

static PyObject *func1(PyObject *self, PyObject *args) {
  Py_RETURN_NONE;
}

static PyObject *func2(PyObject *self, PyObject *args) {
  PyObject arg1, arg2;
  int ret = PyArg_ParseTuple(args, "O|O", &arg1, &arg2);
  printf("ret = %d\n", ret);
  Py_RETURN_NONE;
}

static PyObject *func3(PyObject *self, PyObject *args) {
  Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"func1", func1, METH_NOARGS,  "help doc about func1"},
    {"func2", func2, METH_VARARGS, "help doc about func2"},
    {"func3", func3, METH_VARARGS | METH_KEYWORDS, "help doc about func2"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "pyc",
    NULL,
    -1,
    methods
};

void PyInit_pyc(void) {
    PyModule_Create(&module);
}
