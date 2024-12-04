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

struct stackhead{
    int count;
    node* top;
    stackhead(){
        count = 0;
        top = NULL;
    }
};

bool emptystack(stackhead* stk){
    return stk->count == 0;
}

bool push(stackhead* stk,int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->next = stk->top;
    stk->top = newnode;
    stk->count ++;
    return true;
}

bool pop(stackhead* stk,int& dataout){
    if (emptystack(stk)) return false;
    else{
        node *temp = stk->top;
        dataout = temp->data;
        stk->top = temp->next;
        delete temp;
        stk->count--;
        return true;
    }
}

bool stacktop(stackhead* stk,int &dataout){
    if(emptystack(stk)) return false;
    else{
        dataout = stk->top->data;
        return true;
    }
}

void destroystack(stackhead* stk){
    while(stk->top != NULL){
        node* temp = stk->top;
        stk->top = temp->next;
        delete temp;
    }
    stk->count = 0;
}

int stackcount(stackhead* stk){
    return stk->count;
}

int main(){
    stackhead* stk = new stackhead;
    int dataout,count;
    int choice;
    do{
        cout<<"Enter "<<endl;
        cout<<"1.For push"<<endl;
        cout<<"2.For pop"<<endl;
        cout<<"3.For stacktop"<<endl;
        cout<<"4.For destroystack"<<endl;
        cout<<"5.For stack count"<<endl;
        cout<<"6.For Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1){
            int num;
            cout<<"Enter a num to push :";
            cin>>num;
            push(stk,num);
            cout<<"The element pushed"<<endl;
        }
        else if (choice == 2){
            if(pop(stk,dataout)){
                cout<<"The popped element is "<<dataout<<endl;
            }
            else{
                cout<<"The list is empty"<<endl;
            }
        }
        else if (choice == 3){
            if(stacktop(stk,dataout)){
                cout<<"The top element is "<<dataout<<endl;
            }
            else{
                cout<<"The list is empty"<<endl;
            }
        }
        else if (choice == 4) {
            destroystack(stk);
        }
        else if(choice == 5){
            count = stackcount(stk);
            cout<<"The no. of element in the stack is "<<count<<endl;
        }
        else cout<<"Please check your choice"<<endl;
    }while(choice != 6);
    delete(stk);
}