#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int savkono(std::vector<int> soldier_power,int pain_strength){
    //std::cout << soldier_power[0] << '\n';
    int hit=0;
    while(pain_strength>0 && !soldier_power.empty()){
      sort(soldier_power.begin(),soldier_power.end());
      std::cout <<"soldier_power = "<< soldier_power.back()<<" ";
      if(soldier_power.back()>0){
        std::cout << " current pain_strength = " <<pain_strength<< '\n';
        pain_strength-=soldier_power.back();
        soldier_power.back()/=2;
        ++hit;
      }
      else{
        soldier_power.pop_back();
      }
    }
    if(pain_strength>0){ =
      return 0;
    }
    else{
      return hit;
    }
}

int main(){
  std::vector<int> soldier_power={7,13,8,17,3};
  int result=savkono(soldier_power,25);
  if (result==0){
    std::cout << "EVACUATE" << '\n';
    return 0;
  }
  std::cout << result << '\n';
}
