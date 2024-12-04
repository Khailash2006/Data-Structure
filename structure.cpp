#include<iostream>
using namespace std;
struct distance{
    int feet;
    float inch; 
}d1,d2;
void engdisp(struct distance );
int main(){
    
    //get length d1
    cout<<"Enter feet:";
    cin>>d1.feet;
    cout<<"\nEnter inches:";
    cin>>d1.inch;
    //get length d2
    cout<<"\nEnter feet:";
    cin>>d2.feet;
    cout<<"\nEnter inches:";
    cin>>d2.inch;
    cout<<"\nd1=";
    engdisp(d1);
    cout<<"\nd2=";
    engdisp(d2);
    cout<<endl;
    return 0;
}
void engdisp(struct distance dd){
    cout<<dd.feet<<"-"<<dd.inch;
}