#include <iostream>

int main(){
  int x=10;
  int* p=&x;
  int t=56;
  int* q=p+1;
  int** (pp)=&p;

  *p=20;
  std::cout << p << '\n';
  std::cout << *pp << '\n';
  std::cout << q << '\n';
  std::cout << x << '\n';


  return 0;
}
