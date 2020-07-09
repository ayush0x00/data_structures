#include <iostream>

class search{
public:
  search(int* array,int element):_array(array),_element(element){
    std::cout << "Constructor called--array initialised " << '\n';
    _length=sizeof(_array)/sizeof(_array[0]);
    std::cout << "length of array is " <<_length<< '\n';
  }
  int linear_search(){
    std::cout << "linear search called" << '\n';
    for(int i=0;i<_length;i++){
      std::cout << "PASS " <<i+1<<'\n';
      if(_array[i]==_element){
        return i+1;
      }
    }
    return 0;
  }
private:
  int* _array;
  int _element;
  int _length;
};

int main(){
  int* my_array=new int[5]{1,2,3,4,5};
  search obj1=search(my_array,4);
  std::cout << obj1.linear_search() << '\n';
  return 0;
}
