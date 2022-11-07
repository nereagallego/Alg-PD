#include "Solver.hpp"

Solver::Solver(){
    initVariables();
    unValorPorCelda();
    noValoresDuplicados();
}

Minisat::Var toVar(int row, int column, int value) {
    assert(row >= 0 && row < _rows    && "Attempt to get var for nonexistant row");
    assert(column >= 0 && column < _columns && "Attempt to get var for nonexistant column");
    assert(value >= 0 && value < _values   && "Attempt to get var for nonexistant value");
    return row * _columns * _values + column * _values + value;
}

void Solver::initVariables(){
    for (int i = 0; i < _rows; ++i) {
      for (int j = 0; j < _columns; ++j) {
        for (int v = 0; v < _values; ++v) {
          static_cast<void>(resolutor.newVar());
        }
      }
    }
}

void Solver::exactamenteUnValor(Minisat::vec<Minisat::Lit> const& literales){
    resolutor.addClause(literales);
    for (size_t i = 0; i < literales.size(); ++i) {
        for (size_t j = i + 1; j < literales.size(); ++j) {
            resolutor.addClause(~literales[i], ~literales[j]);
        }
    }
}

void Solver::noValoresDuplicados(){
    for (int row = 0; row < _rows; ++row) {
        for (int value = 0; value < _values; ++value) {
            Minisat::vec<Minisat::Lit> literals;
            for (int column = 0; column < _columns; ++column) {
                literals.push(Minisat::mkLit(toVar(row, column, value)));
            }
            exactamenteUnValor(literals);
        }
    }
    // In each column, for each value, forbid two rows sharing that value
    for (int column = 0; column < _columns; ++column) {
        for (int value = 0; value < _values; ++value) {
            Minisat::vec<Minisat::Lit> literals;
            for (int row = 0; row < _rows; ++row) {
                literals.push(Minisat::mkLit(toVar(row, column, value)));
            }
            exactamenteUnValor(literals);
        }
    }
    // Now forbid sharing in the 3x3 boxes
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            for (int value = 0; value < _values; ++value) {
                Minisat::vec<Minisat::Lit> literals;
                for (int rr = 0; rr < 3; ++rr) {
                    for (int cc = 0; cc < 3; ++cc) {
                        literals.push(Minisat::mkLit(toVar(r + rr, c + cc, value)));
                    }
                }
                exactamenteUnValor(literals);
            }
        }
    }
}

void Solver::unValorPorCelda() {
    for (int row = 0; row < _rows; ++row) {
        for (int column = 0; column < _columns; ++column) {
            Minisat::vec<Minisat::Lit> literals;
            for (int value = 0; value < _values; ++value) {
                literals.push(Minisat::mkLit(toVar(row, column, value)));
            }
            exactamenteUnValor(literals);
        }
    }
}

bool Solver::solve() {
    return resolutor.solve();
}