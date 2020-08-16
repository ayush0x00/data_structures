#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int calculate_perimeter(const vector<int> &l, const vector<int> &h,const int &w){
  std::vector<int> perimeter;
  int start=0;
  perimeter.push_back(2*(h[0]+w));
  int previous_perimeter=0;
  for(int i=1;i<l.size();i++){
    previous_perimeter=perimeter[i-1];
    if(l[i]<(l[i-1]+w)){
      int top=l[i]+w-l[start];
      cout<<"top="<<top<<" ";
      int right;
      int left;
      if(h[i]<h[i-1]){
        left=h[i-1];
        right=h[i-1];
      }
      else{
        left=h[i];
        right=h[i];
      }
      std::cout << "left=" <<left<<" ";
      std::cout << "right=" <<right<<"\n";
      perimeter.push_back(top+top+left+right);
    }
    else{
      perimeter.push_back(previous_perimeter+2*(h[i]+w));
      start=i;
    }
  }
  for(int i=0;i<perimeter.size();i++)
    std::cout << perimeter[i] <<" ";
  return 0;
}

int main(){
    ifstream input("perimetric_1.txt");
    ofstream output("perimetric_1_output.txt");
    int t;
    input>>t;
    for(int test=0;test<t;test++){
      //cout<<"Case #"<<test+1<<":"<<" " ;
      int n,k,w;
      input>>n>>k>>w;
      //cout<<n<<" "<<k<<" "<<w<<"\n";
      std::vector<int> l;
      std::vector<int> h;

      for(int i=0;i<k;i++){
        int val;
        input>>val;
        l.push_back(val);
      }

      int al,bl,cl,dl;
      input>>al>>bl>>cl>>dl;

      for(int i=0;i<k;i++){
        int val;
        input>>val;
        h.push_back(val);
      }

      int ah,bh,ch,dh;
      input>>ah>>bh>>ch>>dh;

      for(int i=k;i<n;i++){
        int lval=((al*l[i-2]+bl*l[i-1]+cl)%dl)+1;
        int hval=((ah*h[i-2]+bh*h[i-1]+ch)%dh)+1;
        l.push_back(lval);
        h.push_back(hval);
      }
      int result=calculate_perimeter(l,h,w);
    }
    return 0;
}
