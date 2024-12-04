#include<iostream>
using namespace std;

struct node{
  int data;
  node *next;
  node(){
    data = 0;
    next = NULL;
  }
};

struct list{
  int count;
  node *head;
  list(){
    count = 0;
    head = NULL;
  }
};


bool insertnode(list *list,node *ppre,int datain){
  node* pnew = new node;
  pnew->data = datain;

  if (ppre == NULL) {
    pnew->next = list->head;
    list->head = pnew;
  }
  else {
    pnew->next = ppre->next;
    ppre->next = pnew;
  }
  list->count++;
  return true;
}

bool deletenode(list *list,node* ppre,node* ploc,int &dataout){
  if(ppre == NULL){
    list->head = ploc->next;
  }
  else {
    ppre->next= ploc->next;
  }
  dataout = ploc->data;
  delete(ploc);
  list->count--;
  return true;
}

bool searchlist(list *list,node *&ppre,node *&ploc,int target){
    ppre = NULL;
    ploc = list->head;

    while (ploc != NULL and ploc->data != target){
        ppre = ploc;
        ploc = ploc->next;
    }

    if (target == ploc->data){
        return true;
    }
    else {
        return false;
    }
}

bool retrievenode(list *list,int target,int &dataout){
    node *ppre,*ploc;
    bool found = searchlist(list,ppre,ploc,target);
    if (found){
        dataout = ploc->data;
    }
    return found;
}

bool emptylist(list* list){
    if (list->count == 0){
        return true;
    }
    else {
        return false;
    }
}

int listcount(list* list){
    return list->count;
}

bool getnext(list *list,int fromwhere,int &dataout){
    node *current = new node();

    if (list->count == 0) return false;

    if (fromwhere == 1){
        current = list->head;
        dataout = current->data;
        return true;
    }

    current = list->head;
    for (int i = 1; i < fromwhere ;i++){
        current = current->next;
    }

    if (current == NULL){
        delete(current);
        return false;
    }
    else{
        dataout = current->data;
        delete(current);
        return true;
    }
}

bool destroylist(list *list){
    while (list->head != NULL){
        node* current = list->head;
        list->head = current->next;
        delete(current);
    }
    list->count = 0;
    list->head = NULL;
    return true;
}

int main(){
    list* lst = new list;
    int choice;
    do{
        int datain,dataout,num,from,count;
        node *ppre = NULL,*ploc = NULL;
        cout<<"Enter "<<endl;
        cout<<"1. For insert"<<endl;
        cout<<"2. For delete"<<endl;
        cout<<"3. For search"<<endl;
        cout<<"4. For retrieve"<<endl;
        cout<<"5. For emptylist"<<endl;
        cout<<"6. For list count"<<endl;
        cout<<"7. For traversal"<<endl;
        cout<<"8. For delete list"<<endl;
        cout<<"9. For exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice){
           case 1:
                cout<<"Enter a data for inserting : ";
                cin>>datain;
                insertnode(lst,NULL,datain);
                cout<<"New node inserted"<<endl;
                continue;
           case 2:
                cout<<"Enter the num to delete : ";
                cin>>num;
                if (searchlist(lst,ppre,ploc,num)){
                    deletenode(lst,ppre,ploc,dataout);
                    cout<<"The deleted data is "<<dataout<<endl;
                }
                else{
                    cout<<"Entered num is not present"<<endl;
                }
                continue;
           case 3:
                cout<<"Enter the num to search : ";
                cin>>num;
                if (searchlist(lst,ppre,ploc,num)){
                    cout<<"The data is found"<<endl;
                }
                else{
                    cout<<"The data is not found"<<endl;
                }
                continue;
         case 4:
             cout<<"Enter a number for retrieve:";
             cin>>num;
             if (retrievenode(lst,num,dataout)){
                cout<<"The node retrieved is "<<dataout<<endl;
             }
             else{
                cout<<"The data is not retrieved"<<endl;
             }
             continue;
        case 5:
            if (emptylist(lst)){
                cout<<"The list is empty"<<endl;
            }
            else{
                cout<<"The list is not empty"<<endl;
            }
            continue;
        case 6:
            count = listcount(lst);
            cout<<"The count of the list is "<<count<<endl;
            continue;
        case 7:
            cout<<"Enter the value for fromwhere:";
            cin>>from;
            if (getnext(lst,from,dataout)){
                cout<<"The data at that position is "<<dataout<<endl;
            }
            else{
                cout<<"The position is greater than the list size"<<endl;
            }
            continue;
        case 8:
            destroylist(lst);
            continue;
        case 9:
            cout<<"Exiting";
            continue;
        default:
            cout<<"Invalid choice";
        }
    }while(choice != 9);
    delete(lst);
}