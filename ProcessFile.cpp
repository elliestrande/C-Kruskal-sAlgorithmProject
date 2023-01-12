/*
Ellie Strande
2371288
strande@chapman.edu
CPSC 350-01
A6: Spanning the Gamut
*/

#include "WGraph.h"
#include "ProcessFile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//default constructor
ProcessFile::ProcessFile(){
    m_infile = "unknown";
}

//default deconstructor
ProcessFile::~ProcessFile(){

}

//reads in the input file to create graph and MST
WGraph ProcessFile::readFile(string file){
    m_infile = file;
    int rowCount = 0;
    int colCount = 0;
    string temp;
    string contentsOfLine;
    int N;

    //open input file
    ifstream inFile;
    inFile.open(m_infile);

    if(inFile.is_open()){
        getline(inFile,contentsOfLine);
        if (rowCount == 0){
            N = stod(contentsOfLine);
            //creates a new graph with N size
            G = WGraph(N);
            //creates new array to store dooubles from input
            arr = new double*[N];
            for(int i = 0; i < N; ++i){
                arr[i] = new double[N];
            }
            ++rowCount;
        }
        //fills the array with the doubles from the input file
        for (int i = 0; i < N; i++){
            while(getline(inFile,contentsOfLine)){
                //creates a new stringstream 
                stringstream s(contentsOfLine);
                for (int j = 0; j < N; j++){
                    while(getline(s, temp, ' ')){
                        arr[i][j] = stod(temp);
                        break;
                    }
                }
                break;
            }
        }
        //closes the input file
        inFile.close();
        //sets the graph's array to the array created from the input file 
        G.setArr(arr);
        //computes the graph's MST
        G.computeMST();
    }
    return G;
}
