#include <iostream>
#include "./public/Matrix.h"

int main() {

  // Matrix m(3, 2);
  // m.print();

  unsigned int rows;
  unsigned int cols;

  do {
    std::cout << "Insert how many rows: ";
    std::cin >> rows;
  }while(rows == 0);
  
  do {
    std::cout << "Insert how many cols: ";
    std::cin >> cols;
  }while(cols == 0);

  Matrix m(rows, cols);

  m.print();

  std::cout << "Hello World";

}