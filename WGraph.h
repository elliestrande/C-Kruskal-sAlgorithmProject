
/*
Ellie Strande
2371288
strande@chapman.edu
CPSC 350-01
A6: Spanning the Gamut
*/

#ifndef WGraph_H
#define WGraph_H

#include <iostream>
#include <cstdlib>
#include <deque>
#include <set>
#include <stack> 
#include <iostream>
#include <limits>

using namespace std;
typedef unsigned int VertexID;

//a weighted, undirected WGraph implemented with adjacency matrix

class WGraph{
    public:
        WGraph(); //default constructor
        WGraph(unsigned int sz); //overloaded constructor
        ~WGraph(); //default deconstructor
        void addEdge(VertexID i, VertexID j, double w); //adds an edge
        void removeEdge(VertexID i, VertexID j); //removes an edge
        bool areAdjacent(VertexID i, VertexID j); //checks if adjacent
        double cheapestCost(VertexID i, VertexID j);
        void calcFW();

        void computeMST(); //computes the MST of the graph
        void setArr(double** arr); //sets the graph's array

    private:
        double** m_adj; //is there an edge between two vertices and what's the weight of the edge
        double** m_conn; //is there a path between a start and a finish and whats the cost
        unsigned int N; //nodes in WGraph (fixed)

        string m_infile; //name of the input file
        double** valArr; //2d array of weights
};
#endif