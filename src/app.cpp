#include <iostream>
#include "./public/Matrix.h"

int main() {

  // Matrix m(3, 2);
  // m.print();

  int rows;
  int cols;
  int initial_value;
  int scalar;

  // do {
  //   std::cout << "Insert how many rows: ";
  //   std::cin >> rows;
  // }while(rows <= 0);
  
  // do {
  //   std::cout << "Insert how many cols: ";
  //   std::cin >> cols;
  // }while(cols <= 0);

  // std::cout << "Insert initial value for each cell: ";
  // std::cin >> initial_value;

  // Matrix m(rows, cols, initial_value);

  // //print initial matrix
  // m.print();

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
  // do {
  //   std::cout << "Insert rows for second matrix: ";
  //   std::cin >> rows;
  // }while(rows <= 0);
  
  // do {
  //   std::cout << "Insert columns for second matrix: ";
  //   std::cin >> cols;
  // }while(rows <= 0);

  // std::cout << "Insert the value for each cell: ";
  // std::cin >> initial_value;

  // Matrix second_matrix(rows, cols, initial_value);

  // std::cout << "Second matrix:" << std::endl;
  // //print of the second matrix
  // second_matrix.print();

  // // TEST OPERATIONS BETWEEN TWO MATRIX
  // // - test sum of tow matrix
  // Matrix matrix_sum = m + second_matrix;
  
  // // - test diff between two matrix
  // Matrix matrix_diff = m - second_matrix;

  // std::cout << "Matrix sum:\n";
  // matrix_sum.print();

  // std::cout << "\n\nMatrix diff:\n";
  // matrix_diff.print();

  //test creation with different values
  
  // Matrix m1{2, 3};
  // m1.define_values();

  // m1.print();

  // Matrix m2{3, 2};
  // m2.define_values();
  // m2.print();

  // Matrix res = m1 * m2;

  // std::cout << "prodotto: \n";

  // res.print();

  std::vector<int> v(4);
  v = {1, 0, 0, 0};
  
  std::vector<int> v2(4);
  v2 = {0, 1, 0, 1};

  Matrix first{2, 2, v};
  
  std::cout << "First matrix:\n";
  first.print();

  Matrix second{2, 2, v2};

  std::cout << "\nSecond matrix:\n";
  second.print();

  Matrix prod = first * second;

  std::cout << "\nm1 * m2 = \n";
  prod.print();

  //SECOND TEST
  std::vector<int> v_a(6);
  v_a = {1, 2, 0, 0, 2, 3};

  std::vector<int> v_b(6);
  v_b = {2, 3, 4, 1, 0, 2};

  Matrix a{2, 3, v_a};
  std::cout << "\nA:\n";
  a.print();
  Matrix b{3, 2, v_b};

  std::cout << "\nB: \n";
  b.print();

  Matrix sec_prod = a * b;

  std::cout << "\nA * B:\n";
  sec_prod.print();

  //TEST TRASPOSE OPERATION
  std::vector<int> v_transpose(4);
  v_transpose = {1, 2, 3, 4};
  Matrix m_to_transpose{2, 2, v_transpose};

  std::cout << "Matrix before transposition: \n";
  m_to_transpose.print();

  Matrix transpose_matrix = m_to_transpose.transpose();

  std::cout << "\nMatrix after transposition:\n";
  transpose_matrix.print();
  std::cout << "\n";
  // std::cout << "Hello World";

  //TEST DETERMINANT
  std::vector<int> v_determinant(4);
  v_determinant = {1, 2, 3, 3};

  Matrix m_determinant{2, 2, v_determinant};

  m_determinant.print();

  //get initial value of determinant
  std::cout << "\nInitial value of determinant: " << m_determinant.get_determinant() << std::endl;

  m_determinant.two_by_two_determinant();

  std::cout << "Determinant after determinant calculation: " << m_determinant.get_determinant() << "\n";

  // m_determinant.two_by_two_determinant();
  // std::cout << "\ndeterminant of the last matrix is: " << m_determinant.get_determinant();

  //TEST SARRUS
  std::vector<int> v_sarrus(9);
  v_sarrus = {1, 0, 0, 0, 1, 0, 0, 0, 1};

  Matrix m_sarrus{3, 3, v_sarrus};
  
  std::cout << "Matrix 3*3: \n";
  m_sarrus.print();

  std::cout << "\nSarrus: \n";
  m_sarrus.sarrus();

  std::cout << "\nNow the determinant is: " << m_sarrus.get_determinant();


}