#include<iostream>
using namespace std;

class Queue{
  const int max = 10;
  int a[10];
  int front,rear;
  public:
    Queue(){
      front = rear = -1;
    }
    bool enque(int);
    bool deque(int&);
    bool queueFront(int&);
    bool queueRear(int&);
    bool emptyQueue();
    bool fullQueue();
    int queuecount();
};

bool Queue::emptyQueue(){
  bool empty;
  if (front == -1 and rear == -1)empty = true;
  else empty = false;
  return empty;
}

bool Queue::fullQueue(){
  bool full;
  if (rear == max) full = true;
  else full = false;
  return full;
}

bool Queue::enque(int data){
  bool success;
  if (fullQueue()) success = false;
  else{
    rear++;
    a[rear] = data;
    if (front = -1) front = 0;
    success = true;
  }
  return success;
}

bool Queue::deque(int& dataout){
  bool success;
  if (emptyQueue()) success = false;
  else{
    dataout = a[front];
    if (front == rear) front = rear = -1;
    else{
      front++;
      success = true;
    }
  }return success;
}

bool Queue::queueRear(int& dataout){
  bool success;
  if (emptyQueue()) success = false;
  else{
    dataout = a[rear];
    success = true; 
  }
  return success;
}

bool Queue::queueFront(int& dataout){
  bool success;
  if (emptyQueue()) success = false;
  else{
    dataout = a[front];
    success = true;
  }
  return success;
}

int Queue::queuecount(){
    return (rear-front);
}
int main(){
  int data,dataout,choice;
  Queue s;
  bool a,b,c;

  do{
    cout<<"Enter "<<endl;
    cout<<"1.For Enque"<<endl;
    cout<<"2.For Deque"<<endl;
    cout<<"3.For QueueFront"<<endl;
    cout<<"4.For QueueRear"<<endl;
    cout<<"5.For exit"<<endl;
    cout<<"Enter your choice :";
    cin>>choice;
   
    switch(choice){
      case 1:
        cout<<"Enter a data :";
        cin>>data;
        a = s.enque(data);
        if (a) cout<<"Enquied successfully"<<endl;
        else cout<<"Queue is overflow"<<endl;
        continue;
      case 2:
        b = s.deque(dataout);
        if (b) cout<<"The data dequied is "<<dataout<<endl;
        else cout<<"Queue is underflow"<<endl;
        continue;
      case 3:
        c = s.queueFront(dataout);
        if (c) cout<<"The data QueueFronted is "<<dataout<<endl;
        else cout<<"Queue is underflow"<<endl;
        continue;
      case 4:
        c = s.queueRear(dataout);
        if (c) cout<<"The data QueueReared is "<<dataout<<endl;
        else cout<<"Queue is underflow"<<endl;
        continue;
      case 5: continue;
      default:
        cout<<"Please check your choice"<<endl;
    }
  }while(choice !=5);

}