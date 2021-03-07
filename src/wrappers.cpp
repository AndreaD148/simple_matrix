#include <pybind11/pybind11.h>
#include "public/Matrix.h"

// namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(first_test, m) {
  m.doc() = "TEST C++ IMPLEMENTATION";
  m.def("add", &add, "A function which add two numbers");

  pybind11::class_<Matrix>(m, "Matrix")
    .def(pybind11::init<unsigned, unsigned>())
    .def("print", &Matrix::print); 

}

