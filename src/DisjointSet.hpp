/**
 * Implementation of Disjoint Set Data Structure
 * 
 * @author Filippo Scaramuzza
 * @version 1.0 17/10/2022
*/

#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP

class DisjointSet {
    private:
        /*
            If the element is a representative, the value is negative and
            the absolute value is the number of elements in the set.
            Otherwise, the value is the index of the parent element.
        */
        int *parent;
        /*
            The number of total elements
        */
        int n;
    public:
        /**
         * Constructor
         * 
         * @param n the number of elements
        */
        DisjointSet(int n);
        
        /**
         * Destructor
        */
        ~DisjointSet();

        /**
         * Find the representative of the set containing the element
         * 
         * @param x the element
         * @return the representative of the set containing the element
        */
        int Find(int x);

        /**
         * Merge the sets containing the elements x and y
         * 
         * @param x the first element
         * @param y the second element
        */
        void Union(int x, int y);
};

#endif