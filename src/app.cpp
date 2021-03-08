#include <iostream>
#include "./public/Matrix.h"

int main() {

  // Matrix m(3, 2);
  // m.print();

  int rows;
  int cols;
  int initial_value;
  int scalar;

  do {
    std::cout << "Insert how many rows: ";
    std::cin >> rows;
  }while(rows <= 0);
  
  do {
    std::cout << "Insert how many cols: ";
    std::cin >> cols;
  }while(cols <= 0);

  std::cout << "Insert initial value for each cell: ";
  std::cin >> initial_value;

  Matrix m(rows, cols, initial_value);

  //print initial matrix
  m.print();

  //initialize scalar number
  // std::cout << "\nInsert a scalar number: ";
  // std::cin >> scalar;

  // Matrix scalar_sum = m + scalar;

  // std::cout << "\nScalar sum:\n";
  // scalar_sum.print();

  // std::cout << "\nScalar mul:\n";
  // Matrix scalar_mul = m * scalar;
  // scalar_mul.print();

  // SECOND MATRIX
  do {
    std::cout << "Insert rows for second matrix: ";
    std::cin >> rows;
  }while(rows <= 0);
  
  do {
    std::cout << "Insert columns for second matrix: ";
    std::cin >> cols;
  }while(rows <= 0);

  std::cout << "Insert the value for each cell: ";
  std::cin >> initial_value;

  Matrix second_matrix(rows, cols, initial_value);

  std::cout << "Second matrix:" << std::endl;
  //print of the second matrix
  second_matrix.print();

  // TEST OPERATIONS BETWEEN TWO MATRIX
  // - test sum of tow matrix
  Matrix matrix_sum = m + second_matrix;
  
  // - test diff between two matrix
  Matrix matrix_diff = m - second_matrix;

  std::cout << "Matrix sum:\n";
  matrix_sum.print();

  std::cout << "\n\nMatrix diff:\n";
  matrix_diff.print();


  // std::cout << "Hello World";

}