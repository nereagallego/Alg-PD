#pragma once

#include "minisat-master/minisat/core/Solver.h"

static const int _rows = 9;
static const int _columns = 9;
static const int _values = 9;
class Solver{
    Minisat::Solver resolutor;
    
public:

    Solver();

    void initVariables();

    // ∀(i,j) ∈ {filas x columnas} : solo puede haber un valor por celda
    // ∀(v1,v2) ∈ {0..9,0..9} ~v1 ∨ ~v2
    void exactamenteUnValor(Minisat::vec<Minisat::Lit> const& literales);

    // no hay valores duplicador
    void noValoresDuplicados();

    // comprueba que haya al menos un valor en cada celda
    void unValorPorCelda();

    bool solve();

};