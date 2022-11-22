#pragma once

#include <iostream>
#include <vector>
#include <string.h>
#include <assert.h>
#include <fstream>

using namespace std;

class Tablero {
    int _n;

private:
    bool is_number(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
public:
    vector<vector<int>> tablero;

    Tablero() {}

    Tablero(string file){
        ifstream fin;
        fin.open(file, ios::in);

        if(!fin.is_open()){
            cerr << "No se abre el fichero" << endl;
            exit(1);
        }
        char c; 
        int i = 0;
        int n,n1,n2;
        fin >> n;
        fin >> n1;
        vector<vector<int>> t(n, vector<int>(n1,0));
        tablero = t;
        string s;
        _n = n;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n1; j ++){
                fin >> s;
                if(is_number(s)){
                    tablero[i][j] = std::stoi(s);
                }
            }
        }

        assert(n == n1);
    }
    int size() const;

    int getRows() const;

    int getColumns() const;

    int getValues() const;

};

ostream& operator<<(ostream& os, const Tablero& t);