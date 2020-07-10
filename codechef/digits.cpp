#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
vector<int> all_digits(int number){
    //int n=number;
    vector<int>digits;
    while(number>0){
        int digit=number%10;
        number/=10;
        digits.push_back(digit);
    }
    return digits;
}
int findDigits(int n) {
    for(int i=0;i<n;i++){
        int number,counter=0;
        cin>>number;
        vector<int>digits=all_digits(number);
        for(int j=0;j<digits.size();j++){
          //std::cout << digits[j] << '\n';
            if(number%digits[j]==0)
            counter++;
        }
        return counter;
    }
}
int main(){
  int result=findDigits(1);
  cout<<result<<"\n";
  return 0;
}
