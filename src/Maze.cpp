/**
 * Maze Generator
 *
 * This program generates a maze using the disjoint set data structure.
 *
 * @author Filippo Scaramuzza
 * @version 1.0 17/10/2022
 */

#include "Maze.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

Maze::Maze(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    n = rows * cols;
    w = (cols - 1) * rows + (rows - 1) * cols;
    disjointSet = new DisjointSet(n);
    walls = new bool[w];
    for (int i = 0; i < w; i++) {
        walls[i] = true;
    }
}

Maze::~Maze() {
    delete disjointSet;
}

void Maze::Generate() {

    int start = 0;
    int goal = this->n - 1;

    // Create disjoint sets representing groups of neighboring connected cells
    this->disjointSet = new DisjointSet(this->n);

    // Srand for random number generation
    srand(time(NULL));

    while(this->disjointSet->Find(start) != this->disjointSet->Find(goal)) {
        // Select a random wall, from 0 to (cols - 1)*rows -1 it's a vertical wall, otherwise it's a horizontal wall
        int w = rand() % this->w;
        walls[w] = false;

        int x, y;

        if (w < (cols - 1) * rows)
        {
            // Vertical wall
            x = w + (int)(w / (cols - 1));
            y = x+1;
        }
        else
        {
            // Horizontal wall
            x = w - (rows * (cols - 1));
            y = x + cols;
        }

        if(this->disjointSet->Find(x) != this->disjointSet->Find(y)) {
            this->disjointSet->Union(x, y);
            cout << "Union: " << x << " " << y << " from wall " << w << endl;
        }
    }
}

void Maze::Print(std::vector<int> path) {
    // Draw the first row of the maze checking only vertical walls
    // The array is ordered having first the vertical walls and then the horizontal walls
    for (int i = 0; i < cols; i++) {
        cout << "+---";
    }
    cout << "+" << endl;

    // Draw the rest of the maze
    for (int i = 0; i < rows; i++) {
        // Draw the left wall
        cout << "|";
        for (int j = 0; j < cols; j++) {

            int cell = i * cols + j;

            // Draw the bottom wall
            if (walls[(cols-1)*i + j] || j == cols - 1) {
                if(find(path.begin(), path.end(), cell) != path.end()) {
                    cout << " # |";
                }
                else {
                    cout << "   |";
                }
            } else {
                if(find(path.begin(), path.end(), cell) != path.end()) {
                    cout << " #  ";
                }
                else {
                    cout << "    ";
                }
            }
        }
        cout << endl;

        // Draw the bottom wall
        for (int j = 0; j < cols; j++) {
            if (walls[(cols-1)*rows + i*cols + j] || i == rows - 1) {
                cout << "+---";
            } else {
                cout << "+   ";
            }
        }
        cout << "+" << endl;
    }
}

bool Maze::IsNeighbor(int x, int y) {

    if(x < 0 || y < 0 || x >= this->n || y >= this->n) {
        return false;
    }

    if (x == y+1 || x == y-1) {
        // Check if x and y are on the same row, otherwise it's false
        if ((int)x / cols == (int)y / cols) {
            if(x < y) { // x is the left cell
                return !walls[x - (int)(x / (cols))];
            } else { // y is the left cell
                return !walls[y - (int)(y / (cols))];
            }
        }
        else {
            return false;
        }
    }

    if(x == y+cols || x == y-cols) {
        // Check that they belong to different but adjacent rows
        if (x / cols == y / cols + 1 || x / cols == y / cols - 1) {
            // Check if the wall between x and y is still present
            if (x < y) {
                return !walls[x + (cols-1)*rows];
            } else {
                return !walls[y + (cols-1)*rows];
            }
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}

bool Maze::DepthFirstSearch() {
    
    stack<int> frontier; // Stack for the DFS
    bool visited[this->n]; // Array to keep track of the visited cells
    for (int i = 0; i < this->n; i++) {
        visited[i] = false;
    }

    // Path from start to goal (using map data structure)
    map<int, int> path;

    // Start from the first cell
    frontier.push(0);
    visited[0] = true;

    int currentCell = 0;
    int childCell = 0;

    while(currentCell != this->n - 1) {
        currentCell = frontier.top();
        frontier.pop();

        // Check for Right cell
        if(IsNeighbor(currentCell, currentCell-1)) {
            childCell = currentCell-1;
            if(!visited[childCell]) {
                visited[childCell] = true;
                frontier.push(childCell);

                // Add the child cell to the path
                path[childCell] = currentCell;
            }
        }

        // Check for Top cell
        if(IsNeighbor(currentCell, currentCell-this->cols)) {
            childCell = currentCell-this->cols;
            if(!visited[childCell]) {
                visited[childCell] = true;
                frontier.push(childCell);

                // Add the child cell to the path
                path[childCell] = currentCell;
            }
        }

        // Check for Bottom cell
        if(IsNeighbor(currentCell, currentCell+this->cols)) {
            childCell = currentCell+this->cols;
            if(!visited[childCell]) {
                visited[childCell] = true;
                frontier.push(childCell);

                // Add the child cell to the path
                path[childCell] = currentCell;
            }
        }

        // Check for Left cell
        if(IsNeighbor(currentCell, currentCell+1)) {
            childCell = currentCell+1;
            if(!visited[childCell]) {
                visited[childCell] = true;
                frontier.push(childCell);

                // Add the child cell to the path
                path[childCell] = currentCell;
            }
        }

        if(frontier.size() == 0) {
            return false;
        }
    }

    // Reconstruct the path
    int current = this->n - 1;
    map<int, int> fwdPath;

    while(current != 0) {
        fwdPath[path[current]] = current;
        current = path[current];
    }

    // Convert path to a vector
    vector<int> pathVector;
    for (map<int, int>::iterator it = fwdPath.begin(); it != fwdPath.end(); ++it) {
        pathVector.push_back(it->first);
    }

    pathVector.push_back(this->n - 1);

    this->Print(pathVector);

    return true;
}