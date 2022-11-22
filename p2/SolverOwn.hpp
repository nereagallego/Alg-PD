#pragma once

#include <minisat/core/Solver.h>
#include "Tablero.hpp"


class SolverOwn{
    Minisat::Solver resolutor;
    Tablero _t;
    int _rows;
    int _columns;
    int _values;
    
    
public:

    Minisat::Var toVar(int row, int column, int value, int _rows, int _columns, int _values);

    SolverOwn(const string file);

    void initVariables();

    // ∀(i,j) ∈ {filas x columnas} : solo puede haber un valor por celda
    // ∀(v1,v2) ∈ {0..9,0..9} ~v1 ∨ ~v2
    void exactamenteUnValor(Minisat::vec<Minisat::Lit> const& literales);

    // no hay valores duplicador
    void noValoresDuplicados();

    // comprueba que haya al menos un valor en cada celda
    void unValorPorCelda();

    bool resuelve();

    bool crearTablero(const Tablero &b);

    Tablero obtenerSolucion();

    Tablero getTablero();

};

bool esValido(const Tablero &b);