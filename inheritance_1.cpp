#include<iostream>
class getSquare{
public:
  getSquare(float n):number(n){}
  float computeSquare(const float &number){
    float square=number*number;
    return square;
  }
private:
  float number;
};

class getCube{
public:
  getCube(float n):number(n){}
  float computeCube(const float &number){
    float cube=number*number*number;
    return cube;
  }
private:
  float number;
};

class compute:public getSquare,public getCube{
public:
  compute(float number):_number(number),getCube(number),getSquare(number){
    std::cout << "float number initialized and ready for computation" << '\n';
  }
  void SquareValue(){
    std::cout << "SquareValue of number is " <<this->getSquare::computeSquare(_number)<< '\n';
  }
  void CubeValue(){
    std::cout << "Cube Value of number is " <<this->getCube::computeCube(_number)<< '\n';
  }
private:
  float _number;
};

int main(){
  compute value=compute(32.0);
  value.SquareValue();
  value.CubeValue();
  return 0;
}
