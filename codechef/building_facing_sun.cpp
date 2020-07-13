#include<iostream>
using namespace std;
int main(){
  int n,height;
  std::cout << "Enter the number of test cases " << '\n';
  std::cin >> n;
  for(int i=0;i<n;i++){
    std::cout << "Enter the number of building " << '\n';
    std::cin >> height;
    int arr[height];
    for (int j=0;j<height;j++){
      cin>>arr[j];
    }
    int flag=1;
    //sort(arr,arr+height);
    int current=arr[0];
    int next=arr[1];
    for(int k=0;k<height-1;k++){
      if(next>=current){
        std::cout << "If executing" << '\n';
        current=next;
        next=arr[k+2];
        ++flag;
      }
      else{
        std::cout << "else executing" << '\n';
        next=arr[k+2];
      }
    }
    std::cout << flag << '\n';
  }
  return 0;
}
