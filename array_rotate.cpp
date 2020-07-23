/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y){
  int temp=x;
  x=y;
  y=temp;
}

void transpose(std::vector<std::vector<int> > &arr){
  int size=arr.size();
  for(int i=0;i<size;i++){
       for(int j=i;j<size;j++){
           int temp=arr[i][j];
           arr[i][j]=arr[j][i];
           arr[j][i]=temp;
       }
   }
}

void flip(std::vector<std::vector<int> > &arr){
  int size=arr.size();
  for(int i=0;i<size;i++){
    for(int j=0;j<(size/2);j++){
      int temp=arr[i][j];
      arr[i][j]=arr[i][size-(1+j)];
      arr[i][size-(1+j)]=temp;
    }
  }
}


int main(){
  int size;
  cin>>size;
  std::vector<std::vector<int>> arr(size);
  for(int i=0;i<size;i++){
    arr[i].resize(size);
    for (int j=0;j<size;j++)
      std::cin>> arr[i][j];
  }
  transpose(arr);
  flip(arr);
  for(int i=0;i<size;i++){
    for (int j=0;j<size;j++)
      std::cout << arr[i][j] << " ";
    std::cout  << '\n';
  }
  return 0;
}
