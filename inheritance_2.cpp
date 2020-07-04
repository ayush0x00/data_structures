#include <iostream>
#include <string>
using namespace std;
class Student{

public:
  static int roll_no;
  Student(string name):_name(name){
    roll_no++;
  }

  float phy_marks,chem_marks,math_marks;
  void set_phy(float marks){
    phy_marks=marks;
  }
  void set_chem(float marks){
    chem_marks=marks;
  }
  void set_math(float marks){
    math_marks=marks;
  }
private:
  string _name;
};
int Student::roll_no=0; //you cant initialize static memebers from inside class

class set_marks: public Student{
public:
  set_marks(string name,float phy_marks,float chem_marks,float math_marks):Student(name),phy_marks(phy_marks),chem_marks(chem_marks),math_marks(math_marks){
    this->Student::set_phy(phy_marks);
    this->Student::set_chem(chem_marks);
    this->Student::set_math(math_marks);
    std::cout << "Marks initialized...ready for calculation" << '\n';
  }
  float total_marks(){
    total=this->phy_marks+this->math_marks+this->chem_marks;
    return total;
  }
  float average(){
    return total/3;
  }
private:
  float total;
  float phy_marks,chem_marks,math_marks;
};

int main(){
  set_marks a1=set_marks("Ayush",45.0,56.0,33.0);
  std::cout << "total marks = " <<a1.total_marks()<< '\n';
  std::cout << "average marks= " <<a1.average()<< '\n';
  std::cout << "total Student " <<a1.roll_no<< '\n';
  return 0;
}
