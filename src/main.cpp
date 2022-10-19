/*
    Maze Generator

    This program generates a maze using the disjoint set data structure.

    @author Filippo Scaramuzza
    @version 1.0 17/10/2022
*/

#include "DisjointSet.hpp"
#include "Maze.hpp"
// #include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    int rows, cols;

    if(argc != 3) {
        // cout << "Usage: ./maze rows cols" << endl;
        printf("Usage: ./maze rows cols\n");
        return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    Maze maze(rows, cols);

    maze.Generate();

    bool dfs = maze.DepthFirstSearch();

    if(dfs) {
        // cout << "The maze is solvable :D" << endl;
        printf("The maze is solvable :D\n");
    } else {
        // cout << "The maze is not solvable D:" << endl;
        printf("The maze is not solvable D:\n");
    }


    return 0;
}