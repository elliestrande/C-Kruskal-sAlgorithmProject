/*
Ellie Strande
2371288
strande@chapman.edu
CPSC 350-01
A6: Spanning the Gamut
*/

#include <iostream>
#include "WGraph.h"
#include "ProcessFile.h"
using namespace std;

int main(int argc, char* argv[]){
    /*
    take in name of file that contains specification for an undirected,
    weighted grapth as a command line argument
    */
    ProcessFile f = ProcessFile();
    WGraph G = f.readFile(argv[1]);

    return 0;
}