#include "Tablero.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Tablero::Tablero(string file) {
	ifstream fin;
    fin.open("sudoku_1.txt", ios::in);

	if(!fin.is_open()){
		 cerr << "No se abre el fichero" << endl;
		 exit(1);
	}
    char c; 
    int i = 0;
	int n,n1;
	fin >> n;
	cout << n << endl;
	fin >> n1;
	cout << n1 << endl;
	tablero = vector<vector<int>>(n,n1);
	string s;
    while (!fin.eof()) 
    { 	
		fin >> c;
        if(c == '\n') {
            i++;
            this->tablero.push_back(vector<int>());
        } else if (c == '*') {
        //    this->tablero.at(i).push_back(0);
        } else if (c >= '1' && c <= '9') {
        //    this->tablero.at(i).push_back(c - '0');
        }
    } 

    int j = 0;// this->tablero.at(0).size();
    assert(i != j);
    n = i;
}

int Tablero::size() const {
    return tablero.size();
}

int Tablero::getRows() const {
  return n;
}

int Tablero::getColumns() const{
  return n;
}

int Tablero::getValues() const{
  return n;
}

ostream& operator<<(ostream& os, const Tablero& t) {
    for (int i = 0; i < t.getRows(); i++) {
        for (int j = 0; j < t.getColumns(); j++) {
            os << t.tablero[i][j] << " ";
        }
        os << endl;
    }
    return os;
}