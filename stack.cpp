#include <iostream>
using namespace std;

class stack {
    int top;
    const int max = 10;
    int a[10];
public:
    stack() {
        top = -1;
    }

    bool emptystack();
    bool fullstack();
    bool push(int data);
    bool pop(int &dataout);
    bool stacktop(int &dataout);
};

bool stack::emptystack() {
    return top == -1;
}

bool stack::fullstack() {
    return top == max - 1; // Adjusted for zero-based index
}

bool stack::push(int data) {
    if (fullstack()) {
        return false; // Stack overflow
    } else {
        a[++top] = data; // Increment top and then assign data
        return true;
    }
}

bool stack::pop(int &dataout) {
    if (emptystack()) {
        return false; // Stack underflow
    } else {
        dataout = a[top--]; // Assign data and then decrement top
        return true;
    }
}

bool stack::stacktop(int &dataout) {
    if (emptystack()) {
        return false; // Stack is empty
    } else {
        dataout = a[top]; // Assign top element
        return true;
    }
}

int main() {
    int data, dataout, choice;
    stack s;
    bool success;

    do {
        cout << "Enter " << endl;
        cout << "1. For push" << endl;
        cout << "2. For pop" << endl;
        cout << "3. For stacktop" << endl;
        cout << "4. For exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            success = s.push(data);
            if (success) {
                cout << "Pushed successfully" << endl;
            } else {
                cout << "Stack is full" << endl;
            }
            continue;
        case 2:
            success = s.pop(dataout);
            if (success) {
                cout << "The data popped is " << dataout << endl;
            } else {
                cout << "Stack is empty" << endl;
            }
            continue;
        case 3:
            success = s.stacktop(dataout);
            if (success) {
                cout << "The data at stack top is " << dataout << endl;
            } else {
                cout << "Stack is empty" << endl;
            }
            continue;
        case 4:
            cout << "Exiting..." << endl;
            continue;
        default:
            cout << "Please check your choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
