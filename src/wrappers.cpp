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
    .def("transpose", &Matrix::transpose)
    .def("two_by_two_determinant", &Matrix::two_by_two_determinant)
    .def("sarrus", &Matrix::sarrus)
    .def("get_determinant", &Matrix::get_determinant)
    .def("__mul__", [](Matrix first, Matrix second) {
      return first * second;
    })
    .def("__mul__", [](Matrix first, int scalar) {
      return first * scalar;
    })
    .def("__add__", [](Matrix first, Matrix second) {
      return first + second;
    })
    .def("__sub__", [](Matrix first, Matrix second) {
      return first - second;
    });

}

