#include "Tablero.hpp"


using namespace std;

Tablero::Tablero(string file) {
	ifstream fin;
    fin.open("sudoku_1.txt", ios::in);

	if(!fin.is_open()){
		 cerr << "No se abre el fichero" << endl;
		 exit(1);
	}
    char c; 
    int i = 0;
	int n,n1;
	fin >> n;
	cout << n << endl;
	fin >> n1;
	cout << n1 << endl;
    vector<vector<int>> t(n, vector<int>(n1,0));
	tablero = t;
	string s;
    _n = n;
    // while (!fin.eof()) 
    // { 	
	// 	fin >> c;
    //     if(c == '\n') {
    //         i++;
    //         this->tablero.push_back(vector<int>());
    //     } else if (c == '*') {
    //     //    this->tablero.at(i).push_back(0);
    //     } else if (c >= '1' && c <= '9') {
    //     //    this->tablero.at(i).push_back(c - '0');
    //     }
    // } 

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n1; j ++){
            fin >> c;
            if(c >= '1' && c <= '9'){
                tablero[i][j] = c - '0';
            }
        }
    }

  //  int j = 0;// this->tablero.at(0).size();
    assert(n == n1);
 //   n = i;
}

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
    return os;
}