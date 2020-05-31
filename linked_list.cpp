#include <iostream>
#include "linked_list.h"

operations:: add_head(Node** head_ref){
  Node* new_node=new Node(data);
  //new_node->_data=data;
  //new_node->_next=nullptr;
  *head_ref=new_node;
  std::cout << "Address of node-->" <<new_node->_data<<"-----"<<new_node <<'\n';
}

operations::append(Node*head,int data){
  Node* new_node=new Node(data);
  while(head->_next!=nullptr){
    head=head->_next;
  }
  head->_next=new_node;
  //new_node->_data=data;
  //new_node->_next=nullptr;
  std::cout << "Address of node-->" <<new_node->_data<<"----"<<new_node <<'\n';
}

operations:: append_at(Node*head,int position, int data){
  Node* new_node=new Node(data);
  int pos=1;
  while (pos!=position&&position!=0){
    head=head->_next;
    pos+=1;
  }
  new_node->_next=head->_next;
  head->_next=new_node;
  //new_node->_data=data;
  std::cout << "Address of node-->" <<new_node->_data<<"-----"<<new_node <<'\n';
}

operations:: delete_head(Node**head_ref){
  Node* temp=*head_ref;
  *head_ref=temp->_next;
  //temp->next=nullptr;
  delete(temp);
  std::cout << "Address of new head node-------"<<*head_ref << '\n';


}

operations:: delete_end_node(Node*head){
  while(head->_next->_next!=nullptr){
    head=head->_next;
  }
  delete(head->_next);
  head->_next=nullptr;
}

operations:: delete_node_at(Node*head,int position){
  int pos=1;
  if (position==1){
    std::cout << "not allowed" << '\n';
  }
  else{
    Node* prev=new Node;
    while(pos!=position){
      prev=head;
      head=head->_next;
      pos+=1;
    }
    prev->_next=head->_next;
    delete(head);
  }
}

operations:: printlist(Node* head){
  while (head!=nullptr) {
    std::cout << head->_data << "->";
    head=head->_next;
  }
  std::cout << "nullptr" << '\n';
}

int main(){
  Node* head=new Node(76);
  operations operation;
  operation.add_head(&head);//where ever we have to change the value of head we need to have call by reference.
  operation.append(head,98);
  operation.append(head,89);
  operation.append(head,300);
  operation.append(head,34);
  operation.append_at(head,2,69);
  operation.append_at(head,3,41);
  std::cout << "Address of previous head node ------"<<head<< '\n';
  operation.delete_head(&head);
  std::cout <<"Address of current head after fuction call----------"<< head << '\n';
  operation.delete_end_node(head);
  operation.printlist(head);
  operation.delete_node_at(head,3);
  operation.printlist(head);
  return 0;

}
