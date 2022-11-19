#include "Solver.hpp"

Solver::Solver(const string file){
    Tablero t(file);
    crearTablero(t);
    _rows = t.getRows();
    _columns = t.getColumns();
    _values = t.getValues();
    initVariables();
    unValorPorCelda();
    noValoresDuplicados();
}

Minisat::Var toVar(int row, int column, int value, int _rows, int _columns, int _values) {
    assert(row >= 0 && row < _rows && "Attempt to get var for nonexistant row");
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
                literals.push(Minisat::mkLit(toVar(row, column, value,_rows, _columns, _values)));
            }
            exactamenteUnValor(literals);
        }
    }
    // In each column, for each value, forbid two rows sharing that value
    for (int column = 0; column < _columns; ++column) {
        for (int value = 0; value < _values; ++value) {
            Minisat::vec<Minisat::Lit> literals;
            for (int row = 0; row < _rows; ++row) {
                literals.push(Minisat::mkLit(toVar(row, column, value, _rows, _columns, _values)));
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
                        literals.push(Minisat::mkLit(toVar(r + rr, c + cc, value, _rows, _columns, _values)));
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
                literals.push(Minisat::mkLit(toVar(row, column, value, _rows, _columns, _values)));
            }
            exactamenteUnValor(literals);
        }
    }
}

bool Solver::resuelve() {
    return resolutor.solve();
}


bool esValido(Tablero const& b) {
    if (b.size() != b.getRows()) {
        return false;
    }
    for (int row = 0; row < b.getRows(); ++row) {
        if (b.tablero[row].size() != b.getRows()) {
            return false;
        }
        for (int col = 0; col < b.getColumns(); ++col) {
            auto value = b.tablero[row][col];
            if (value < 0 || value > b.getValues()) {
                return false;
            }
        }
    }
    return true;
}

bool Solver::crearTablero(Tablero const& b) {
    assert(esValido(t) && "Provided board is not valid!");
  //  assert(is_valid(b) && "Provided board is not valid!");
    bool ret = true;
    for (int row = 0; row < _rows; ++row) {
        for (int col = 0; col < _columns; ++col) {
            auto value = b.tablero[row][col];
            if (value != 0) {
                ret &= resolutor.addClause(Minisat::mkLit(toVar(row, col, value - 1, _rows, _columns, _values)));
            }
        }
    }
    return ret;
}

Tablero Solver::obtenerSolucion(){
   // Tablero t(file);

    for (int row = 0; row < _rows; ++row) {
        for (int col = 0; col < _columns; ++col) {
            int found = 0;
            for (int val = 0; val < _values; ++val) {
                if (resolutor.modelValue(toVar(row, col, val, _rows, _columns, _values)).isTrue()) {
                    ++found;
                    t.tablero[row][col] = val + 1;
                }
            }
            assert(found == 1 && "The SAT solver assigned one position more than one value");
            (void)found;
        }
    }
    return t;
}