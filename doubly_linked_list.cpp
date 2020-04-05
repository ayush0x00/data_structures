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
  if (position==1){
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
    std::cout << "Added node-->" <<new_node->data<<"-------"<<new_node<< '\n';
  }
}

void delete_head(Node** head){
  Node* temp=*head;
  *head=temp->next;
  delete(temp);
  std::cout << "New head-->" <<*head<< '\n';
}

void delete_end(Node* head){
  while(head->next->next!=nullptr){
    head=head->next;
  }
  delete(head->next);
  head->next=nullptr;
}

void delete_node_at(Node* head, int position){
  int pos=1;
  if (position==1){
    std::cout << "Deletion of head not allowed in this method" << '\n';
  }
  else{
    Node* prev;
    while(pos!=position){
      prev=head;
      head=head->next;
      pos+=1;
    }
    prev->next=head->next;
    head->next->previous=prev;
    head->next=nullptr;
    head->previous=nullptr;
    delete(head);
  }
}

void display(Node* head){
  while(head!=nullptr){
    std::cout << head->data<<"->";
    head=head->next;
  }
  std::cout << "NULL" << '\n';
}

int main(){
  Node* head=new Node;
  add_head(&head,78);
  append(head,67);
  append(head,45);
  append(head,90);
  append_at(head,2,12);
  append_at(head,2,98);
  append(head,34);
  display(head);
  delete_head(&head);
  delete_end(head);
  delete_node_at(head,2);
  display(head);
  std::cout <<"Head address after all function calls-->" <<head<< '\n';
  return 0;
}
