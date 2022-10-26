#include "Solver.hpp"

Solver::Solver(){
    initVariables();
  //  one_square_one_value();
  //  non_duplicated_values();
}

void Solver::initVariables(){
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        for (int v = 0; v < values; ++v) {
          static_cast<void>(resolutor.newVar());
        }
      }
    }
}

void Solver::unValorPorCelda(Minisat::vec<Minisat::Lit> const& literales){
    resolutor.addClause(literales);
    for (size_t i = 0; i < literales.size(); ++i) {
        for (size_t j = i + 1; j < literales.size(); ++j) {
            resolutor.addClause(~literales[i], ~literales[j]);
        }
    }
}

void Solver::noValoresDuplicados(){
    
}