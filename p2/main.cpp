#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "Tablero.hpp"
#include "SolverOwn.hpp"

using namespace std;

int main(int argc, char** argv) {
    string board_file = argv[1];
    
    auto t1 = std::chrono::high_resolution_clock::now();
    SolverOwn s(board_file);
    Tablero t = s.getTablero();

    if (!s.crearTablero(t)) {
        std::clog << "There is a contradiction in the parsed!\n";
        return 2;
    }
    if (s.resuelve()) {
        std::chrono::duration<double, std::milli> time_taken = std::chrono::high_resolution_clock::now() - t1;
        std::clog << "Solution found in " << time_taken.count() << " ms\n" << endl;
        Tablero solution = s.obtenerSolucion();
        cout << solution << endl;
    } else {
        std::clog << "Solving the provided parsed is not possible\n";
    }
}