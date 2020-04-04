#include <iostream>
#include "Cube.h"

int main(){
  uiuc::Cube c;
  c.setLength(2.4);
  std::cout << "volume=" <<c.getVolume()<< '\n';
  std::cout << "surface area" <<c.getSurfaceArea()<< '\n';
  return 0;
}
