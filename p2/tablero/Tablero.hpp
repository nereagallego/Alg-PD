#pragma once

#include <iostream>
#include <vector>
#include <string.h>
#include <assert.h>

using namespace std;

class Tablero {
    int n;
public:
    vector<vector<int>> tablero;

    Tablero();
    Tablero(string file);
    int size() const;
    int getRows() const;
    int getColumns() const;
    int getValues() const;

    friend ostream& operator<<(ostream& os, const Tablero& t);
};
