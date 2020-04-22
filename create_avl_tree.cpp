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

Node* avl_insert(Node* node,int data){//insert node in subtree rooted at node
  if (node==nullptr){
    //std::cout << node << '\n';
    return(add_node(data));
  }
  else if (data< node->data){
    node->left_child=avl_insert(node->left_child,data);
  }
  else if(data>node->data){
    node->right_child=avl_insert(node->right_child,data);
  }
  else{
    return node;
  }


node->height=1+max(height(node->left_child),height(node->right_child));
int diff=height_difference(node);
std::cout << diff << '\n';

if (diff<-1 && data>node->right_child->data){
  return left_rotate(node);
}
if (diff>1 && data<node->left_child->data){
  return right_rotate(node);
}
if(diff<-1 && data<node->right_child->data){
node->right_child =right_rotate(node->right_child);
return left_rotate(node);
}
if(diff>1 && data>node->left_child->data){
  node->left_child=left_rotate(node->left_child);
  return right_rotate(node);
}
if(diff==1){
  return node;
}
}

void preorder(Node* root){
if (root!=nullptr){
  std::cout << root->data <<"->"<< '\n';
  preorder(root->left_child);
  preorder(root->right_child);
}
}

int main(){
  Node* root=nullptr;
  root=avl_insert(root,67);
  std::cout << root->data << '\n';
  root=avl_insert(root,56);
  std::cout << root->data << '\n';

  root=avl_insert(root,34);
  std::cout << root << '\n';
  root=avl_insert(root,98);
  root=avl_insert(root,58);
  root=avl_insert(root,22);
  root=avl_insert(root,21);
  preorder(root);
  return 0;
}
