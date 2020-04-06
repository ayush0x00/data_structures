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

void display(Node* root){
  //std::cout << root->data <<"-->";
  if (root==nullptr){
    return;
  }
  else{
  //Node* root=root;
  //std::cout << root->data <<"-->";
  if(root->right_child==nullptr && root->left_child==nullptr){
    //std::cout << "null";
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
    //root=root->left_child;
    //display(root);
  }
  else if(root->left_child==nullptr){
    std::cout << root->right_child->data << '\n';
    //root=root->right_child;
    //display(root);
  }



  //display(root->left_child);
  //display(root->right_child);
  //std::cout << "null" << '\n';
  //display(temp->right_child);
  std::cout<< '\n';
}

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
  //add_node(root,199);
  //add_node(root,2354);

  display(root);
  //std::cout << "Value and address of root after all function calls-->" <<root->data<<"--"<<root<< '\n';
  return 0;
}
