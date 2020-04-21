#include<iostream>

class Node{
public:
  int data;
  Node* left_child;
  Node* right_child;
  int height;
};

int height(Node* current){
  if (current==nullptr){
    return 0;
  }
  return current->height;
}

int max(int a, int b){
  return (a>b)?a:b;
}

Node* right_rotate(Node* current){  //perform rotation on tree rooted at current node
  Node* temp_x=current->left_child;
  Node* temp_y=temp_x->right_child;
  //performing rotations
  temp_x->right_child=current;
  current->left_child=temp_y;
  //calculating heights
  temp_x->height=max(height(temp_x->right_child),height(temp_x->left_child));
  temp_y->height=max(height(temp_y->right_child),height(temp_y->left_child));

  return temp_x;
}

Node* left_rotate(Node* current){
  Node* temp_x= current->right_child;
  Node* temp_y=temp_x->left_child;

  temp_x->left_child=current;
  current->right_child=temp_y;

  temp_x->height=max(height(temp_x->right_child),height(temp_x->left_child));
  temp_y->height=max(height(temp_y->right_child),height(temp_y->left_child));

  return temp_x;
}
