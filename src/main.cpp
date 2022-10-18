/*
    Maze Generator

    This program generates a maze using the disjoint set data structure.

    @author Filippo Scaramuzza
    @version 1.0 17/10/2022
*/

#include "DisjointSet.hpp"
#include "Maze.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int rows, cols;

    if(argc != 3) {
        cout << "Usage: ./maze rows cols" << endl;
        return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    Maze maze(rows, cols);

    maze.Generate();

    bool dfs = maze.DepthFirstSearch();

    if(dfs) {
        cout << "The maze is solvable :D" << endl;
    } else {
        cout << "The maze is not solvable D:" << endl;
    }


    return 0;
}