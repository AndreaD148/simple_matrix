#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "public/Matrix.h"
#include <pybind11/operators.h>

// namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(first_test, m) {
  m.doc() = "TEST C++ IMPLEMENTATION";
  m.def("add", &add, "A function which add two numbers");

  pybind11::class_<Matrix> (m, "Matrix")
    .def(pybind11::init<int, int>())
    .def(pybind11::init<int, int, int>())
    .def(pybind11::init< int, int, std::vector<int> >())
    .def("print", &Matrix::print)
    .def("__mul__", [](Matrix first, Matrix second) {
      return first * second;
    })
    .def("__add__", [](Matrix first, Matrix second) {
      return first + second;
    });

}

