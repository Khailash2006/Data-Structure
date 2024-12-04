#define MAX 10
#include <iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

struct nodehead {
    node* first;
    int count;
};

struct Hashtable {
    nodehead* hashtable[MAX];
};

// Function to create a new hashtable
Hashtable* createhashtable() {
    Hashtable* hash = new Hashtable;
    for (int i = 0; i < MAX; i++) {
        hash->hashtable[i] = new nodehead; // Allocate memory for each nodehead
        hash->hashtable[i]->first = NULL;
        hash->hashtable[i]->count = 0;
    }
    return hash;
}

// Function to create a new node
node* createnode(int key) {
    node* newnode = new node;
    newnode->data = key;
    newnode->link = NULL;
    return newnode;
}

// Function to insert a key into the hash table
bool inserthash(Hashtable* hash, int key) {
    int hashindex = key % MAX;
    node* newnode = createnode(key);
    newnode->link = hash->hashtable[hashindex]->first;
    hash->hashtable[hashindex]->first = newnode;
    hash->hashtable[hashindex]->count++;
    return true;
}

// Function to delete a key from the hash table
bool deletehash(Hashtable* hash, int dltkey) {
    int hashindex = dltkey % MAX;
    node* delnode = hash->hashtable[hashindex]->first;
    node* pred = NULL;
    while (delnode != NULL) {
        if (delnode->data == dltkey) {
            if (pred == NULL) {
                hash->hashtable[hashindex]->first = delnode->link;
            } else {
                pred->link = delnode->link;
            }
            hash->hashtable[hashindex]->count--;
            delete(delnode);
            return true;
        }
        pred = delnode;
        delnode = delnode->link;
    }
    return false;
}

// Function to search for a key in the hash table
bool searchhash(Hashtable* hash, int key, int& locn) {
    int hashindex = key % MAX;
    node* search = hash->hashtable[hashindex]->first;
    while (search != NULL) {
        if (search->data == key) {
            locn = hashindex;
            return true;
        }
        search = search->link;
    }
    return false;
}

// Function to display the hash table
void display(Hashtable* hash) {
    for (int walker = 0; walker < MAX; walker++) {
        node* temp = hash->hashtable[walker]->first;
        cout << "Bucket " << walker << ": ";
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->link;
        }
        cout << endl;
    }
}

// Main function
int main() {
    Hashtable* hash = createhashtable(); // Initialize hashtable
    int choice, data, target, locn;

    do {
        cout << "Enter" << endl;
        cout << "1. For create Table" << endl;
        cout << "2. For insert node" << endl;
        cout << "3. For delete node" << endl;
        cout << "4. For search node" << endl;
        cout << "5. For display" << endl;
        cout << "6. For exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Creating a new table and deleting old table if exists
                delete hash; // Clean up the old hashtable
                hash = createhashtable();
                cout << "Hash table created" << endl;
                break;
            case 2:
                cout << "Enter a data to insert : ";
                cin >> data;
                inserthash(hash, data);
                cout << "The data is inserted" << endl;
                break;
            case 3:
                cout << "Enter a num to delete : ";
                cin >> data;
                if (deletehash(hash, data))
                    cout << "The data is deleted" << endl;
                else
                    cout << "The data is not deleted" << endl;
                break;
            case 4:
                cout << "Enter a num to search : ";
                cin >> target;
                if (searchhash(hash, target, locn))
                    cout << "The data is at location " << locn << endl;
                else
                    cout << "The data is not found" << endl;
                break;
            case 5:
                display(hash);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    // Clean up hashtable memory before exiting
    for (int i = 0; i < MAX; i++) {
        node* temp = hash->hashtable[i]->first;
        while (temp != NULL) {
            node* toDelete = temp;
            temp = temp->link;
            delete toDelete;
        }
        delete hash->hashtable[i]; // Free nodehead memory
    }
    delete hash; // Free hashtable memory

    return 0;
}
