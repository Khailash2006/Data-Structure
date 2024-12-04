#include <iostream>
using namespace std;

struct node{
  int data;
  node* forword;
  node* backword;
  node(){
    data = 0;
    forword = NULL;
    backword = NULL;
  }
};

class Doublylinklist{
  int count;
  node* head;
  node* rear;

public:
  Doublylinklist(){
    count = 0;
    head = NULL;
    rear = NULL;
  }

  bool search(node* &ppre,node* &ploc,int target);
  bool insert(int data);
  bool deletenode(node* deletenode);
  bool emptydll();
  int countdll();
  void displayhtor();
  void displayrtoh();
  void deletelist();
  int searchposh(int target);
  int searchposr(int target);
};

bool Doublylinklist::emptydll(){
  return count == 0;
}

bool Doublylinklist::search(node* &ppre,node* &ploc,int target){
  ppre = NULL;
  ploc = head;
  while (ploc != NULL and target > ploc->data){
    ppre = ploc;
    ploc = ploc->forword;
  }
  
  if(ploc == NULL) return false;
  else{
    if (target == ploc->data) return true;
    else return false;
  }
}

bool Doublylinklist::insert(int data){
  node* ppre,*ploc;
  bool found = search(ppre,ploc,data);
  if(found) return false;
  else{
    node* newnode = new node;
    newnode->data = data;
    count++;

    if (ppre == NULL){
      newnode->backword = NULL;
      newnode->forword = head;
      head = newnode;
    }
    else{
      newnode->backword = ppre;
      newnode->forword = ploc;
      ppre->forword = newnode;
    }

    if(newnode->forword == NULL) rear = newnode;
    else ploc->backword = newnode;
    return true;
    }
}

bool Doublylinklist::deletenode(node* deletenode){
  if (deletenode == NULL) return false;

  if (deletenode->backword != NULL){
    deletenode->backword->forword = deletenode->forword;
  }
  else head = deletenode->forword;
  
  if(deletenode->forword != NULL){
    deletenode->forword->backword = deletenode->backword;
  }
  else rear = deletenode->backword;

  count--;
  delete deletenode;
  return true;
}

int Doublylinklist::countdll(){
  return count;
}

void Doublylinklist::displayhtor(){
  node* pwalker = head;
  while(pwalker != NULL){
    cout<<pwalker->data<<" -> ";
    pwalker = pwalker->forword;
  }
  delete pwalker;
}

void Doublylinklist::displayrtoh(){
  node* pwalker = rear;
  while(pwalker != NULL){
    cout<<pwalker->data<<" -> ";
    pwalker = pwalker->backword;
  }
  delete pwalker;
}

void Doublylinklist::deletelist(){
  while (head != NULL){
    node* dnode = head;
    head = dnode->forword;
    delete dnode;
  }

  rear = NULL;
  count = 0;
}

int Doublylinklist::searchposh(int target){
  node* ploc = head;
  int pos = 1;
  while(ploc != NULL and target > ploc->data){
    ploc = ploc->forword;
    pos++;
  }

  if (ploc == NULL) return -1;
  else {
    if (target == ploc->data) return pos;
    else return -1;
  }
}

int Doublylinklist::searchposr(int target){
  node* ploc = rear;
  int pos = 1;
  while(ploc != NULL and target < ploc->data){
    ploc = ploc->backword;
    pos++;
  }

  if (ploc == NULL) return -1;
  else {
    if (target == ploc->data) return pos;
    else return -1;
  }
}

int main(){
  Doublylinklist list;
  node* ppre;
  node* ploc;
  int choice,pos;
  int data,dataout,target;
  do{
    cout<<"Enter "<<endl;
    cout<<"1.For insert"<<endl;
    cout<<"2.For delete"<<endl;
    cout<<"3.For search from head"<<endl;
    cout<<"4.For search from rear"<<endl;
    cout<<"5.For destroy list"<<endl;
    cout<<"6.For Display from head"<<endl;
    cout<<"7.For Display from rear"<<endl;
    cout<<"8.For Exit"<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice){
       case 1:
         cout<<"Enter a data to insert : ";
         cin>>data;
         if(list.insert(data)) cout<<"The data is inserted"<<endl;
         else cout<<"The data is not inserted"<<endl;
         continue;
       case 2:
         cout<<"Enter a data to delete : ";
         cin>>data;
         if(list.search(ppre,ploc,data)){
           list.deletenode(ploc);
           cout<<"The data is deleted"<<endl;
         }
         else cout<<"The data is not deleted"<<endl;
         continue; 
       case 3:
         cout<<"Enter a num to search : ";
         cin>>target;
         pos = list.searchposh(target);
         if(pos == -1) cout<<"The target is not found"<<endl;
         else cout<<"The target found at the pos "<<pos<<endl;
         continue;
       case 4:
         cout<<"Enter a num to search : ";
         cin>>target;
         pos = list.searchposr(target);
         if(pos == -1) cout<<"The target is not found"<<endl;
         else cout<<"The target found at the pos "<<pos<<endl;
         continue;
      case 5:
         list.deletelist();
         cout<<"The list is deleted"<<endl;
         continue;
      case 6:
         list.displayhtor();
         continue;
      case 7:
         list.displayrtoh();
         continue;
      case 8:
         cout<<"Exiting..."<<endl;
         continue;
      default:
         cout<<"Invalid choice"<<endl;
    }
  }while(choice != 8);
}