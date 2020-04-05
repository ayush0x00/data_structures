#include<iostream>

class Node{
public:
  int data;
  Node* next;
  Node* previous;
};

void add_head(Node** head,int data){
  Node* new_node=new Node;
  *head=new_node;
  new_node->data=data;
  new_node->next=nullptr;
  new_node->previous=*head;
  std::cout << "Head node--->" <<new_node->data<<"---------"<<new_node<< '\n';
}

void append(Node* head,int data){
  Node* new_node=new Node;
  new_node->data=data;
  while(head->next!=nullptr){
    head=head->next;
  }
  new_node->previous=head;
  new_node->next=nullptr;
  head->next=new_node;
  std::cout << "Added node-->" <<new_node->data<<"-------"<<new_node<< '\n';

}

void append_at(Node* head,int position,int data){
  Node* new_node=new Node;
  Node* prev_temp;
  int pos=1;
  if (position==0){
    std::cout << "Addition of head not allowed in this method" << '\n';
  }
  else{
    while(pos!=position){
      prev_temp=head;
      head=head->next;
      pos+=1;
    }
    new_node->data=data;
    new_node->next=head;
    new_node->previous=prev_temp;
    prev_temp->next=new_node;
    head->previous=new_node;
  }
}

void display(Node* head){
  //Node* head=head;
  while(head!=nullptr){
    std::cout << head->data<<"->";
    head=head->next;
  }
  std::cout << "NULL" << '\n';
}

int main(){
  Node* head=new Node;
  //std::cout << "current head address--->" <<head<< '\n';
  add_head(&head,78);
  append(head,67);
  append(head,45);
  append(head,90);
  append_at(head,2,12);
  display(head);
  std::cout <<"Head address after all function calls-->" <<head<< '\n';
  return 0;
}
