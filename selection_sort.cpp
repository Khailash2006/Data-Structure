#include<iostream>
using namespace std;

int main(){
    int a[5];
    for (int i=0;i<5;i++){
        cout<<"Enter a value of element "<<i+1<<" :";
        cin>>a[i];
    }
    for (int i=0;i<5;i++){
        int min=i;
        for (int j=i+1;j<4;j++){
            if (a[min]>a[j]){
                min=j;
            }
        }
        if (min!=i){
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    cout<<"The value of sorted array is"<<endl;
    for (int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}