#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int savkono(std::vector<int> soldier_power,int pain_strength){
    int hit=0;
    while(pain_strength<=0||soldier_power.empty()){
      sort(soldier_power.begin(),soldier_power.end());
      if(soldier_power[0]>0){
        pain_strength-=soldier_power[0];
        soldier_power[0]/=2;
        ++hit;
      }
      else{
        soldier_power.erase(soldier_power.begin());
      }
    }
    if(pain_strength>0){
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
