#include <iostream>
#include <cstddef>

struct Node{
  int data;
  Node* next=NULL;
};

void add_head(Node** head,int data){
  Node* new_node=new Node;
  //std::cout << head << '\n';
  new_node->data=data;
  new_node->next=NULL;
  *head=new_node;
  //std::cout << head << '\n';

}
void append(Node** head,int data){
  return;
}

void printlist(Node* head){
  Node* head_node=head;
  while (head_node!=NULL) {
    std::cout << head_node->data << "->";
    head_node=head_node->next;
  }
  std::cout << "NULL" << '\n';
}

int main(){
  Node* head=new Node;
  //std::cout << head << '\n';
  add_head(&head,56);//we need to pass the address of head so to have a call by referenece.
  add_head(&head,76);
  //std::cout << head << '\n';
  printlist(head);
  return 0;

}
