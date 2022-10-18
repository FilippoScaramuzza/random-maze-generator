/**
 * Maze Generator
 * 
 * This program generates a maze using the disjoint set data structure.
 * 
 * @author Filippo Scaramuzza
 * @version 1.0 17/10/2022
*/

#ifndef MAZE_HPP
#define MAZE_HPP

#include "DisjointSet.hpp"
#include <vector>

using namespace std;

class Maze {
    private:
        /*
            The number of rows
        */
        int rows;
        /*
            The number of columns
        */
        int cols;
        /*
            The number of total cells
        */
        int n;
        /* 
            The number of walls
        */
        int w;
        
        /*
            The disjoint set data structure
            Maze cells are represented as elements of the disjoint set
        */
        DisjointSet *disjointSet;

        /*
            Array of walls
        */
        bool *walls;
        
    public:
        /**
         * Constructor
         * 
         * @param rows the number of rows
         * @param cols the number of columns
        */
        Maze(int rows, int cols);
        
        /**
         * Destructor
        */
        ~Maze();
        
        /**
         * Generate the maze
        */
        void Generate();
        
        /**
         * Print the maze
        */
        void Print(vector<int> path);

        /**
         * Depth First Search algorithm to check if the maze is solvable
        */
        bool DepthFirstSearch();

        /**
         * Check if a cell x is the neighbor of a cell y
        */
        bool IsNeighbor(int x, int y);
};

#endif