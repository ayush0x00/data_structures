#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

char alchemy_stone(string& alchemy){
  //while(alchemy.size()!=1){
    //int a=0,b=0;
    string str="";
    for(int i=0;i<alchemy.length();){
      //std::cout << "------length of alchemy------" <<alchemy.length()<< '\n';
      if(alchemy.length()==1)
        return 'Y';
      str=alchemy.substr(i,3);
      //std::cout << "value of alchemy=" << '\t'<<alchemy<<"\n";
      //std::cout << "value of str=" << '\t'<<str<<"\n";
      int a=count(str.begin(),str.end(),'A');
      int b=count(str.begin(),str.end(),'B');
      if(a==3||b==3){
        if(alchemy.length()<=3)
          return 'N';
        else{
          i++;
          continue;
        }
      }
      else if(b==2){
        alchemy.push_back('B');
        alchemy.erase(i,3);
        //std::cout << "value of alchemy after operation=" <<"\t"<<alchemy<< '\n';
        i=0;
      }
      else if(a==2){
        alchemy.push_back('A');
        alchemy.erase(i,3);
        //std::cout << "value of alchemy after operation=" <<"\t"<<alchemy<< '\n';
        i=0;
      }
    }
}

int main(){
  ifstream input("alchemy_input.txt");
  ofstream output("alchemy_solution.txt");
  int test;
  input>>test;
  for(int j=0;j<test;j++){
    output<<"Case #"<<j+1<<":"<<" " ;
    int frag_size;
    input>>frag_size;
    string alchemy;
    input>>alchemy;
    char ch=alchemy_stone(alchemy);
    output<<ch<<"\n";
    //std::cout << '\n';
  }
  return 0;
}
