//This code demonstrates how to use friend function to multiply a matrix and vector
#include<iostream>
#include<vector>

class create_matrix;
class create_vector{
public:
  create_vector(std::vector<int> v):_vector(v){
    std::cout << "Vector created with elements as follows " << '\n';
    for(auto it=_vector.begin();it!=_vector.end();it++)
    std::cout << *(it) << " ";
    std::cout << '\n';
  }
  friend std::vector<int> multiply(const std::vector<int> &v, const create_matrix &obj);
private:
  std::vector<int> _vector;
};

class create_matrix{
public:
  create_matrix(std::vector<std::vector<int>> v):_matrix(v){
    std::cout << "Matrix created with elements as follows " << '\n';
    for (auto it=_matrix.begin();it!=_matrix.end();it++){
      for(auto it_columns=it->begin();it_columns!=it->end();it_columns++)
        std::cout << *(it_columns) <<" ";
      std::cout <<'\n';
    }
  }
    friend std::vector<int> multiply(const std::vector<int> &v, const create_matrix &obj);
  private:
    std::vector<std::vector<int>> _matrix;
};

int main(){
  create_vector myVect({1,2,3});
  //std::cout <<'\n';
  create_matrix myMat({{1,3,4},{2,6,7},{3,5,6}});
  return 0;
}
