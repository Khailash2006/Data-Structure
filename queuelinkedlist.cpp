#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(){
        data = 0;
        next = NULL;
    }
};

struct queuehead{
    int count;
    node* front;
    node* rear;
    queuehead(){
        count = 0;
        front = NULL;
        rear = NULL;
    }
};

bool enque(queuehead* queue,int data){
    node* newnode = new node;
    newnode->data = data;
    if(queue->rear == NULL) queue->front = newnode;
    else queue->rear->next = newnode;
    queue->rear = newnode;
    queue->count ++;
    return true; 
}

bool emptyqueue(queuehead* queue){
    return queue->count == 0;
}
bool deque(queuehead* queue,int &dataout){
    if(emptyqueue(queue)) return false;
    else{
        node* temp = new node;
        temp = queue->front;
        dataout = temp->data;
        queue->front = temp->next;
        if(queue->front == NULL) queue->rear = NULL;
        delete temp;
        return true;
    }
}

bool queuefront(queuehead* queue,int &dataout){
    if(emptyqueue(queue)) return false;
    else{
        dataout = queue->front->data;
        return true;
    }
}

bool queuerear(queuehead* queue,int &dataout){
    if(emptyqueue(queue)) return false;
    else{
        dataout = queue->rear->data;
        return true;
    }
}

int queuecount(queuehead* queue){
    return queue->count;
}

void destroyqueue(queuehead* queue){
    while(queue->front != NULL){
        node* temp = queue->front;
        queue->front = temp->next;
        delete temp;
    }
    queue->rear = NULL;
    queue->count = 0;
}

int main(){
    queuehead* queue = new queuehead;
    int dataout,count;
    int choice;
    do{
        cout<<"Enter "<<endl;
        cout<<"1.For Enqueue"<<endl;
        cout<<"2.For Dequeue"<<endl;
        cout<<"3.For Queuefront"<<endl;
        cout<<"4.For Queuerear"<<endl;
        cout<<"5.For destroystack"<<endl;
        cout<<"6.For Queue count"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1){
            int num;
            cout<<"Enter a num to Enqueue :";
            cin>>num;
            enque(queue,num);
            cout<<"The element Enqueued"<<endl;
        }
        else if (choice == 2){
            if(deque(queue,dataout)){
                cout<<"The Dequeued element is "<<dataout<<endl;
            }
            else{
                cout<<"The list is empty"<<endl;
            }
        }
        else if (choice == 3){
            if(queuefront(queue,dataout)){
                cout<<"The queue front element is "<<dataout<<endl;
            }
            else{
                cout<<"The list is empty"<<endl;
            }
        }
        else if (choice == 4) {
            if(queuerear(queue,dataout)){
                cout<<"The queue rear element is "<<dataout<<endl;
            }
            else{
                cout<<"The list is empty"<<endl;
            }
        }
        else if (choice == 5){
            destroyqueue(queue);
        }
        else if(choice == 6){
            count = queuecount(queue);
            cout<<"The no. of element in the queue is "<<count<<endl;
        }
        else cout<<"Please check your choice"<<endl;
    }while(choice != 7);
    delete(queue);
}