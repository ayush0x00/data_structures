#include <iostream>
class Node{
public:
  int data;
  Node* right_child;
  Node* left_child;
};

void add_root(Node** root,int data){
  Node* new_node=new Node;
  Node* root_temp=*root;
  new_node->data=data;
  new_node->left_child=root_temp->left_child;
  new_node->right_child=root_temp->right_child;
  *root=new_node;
  delete(root_temp);
  std::cout << "Root added of value-->" <<new_node->data<<"--> on address "<<new_node<< '\n';
}

void add_node(Node* root, int data){
  Node* new_node=new Node;
  new_node->data=data;
  while(1){
    if (data>root->data){
      if (root->right_child==nullptr){
        root->right_child=new_node;
        break;
      }
      else{
        root=root->right_child;
      }
    }
    else{
      if (root->left_child==nullptr){
        root->left_child=new_node;
        break;
      }
      else{
        root=root->left_child;
      }
    }
  }
}

void searchbst(Node* root, int val){
  if(root==nullptr){
    std::cout << "Value not found" << '\n';
    return;
  }
  if (root->data==val){
    std::cout << "Value found at address -->" <<root<< '\n';
    return;
  }

  else if(val<root->data){
    searchbst(root->left_child,val);
  }
  else if(val>root->data){
    searchbst(root->right_child,val);
}
}

void display(Node* root){
  if (root==nullptr){
    return;
  }
  else{
  if(root->right_child==nullptr && root->left_child==nullptr){
    return;
  }
  if(root->right_child!=nullptr && root->left_child!=nullptr){
    std::cout << root->left_child->data<<"-->" ;
    std::cout << root->right_child->data<<"-->" ;
    display(root->left_child);
    display(root->right_child);
  }
  else if(root->right_child==nullptr){
    std::cout << root->left_child->data << '\n';

  }
  else if(root->left_child==nullptr){
    std::cout << root->right_child->data << '\n';

  }

  std::cout<< '\n';
}

}

void preorder(Node* root){
  if(root==nullptr){
    return;
  }
  std::cout << root->data <<"->";
  preorder(root->left_child);
  preorder(root->right_child);
}

void inorder(Node* root){
  if (root==nullptr)
  return;
  inorder(root->left_child);
  std::cout << root->data <<"->";
  inorder(root->right_child);
}

void postorder(Node* root){
  if(root==nullptr)
  return;
  postorder(root->left_child);
  postorder(root->right_child);
  std::cout << root->data <<"->" ;
}


int main(){
  Node* root=new Node;
  add_root(&root,89);
  add_node(root,56);
  add_node(root,34);
  add_node(root,78);
  add_node(root,22);
  add_node(root,96);
  add_node(root,95);
  add_node(root,104);
  searchbst(root,78);
  preorder(root);
  std::cout <<"null"<< '\n';
  postorder(root);
  std::cout <<"null"<< '\n';
  inorder(root);
  std::cout << "null"<<'\n';
  return 0;
}
