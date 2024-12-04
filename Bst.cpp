#include<iostream>
using namespace std;

struct node{
  node* left;
  int data;
  node* right;
  node(){
    left = NULL;
    data = 0;
    right = NULL;
  }
};

node* largestBST(node* root);

bool addBST(node* &root,node* newnode){
  if(root == NULL){
    root = newnode;
    return true;
  }
  
  if(root->data > newnode->data) return addBST(root->left,newnode);
  else return addBST(root->right,newnode);
}

bool deleteBST(node* &root,int dltkey){
  if(root == NULL) return false;

  if(dltkey < root->data) return deleteBST(root->left,dltkey);
  else if(dltkey > root->data) return deleteBST(root->right,dltkey);
  else{
    if(root->left == NULL){
      root = root->right;
      return true;
    }
    else if(root->right == NULL){
      root = root->left;
      return true;
    }
    else{
      node* dltnode = root;
      node* large = largestBST(root->left);
      dltnode->data = large->data;
      return deleteBST(dltnode->left,large->data);
    }
  }
}

bool searchBST(node* root,int target){
  if(root == NULL) return false;
  
  if(target < root->data) return searchBST(root->left,target);
  else if(target > root->data) return searchBST(root->right,target);
  else true;
}

node* largestBST(node* root){
  if(root->right == NULL)  return root;
  return largestBST(root->right);
}

node* smallestBST(node* root){
  if(root->left == NULL)  return root;
  return smallestBST(root->right);
}

void preorder(node* root){
  if(root != NULL){
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node* root){
  if(root != NULL){
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
  }
}

void postorder(node* root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
  }
}

int main(){
  node* root = NULL;
  int choice,data,del,target;
  do{
    cout<<"Enter"<<endl;
    cout<<"1.For Insert"<<endl;
    cout<<"2.For Delete"<<endl;
    cout<<"3.For Search"<<endl;
    cout<<"4.For Preorder"<<endl;
    cout<<"5.For Inorder"<<endl;
    cout<<"6.For Postorder"<<endl;
    cout<<"7.For Exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter a data to Insert : ";
        cin>>data;
        node* newnode = new node;
        newnode->data = data;
        if(addBST(root,newnode)) cout<<"The entered data is Inserted"<<endl;
        break;}
      case 2:{
        cout<<"Enter a data to delete : ";
        cin>>del;
        if(deleteBST(root,del)) cout<<"The Entered data is Deleted"<<endl;
        else cout<<"The Entered data is not Deleted"<<endl;
        break;}
     case 3:
        cout<<"Enter a data to Search : ";
        cin>>target;
        if(searchBST(root,target)) cout<<"The Entered data is Found"<<endl;
        else cout<<"The Entered data is not Found"<<endl;
        break;
     case 4:
        preorder(root);
        break;
     case 5:
        inorder(root);
        break;
     case 6:
        postorder(root);
        break;
     case 7:
        cout<<"Exiting..."<<endl;
        break;
     default:
        cout<<"Invalid Choice"<<endl;
    }
  }while(choice != 7);
}