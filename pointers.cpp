#include <iostream>
int main(int argc, char const *argv[]) {
  int* p=new int;
  std::cout << "address of heap" <<p<< '\n';
  *p=56;
  std::cout << "value in heap" <<*p<< '\n';
  delete p;
  p=nullptr;
  *p=78;//will give segmentation fault
  std::cout << "value in heap" <<*p<< '\n';
  return 0;
}
