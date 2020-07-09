#include <iostream>
#include <cstdio>
#include <thread>

void use_printf(){  //use printf and scanf for faster input-output
  printf("%s\n","Hello world" );
  std::cout << "Hello world from cout" << '\n';

}

int main(){
  int* _array;
  auto f0=[&_array]() mutable{
    _array=new int[6];
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  };
  //auto length=*(&array+1)-array;
  //std::cout << length<< '\n';
  std::thread t(f0);
  t.join();
  //t.join();
  auto length=sizeof(_array);
  std::cout << length << '\n';
  //std::cout << id << '\n';
  return 0;
}
