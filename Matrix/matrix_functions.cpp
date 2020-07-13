#include <iostream>

class Matrix{
public:
  Matrix(int rows,int columns):_rows(rows),_columns(columns){
    std::cout << "Matrix constructor called with dimensions " <<_rows<<"x"<<_columns<< '\n';
  }
  
}
