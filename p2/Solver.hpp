#pragma once

#include "minisat-master/minisat/core/Solver.h"
#include "tablero/Tablero.hpp"


class Solver{
    Minisat::Solver resolutor;
    Tablero t;
    int _rows;
    int _columns;
    int _values;
    
    
public:

    Solver(const string file);

    void initVariables();

    // ∀(i,j) ∈ {filas x columnas} : solo puede haber un valor por celda
    // ∀(v1,v2) ∈ {0..9,0..9} ~v1 ∨ ~v2
    void exactamenteUnValor(Minisat::vec<Minisat::Lit> const& literales);

    // no hay valores duplicador
    void noValoresDuplicados();

    // comprueba que haya al menos un valor en cada celda
    void unValorPorCelda();

    bool resuelve();

    bool crearTablero(Tablero const&);

    Tablero obtenerSolucion();


};