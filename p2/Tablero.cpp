#include "Tablero.hpp"


using namespace std;

int Tablero::size() const {
    return tablero.size();
}

int Tablero::getRows() const {
  return _n;

}

int Tablero::getColumns() const{
  return _n;
}

int Tablero::getValues() const{
  return _n;
}

ostream& operator<<(ostream& os, const Tablero& t) {
    for (int i = 0; i < t.getRows(); i++) {
        for (int j = 0; j < t.getColumns(); j++) {
            os << t.tablero[i][j] << " ";
        }
        os << endl;
    }
    os << t.getRows() << " " << t.getColumns() << " " << t.getValues() << endl;
    return os;
}