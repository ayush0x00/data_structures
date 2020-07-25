#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

char alchemy_stone(stack<char>& alchemy){
  while(alchemy.size()!=1){
    int a=0,b=0;
    string str="";
    for(int i=0;i<3;i++){
      str[i]=alchemy.top();
      alchemy.pop();
    }
    for(int i=0;i<3;i++){
      if(str[i]=='A')
        a++;
      else if(str[i]=='B')
        b++;
    }
    if(a==2)
      alchemy.push('A');
    else if(b==2)
      alchemy.push('B');
    else if(alchemy.size()==3)
      return 'N';
  }
  return 'Y';
}

int main(){
  ifstream input("alchemy_sample_input.txt");
  ofstream output("alchemy_solution.txt");
  int test;
  input>>test;
  for(int j=0;j<test;j++){
    output<<"Case #"<<j+1<<":"<<"\t";
    int frag_size;
    input>>frag_size;
    stack<char> alchemy;
    string temp;
    input>>temp;
    for(int i=0;i<frag_size;i++)
      alchemy.push(temp[i]);
    cout<<alchemy_stone(alchemy)<<"\n";
    //std::cout << '\n';
  }
  return 0;
}
