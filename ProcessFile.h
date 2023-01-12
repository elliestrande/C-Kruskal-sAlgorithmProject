/*
Ellie Strande
2371288
strande@chapman.edu
CPSC 350-01
A6: Spanning the Gamut
*/

#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include "WGraph.h"
#include <iostream>

using namespace std;

class ProcessFile{
    public:
        ProcessFile(); //default constructor
        ~ProcessFile(); //default deconstructor
        WGraph readFile(string file); //reads in the input file to create the graph and MST

    private:
        string m_infile; //name of the input file
        double** arr; //2d array of weights
        WGraph G;
};
#endif
