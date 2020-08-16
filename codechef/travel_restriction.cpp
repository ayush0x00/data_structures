#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
using namespace std;

bool probability(int i,int j, char incoming[],char outgoing[] ){
  if(outgoing[i]=='Y' && incoming[j]=='Y')
    return true;
  else
    return false;
}

int main(){
  ifstream input("final_input.txt");
  ofstream output("output.txt",std::ofstream::trunc);
  int test;
  input>>test;
  for(int j=0;j<test;j++){
    output<<"Case #"<<j+1<<":"<<"\n";
    int n;
    input>>n;
    char incoming[n],outgoing[n],possibility[n][n];
    //std::vector<std::vector<char>> possibility;
    //for(int i=0;i<n;i++)
      //possibility[i].resize(n);
    for(int i=0;i<n;i++)
      input>>incoming[i];
    for(int i=0;i<n;i++)
      input>>outgoing[i];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        possibility[i][j]='N';
    }
    //std::cout << "Inputs complete" << '\n';
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j)
          {
            possibility[i][j]='Y';
          //  std::cout << "possibility to travel from " <<i+1<<"\t"<<j+1<< " = "<<possibility[i][j]<< '\n';
          }
        else if(abs((i-j))==1 && outgoing[i]=='Y' && incoming[j]=='Y')
          {
            possibility[i][j]='Y';
            //std::cout << "possibility to travel from " <<i+1<<"\t"<<j+1<< " = "<<possibility[i][j]<< '\n';
          }
        else if(abs((i-j))!=1){
          if(i>j){
            int flag=0;
            int temp_i=i,temp_j=j;
            //std::cout << "----Checking possibility to travel from---- " <<i+1<<"\t"<<j+1<< '\n';
            while(temp_i>j){
              //std::cout << " possibility to travel from " <<temp_i+1<<"\t"<<temp_i<< " = "<<possibility[temp_i][temp_i-1]<< '\n';
              if(probability(temp_i,temp_i-1,incoming,outgoing)){
                //std::cout << "Positive possibility to travel from " <<temp_i+1<<"\t"<<temp_i<< '\n';
                flag++;
                --temp_i;
              }
              else
                {
                  //std::cout << "negative possibility to travel from " <<i+1<<"\t"<<j+1<< '\n';
                  break;
                }
            }
            //std::cout << "Value of flag for " <<i <<'\t'<<j<<'\t'<<flag<<'\n';
            if(flag==(i-j))
              possibility[i][j]='Y';
            else
              possibility[i][j]='N';
        }
        if(i<j){
          int flag=0;
          int temp_i=i;
          //std::cout << "*****Checking possibility to travel from***** " <<i+1<<"\t"<<j+1<< '\n';
          while(temp_i<j){
            if(probability(temp_i,temp_i+1,incoming,outgoing)){
              //std::cout << "****Positive possibility to travel from*** " <<temp_i+1<<"\t"<<temp_i+2<< '\n';
              flag++;
              ++temp_i;
              //--temp_j;
            }
            else
              {
                //std::cout << "**negative possibility to travel from** " <<i+1<<"\t"<<j+1<< '\n';
                break;
              }
          }
          //std::cout << "Value of flag for " <<i <<'\t'<<j<<'\t'<<flag<<'\n';
          if(flag==(j-i))
            possibility[i][j]='Y';
          else
            possibility[i][j]='N';
          }
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        output<<possibility[i][j];
      output<<'\n';
    }
  }
  return 0;
}
