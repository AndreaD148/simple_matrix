#include "../public/Matrix.h"

//define easy constructor
Matrix::Matrix(unsigned rowSize, unsigned colSize) {

  this->m_rowSize = rowSize;
  this->m_colSize = colSize;

  //initialize our vector
  this->m_matrix.resize(rowSize);

  for(int i = 0; i < this->m_matrix.size(); i++) {
    this->m_matrix[i].resize(colSize, 0);
  }

}

void Matrix::print() const {
  for(int i = 0; i < this->m_matrix.size(); i++) {
    for(int j = 0; j < this->m_matrix[i].size(); j++) {
      // std::cout<<"element in position <" << i << ", " << j << ">: " << this->m_matrix[i][j];
      std::cout << this->m_matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}