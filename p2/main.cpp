#include <iostream>
#include <stdlib.h>
#include "tablero/Tablero.hpp"
#include "Solver.hpp"

using namespace std;

int main(int argc, char** argv) {
    Tablero t("sudoku_1.txt");

    cout << "TABLERO" << endl;
    cout << t << endl;
}