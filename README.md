# Random Maze Generator using Disjoint Sets Data-Structure

Google colab [notebook](https://colab.research.google.com/drive/15ZASwkjss7a_Pg8qqG4KitJWukR0nDj7?usp=sharing).

This is a simple implementation of a random maze generator using [disjoint sets data-structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure). This project is a part of the course [Advanced Algorithms and Parallel Programming](https://www4.ceda.polimi.it/manifesti/manifesti/controller/ManifestoPublic.do?EVN_DETTAGLIO_RIGA_MANIFESTO=evento&aa=2022&k_cf=225&k_corso_la=481&k_indir=T2A&codDescr=095946&lang=EN&semestre=1&idGruppo=4475&idRiga=281839) at Polytechnic University of Milan.

![Example of a generated maze.](https://imgur.com/FPnnuJr.jpg)

## Theory and Implementation

The algorithm is based on the Disjoint Sets data-structure. To have an idea of what it is we first need to define what are  **disjoint sets**. Two sets are called **disjoints sets** if they don't have any element in common. The **disjoint sets data-structure** is a data-structure that allows us to perform the following operations:
- Adding new sets to the disjoint set
- Merging disjoint sets to a single disjoint set using the **union** operation
- Finding representative of a disjoint set using the **find** operation (the representative is the element of the set that is used to identify the set, it is usually the first element added to the set)
- Check if two sets are disjoint or not

The data structure used to implement the disjoint sets data-structure is an array of integers. Each element of the array represents a node of the disjoint sets data-structure. The value of each element is the index of the parent of the node. If the value of the element is negative it means that the node is a representative of a disjoint set. The absolute value of the element is the size of the set. The size of the set is used to keep the tree balanced. The algorithm used to merge two disjoint sets is the **union by rank** algorithm. The algorithm used to find the representative of a set is the **path compression** algorithm. The latter is used to reduce the height of the tree and to make the find operation faster.

## Testing the Algorithm
To test whether the algorithm works correctly we can use a Depth First Search algorithm. The algorithm is based on the ![Trémaux's algorithm](https://www.wikiwand.com/en/Maze_solving_algorithm#Tr%C3%A9maux's_algorithm). The algorithm uses two main data structure:
1. A stack to keep track of the path and to backtrack when necessary
2. An array of boolean to keep track of the visited nodes

The algorithm starts from the starting node and it explores the maze until it reaches the end node. If the algorithm reaches a dead end it backtracks until it finds a node that has an unvisited neighbour. The algorithm stops when it reaches the end node. At each node it choose the neighbour to visit in the following order: left, top, bottom, right. If the algorithm reaches the end node it means that the maze is solvable. If the algorithm reaches a dead end it means that the maze is not solvable.

## Instructions
To compile the code you need to have the [CMake](https://cmake.org/) build system installed. To compile the code you need to run the following command:
```bash
make
```

To run the code you need to run the following command:
```bash
output/main <rows> <cols>
```
