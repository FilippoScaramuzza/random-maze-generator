/**
 * Implementation of Disjoint Set Data Structure
 * 
 * @author Filippo Scaramuzza
 * @version 1.0 17/10/2022
*/

#include "DisjointSet.hpp"

DisjointSet::DisjointSet(int n) {
    
    this->n = n;
    parent = new int[n];

    for(int i = 0; i < n; i++) {
        parent[i] = -1; // Each element is a representative of itself (a set of size 1)
    }
}

DisjointSet::~DisjointSet() {
    delete[] parent;
}

int DisjointSet::Find(int x) {
    if(parent[x] < 0) { // If the element is a representative
        return x;
    } else {
        // Path compression: make the parent of x the representative of 
        // the set containing x, in a recursive way
        return parent[x] = Find(parent[x]);
    }
}

void DisjointSet::Union(int x, int y) {
    int xRoot = Find(x); // Find the representative of the set containing x
    int yRoot = Find(y); // Find the representative of the set containing y

    if(xRoot == yRoot) { // If x and y are already in the same set
        return;
    }

    if(parent[xRoot] < parent[yRoot]) { // If the size of the set containing x is greater than the size of the set containing y
        parent[xRoot] += parent[yRoot]; // Add the size of the set containing y to the size of the set containing x
        parent[yRoot] = xRoot; // Make the representative of the set containing y the representative of the set containing x
    } else {
        parent[yRoot] += parent[xRoot]; // Add the size of the set containing x to the size of the set containing y
        parent[xRoot] = yRoot; // Make the representative of the set containing x the representative of the set containing y
    }
}