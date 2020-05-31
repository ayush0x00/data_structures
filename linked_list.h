#pragma once
class Node{
public:
  Node(int data):_data(data),_next(nullptr){}
private:
  int _data;
  Node* _next;
};

class operations:public Node{
public:
  operations();
  void add_head(Node**head_ref);
  void append(Node*head, int data);
  void append_at(Node* head,int position,int data);
  void delete_head(Node**head_ref);
  void delete_end_node(Node*head);
  void delete_node_at(Node*head,int position);
  void printlist(Node* head);
};
