#include <iostream>
using namespace std;

// Disjoint set structure
struct Node {
    int parent; // Parent of the node
    int rank;   // Rank of the node
};

// DisjointSet class
class DisjointSet {
private:
    Node* sets;    // Array of nodes to represent each set
    int size;      // Size of the array

public:
    // Constructor to initialize n elements
    DisjointSet(int n) {
        size = n;
        sets = new Node[n];
        makeSet();
    }

    // Initialize each element to be its own set
    void makeSet() {
        for (int i = 0; i < size; i++) {
            sets[i].parent = i;  // Each element is its own parent
            sets[i].rank = 0;    // Initial rank is 0
        }
    }

    // Find function with path compression
    int find(int x) {
        if (sets[x].parent != x) {
            sets[x].parent = find(sets[x].parent);  // Path compression
        }
        return sets[x].parent;
    }

    // Link function to attach two sets based on rank
    void link(int xRoot, int yRoot) {
        if (sets[xRoot].rank > sets[yRoot].rank) {
            sets[yRoot].parent = xRoot;
        } else if (sets[xRoot].rank < sets[yRoot].rank) {
            sets[xRoot].parent = yRoot;
        } else {
            sets[yRoot].parent = xRoot;
            sets[xRoot].rank++;
        }
    }

    // Union function to merge two sets
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if (xRoot != yRoot) {
            link(xRoot, yRoot);
        }
    }

    // Display function to show the parent array and ranks
    void display() {
        cout << "Element: ";
        for (int i = 0; i < size; i++) {
            cout << i << " ";
        }
        cout << "\nParent:  ";
        for (int i = 0; i < size; i++) {
            cout << sets[i].parent << " ";
        }
        cout << "\nRank:    ";
        for (int i = 0; i < size; i++) {
            cout << sets[i].rank << " ";
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~DisjointSet() {
        delete[] sets;
    }
};

int main() {
    int n = 7;  // Number of elements in the disjoint set
    DisjointSet ds(n);

    // Perform some union operations
    ds.unionSets(0, 1);
    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(4, 5);
    ds.unionSets(6, 5);
    
    // Perform find operations
    cout << "Find(0): " << ds.find(0) << endl;
    cout << "Find(3): " << ds.find(3) << endl;
    cout << "Find(6): " << ds.find(6) << endl;
    
    // Display the internal state of the disjoint set
    ds.display();
    
    return 0;
}