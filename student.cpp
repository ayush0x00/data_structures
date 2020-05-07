#include<cassert>
#include<string>
#include<stdexcept>
#include<iostream>
using std::string;

class Student{
public:
  Student(string name, int grade, float GPA):name_(name),grade_(grade),GPA_(GPA){
    validate();
  }
  string Name() const { return name_;}
  float GPA() const { return GPA_;}
  int Grade() const { return grade_;}
  void Name(string name){name_=name;}
  void GPA(float GPA){GPA_=GPA; validate();}
  void Grade(int grade){grade_=grade;validate();}
private:
  string name_;
  int grade_;
  float GPA_;
  void validate(){
    if(Grade()<0 || Grade()>12 || GPA()<0.0 || GPA()>4.0)
      throw std:: invalid_argument("Invalid parameters passed");
  }
};

int main(){
  Student student("Ayush Tiwari",8,3.4);
  assert(student.Name()=="Ayush Tiwari");
  assert(student.Grade()==8);
  //assert(student.GPA()==3.4); assertion not working here???
  //std::cout << student.GPA() << '\n';
  bool caught{false};
  try{
    Student test("validate",13,-1);
  }
  catch(...){
    caught=true;
  }
  assert(caught);

  return 0;

}
