/*
Ellie Strande
2371288
strande@chapman.edu
CPSC 350-01
A6: Spanning the Gamut
*/

#include "WGraph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//default constructor
WGraph::WGraph(){
    N = 0;
    m_adj = NULL;
    m_conn = NULL;
}

//overloaded constructor
WGraph::WGraph(unsigned int sz){
    N = sz;
    //allocate sz*sz adj matrix
    m_adj = new double*[sz];
    m_conn = new double*[sz];
    for(int i = 0; i < N; ++i){
        m_adj[i] = new double[sz];
        m_conn[i] = new double[sz];
    }
    //start with edges
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            m_adj[i][j] = std::numeric_limits<double>::max();
            m_conn[i][j] = std::numeric_limits<double>::max();
        }
    }
}

//default deconstructor
WGraph::~WGraph(){
    //release memory
}

//adds an edge to the graph
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < N && j < N){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

//removes an edge from the graph
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < N && j < N){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

//checks if two vertices are adjacent
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < N; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < N; ++source){ //source = starting point
      for(int sink = 0; sink <N; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}

//compute MST for the graph using Kruskal's algorithm
void WGraph::computeMST(){
    
    //array that stores the cheapest vars
    double* arrLowest = new double[N];
    double lowestVal = 100.0;
    double sumMST = 0;
    int col = 0;

    //sorts through the array to find the cheapest connection of each row
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            //if the value is the lowest value in the row & does not equal 0 sets to lowest value
            if((valArr[i][j] < lowestVal) && (valArr[i][j] != 0)){
                lowestVal = valArr[i][j];
            }
        }
        //adds the lowest value from the row to the array of lowest values
        arrLowest[col] = lowestVal;
        ++col;
        //adds the lowest value to the MST sum
        sumMST += lowestVal;
        //resets the lowestVal value for the next row
        lowestVal = 100.0;
    }

    //prints out the total cost of the MST
    cout << "Cost of the MST: " << sumMST << endl;
    cout << " " << endl;

    //creates a new adjacency matrix representation of the MST
    //creates a new 2D array to represent the adjacency matrix
    double** newArr = new double*[N];
    for(int i = 0; i < N; ++i){
        newArr[i] = new double[N];
    }

    //iterates through the new array to input the MST values
    int k = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            //if the location of the MST value is found, it is added to the new array
            if(arrLowest[k] == valArr[i][j]){
                newArr[i][j] = arrLowest[k];
                break;
            //else, the value is made 0.0
            } else {
                newArr[i][j] = 0.0;
            }
        }
        ++k;
    }

    //prints the adjacency matrix representation of the MST 
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(j == 0){
                if (newArr[i][j] == 0.0){
                    cout << "0.0" << ' ';  
                }
                else {
                    cout << newArr[i][j] << ' ';  
                }
            } else if (j == N-1){
                if (newArr[i][j] == 0.0){
                    cout << "0.0" << endl;  
                } else {
                    cout << newArr[i][j] << endl;
                }
            } else {
                if (newArr[i][j] == 0.0){
                    cout << "0.0" << ' ';  
                } else {
                    cout << newArr[i][j] << ' ';
                }
            }
        }
    }
}

//sets the graph's array member variable
void WGraph::setArr(double** arr){
    valArr = arr;
}
