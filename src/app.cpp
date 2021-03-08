#include <iostream>
#include "./public/Matrix.h"

int main() {

  // Matrix m(3, 2);
  // m.print();

  int rows;
  int cols;
  int initial_value;

  do {
    std::cout << "Insert how many rows: ";
    std::cin >> rows;
  }while(rows <= 0);
  
  do {
    std::cout << "Insert how many cols: ";
    std::cin >> cols;
  }while(cols <= 0);

  std::cout << "Insert initial value for each cells";
  std::cin >> initial_value;

  Matrix m(rows, cols);

  m.print();

  std::cout << "Hello World";

}