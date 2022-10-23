#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main(){
    fstream file;
    file.open("aleatorios1.txt", fstream::out);
    for(int i = 0; i < 200000; i ++){
        file << i << endl;
    }
    file.close();
    return 0;
}