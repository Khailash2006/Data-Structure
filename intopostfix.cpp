#include<iostream>
#include<string>
using namespace std;

struct node{
    char data;
    node *next;
    node(){
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

bool push(stackhead* stk,char data){
    node *newnode = new node;
    newnode->data = data;
    newnode->next = stk->top;
    stk->top = newnode;
    stk->count ++;
    return true;
}

bool pop(stackhead* stk,char& dataout){
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

bool stacktop(stackhead* stk,char &dataout){
    if(emptystack(stk)) return false;
    else{
        dataout = stk->top->data;
        return true;
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix;
    stackhead *stk = new stackhead;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            push(stk,c);
        } else if (c == ')') {
            char dataout;
            pop(stk,dataout);
            while (!emptystack(stk) && dataout != '(') {
                postfix += dataout;
                pop(stk,dataout);
            }
        } else {
            char dataout;
            stacktop(stk,dataout);
            while (!emptystack(stk) && precedence(c) <= precedence(dataout)) {
                postfix += dataout;
                pop(stk,dataout);
                stacktop(stk,dataout);
            }
            push(stk,c);
        }
    }

    while (!emptystack(stk)) {
        char dataout;
        pop(stk,dataout);
        postfix += dataout;
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
}