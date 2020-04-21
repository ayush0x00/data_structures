#include<iostream>

class Node{
public:
  int data;
  Node* left_child;
  Node* right_child;
  int height;
};

Node* add_node(int data){
  Node* new_node=new Node;
  new_node->data=data;
  new_node->left_child=nullptr;
  new_node->right_child=nullptr;
  new_node->height=1;
  return new_node;
}

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

int height_difference(Node* node){
  if (node==nullptr){
    return 0;
  }
  else{
    return height(node->left_child)-height(node->right_child);
  }
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

Node* avl_insert(Node*  node,int data){//insert node in subtree rooted at node
  if (node==nullptr){
    return(add_node(data))
  }
  else if (data< node->data){
    node->left_child=add_node(node->left_child,data);
  }
  else if(data>node->data){
    node->right_child=add_node(node->right_child,data);
  }
  else{
    return node;
  }
}

node->height=1+max(height(node->left_child),height(node->right_child));
int diff=height_difference(node);

if (diff<-1 && data>node->right_child){
  return left_rotate(node);
}
if (diff>1 && data<node->left_child){
  return right_rotate(node);
}
if(diff<-1 && data<node->right_child){
node->right_child =right_rotate(node->right_child);
return left_rotate(node)
}
if(diff>1 && data>node->left_child){
  node->left_child=left_rotate(node->left_child);
  return right_rotate(node);
}
