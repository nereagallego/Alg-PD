#pragma once

#include "minisat-master/minisat/core/Solver.h"

class Solver{
    Minisat::Solver resolutor;
    const int rows = 9;
    const int columns = 9;
    const int values = 9;
public:

    Solver();

    void initVariables();

    // ∀(i,j) ∈ {filas x columnas} : solo puede haber un valor por celda
    // ∀(v1,v2) ∈ {0..9,0..9} ~v1 ∨ ~v2
    void unValorPorCelda(Minisat::vec<Minisat::Lit> const& literales);

    // no hay valores duplicador
    void noValoresDuplicados();
};