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

class Circularlinklist{
  int count;
  node* head;
  node* rear;

public:
  Circularlinklist(){
    count = 0;
    head = NULL;
    rear = NULL;
  }

  bool search(node* &ppre,node* &ploc,int target);
  bool insert(int data);
  bool deletenode(node* deletenode);
  bool emptycll();
  int countcll();
  void displayhtor();
  void displayrtoh();
  void deletelist();
  int searchposh(int target);
  int searchposr(int target);
};

bool Circularlinklist::emptycll(){
  return (count == 0);
}

bool Circularlinklist::search(node* &ppre,node* &ploc,int target){
    ppre = NULL;
    ploc = head;
    if(emptycll()) return false;

    do {
        if (ploc->data == target) return true;
        if (target < ploc->data) return false; 
        ppre = ploc;
        ploc = ploc->forword;
    } while (ploc != head);

    return false; 
}

bool Circularlinklist::insert(int data){
  node* ppre ,*ploc;
  bool found = search(ppre,ploc,data);
  if(found) return false;
  else{
    node* newnode = new node;
    newnode->data = data;

    if (ppre == NULL){
      if(emptycll()){
        head = newnode;
        rear = newnode;
      }
      else{
        head->backword = newnode;
        rear->forword = newnode;
      }
      newnode->backword = rear;
      newnode->forword = head;
      head = newnode;
    }
    else{
      newnode->backword = ppre;
      newnode->forword = ploc;
      ppre->forword = newnode;
      ploc->backword = newnode;
      if(ploc == head){
        rear = newnode;
      }
    }
    count++;
    return true;
  }
}

bool Circularlinklist::deletenode(node* deletenode){
    if (deletenode == NULL) return false;

    if(count == 1){
        head = NULL;
        rear = NULL;
    } 
    else {
        deletenode->backword->forword = deletenode->forword;
        deletenode->forword->backword = deletenode->backword;
        if(deletenode == head) {
            head = deletenode->forword;
        }
        if(deletenode == rear) {
            rear = deletenode->backword;
        }
    }

    count--;
    delete deletenode;
    return true;
}

int Circularlinklist::countcll(){
  return count;
}

void Circularlinklist::displayhtor(){
    if(emptycll()) {
        cout << "List is empty." << endl;
        return;
    }
    node* pwalker = head;
    if(pwalker != NULL){
      do {
        cout << pwalker->data << " -> ";
        pwalker = pwalker->forword;
      } while(pwalker != head);
    cout << "(head)" << endl; 
    }
}

void Circularlinklist::displayrtoh(){
    if(emptycll()) {
        cout << "List is empty." << endl;
        return;
    }
    node* pwalker = rear;
    if(pwalker != NULL){
      do {
        cout << pwalker->data << " -> ";
        pwalker = pwalker->backword;
      } while(pwalker != rear);
    cout << "(rear)" << endl; 
    }
}


void Circularlinklist::deletelist(){
  node* temp = head;
  node* temp1 = NULL;
  if(!emptycll()){
    temp1 = temp;
    temp = temp->forword;
    delete temp1;
    while(temp != head){
      temp1 = temp;
      temp = temp->forword;
      delete temp1;
    }
    head = NULL;
    rear = NULL;
    count = 0;
  }
}

int Circularlinklist::searchposh(int target){
  node* ploc = head;
  int pos = 1;
  if(emptycll()) return -1;
  if(target == ploc->data) return pos;
  ploc = ploc->forword;
  pos++;
  while(ploc != head and target > ploc->data){
    ploc = ploc->forword;
    pos++;
  }

  if (target == ploc->data) return pos;
  else return -1;
  
}

int Circularlinklist::searchposr(int target){
  node* ploc = rear;
  int pos = 1;
  if(emptycll()) return -1;
  if(target == ploc->data) return pos;
  ploc = ploc->backword;
  pos++;
  while(ploc != rear and target < ploc->data){
    ploc = ploc->backword;
    pos++;
  }

  if (target == ploc->data) return pos;
  else return -1;
}

int main(){
  Circularlinklist list;
  node* ppre;
  node* ploc;
  int choice,pos,count;
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
    cout<<"8.For count"<<endl;
    cout<<"9.For Exit"<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice){
       case 1:
         cout<<"Enter a data to insert : ";
         cin>>data;
         if(list.insert(data)) cout<<"The data is inserted"<<endl;
         else cout<<"The data is not inserted"<<endl;
         break;
       case 2:
         cout<<"Enter a data to delete : ";
         cin>>data;
         if(list.search(ppre,ploc,data)){
           list.deletenode(ploc);
           cout<<"The data is deleted"<<endl;
         }
         else cout<<"The data is not deleted"<<endl;
         break; 
       case 3:
         cout<<"Enter a num to search : ";
         cin>>target;
         pos = list.searchposh(target);
         if(pos == -1) cout<<"The target is not found"<<endl;
         else cout<<"The target found at the pos "<<pos<<endl;
         break;
       case 4:
         cout<<"Enter a num to search : ";
         cin>>target;
         pos = list.searchposr(target);
         if(pos == -1) cout<<"The target is not found"<<endl;
         else cout<<"The target found at the pos "<<pos<<endl;
         break;
      case 5:
         list.deletelist();
         cout<<"The list is deleted"<<endl;
         break;
      case 6:
         list.displayhtor();
         break;
      case 7:
         list.displayrtoh();
         break;
      case 8:
         count = list.countcll();
         cout<<count<<endl;
         break;
      case 9:
         cout<<"Exiting..."<<endl;
         break;
      default:
         cout<<"Invalid choice"<<endl;
    }
  }while(choice != 9);
}