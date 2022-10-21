#include "MergeSort/Mergesort.hpp"
#include "QuickSort/Quicksort.hpp"
#include "Radixsort/Radixsort.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << endl;
    cout << endl;
}

void readData(string filepath, std::list<int>& out) {
    ifstream file(filepath);

    if (file.is_open())
    {
        string content;
        while(std::getline(file, content)) {
            out.push_front(stoi(content));
        }

        file.close();
    } else {
        std::cout << "no abre el fichero" << std::endl;
    }

}

void copyVector(const int v[], int  w[], int n){
    for(int i = 0; i < n; i++){
        w[i] = v[i];
    }
}


void experimento(string fichero){
    std::list<int> numbers = std::list<int>();
    

    readData(fichero, numbers);
    
    int n = numbers.size();
    int arr[n];
    int k = 0;
    for (int const &i: numbers) {
        arr[k++] = i;
    }

    float mean = 0;
    
    cout << "| " << setw(25) << fichero; 
    for(int i = 0; i < 5; i ++){
        auto start = chrono::high_resolution_clock::now();
        radixsort(arr, n);
        auto stop = chrono::high_resolution_clock::now();

        auto sort_duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        mean += sort_duration.count() / 5;
        int k = 0;
        for (int const &j: numbers) {
            arr[k++] = j;
        }
    }
    cout << "| " << setw(17) << mean << "|";
    mean = 0;
    for(int i = 0; i < 1; i ++){
        int max_n = max(arr,n);
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1, max_n);
        auto stop = chrono::high_resolution_clock::now();

        auto sort_duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        mean += sort_duration.count() / 5;
        int k = 0;
        for (int const &j: numbers) {
            arr[k++] = j;
        }
    }
    cout << " " << setw(17) << mean << "|";
    // print mean
    mean = 0;
    for(int i = 0; i < 5; i ++){
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto stop = chrono::high_resolution_clock::now();

        auto sort_duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        mean += sort_duration.count() / 5;
        int k = 0;
        for (int const &j: numbers) {
            arr[k++] = j;
        }
    }
    cout << " " << setw(17) << mean << "|" << endl;
    //print mean

}

void printCabecera() {
    cout << setfill('-') << setw(85) << "-" << endl << setfill(' ');
    cout << "| " << setw(25) << "nombre fichero " << "| t_radixsort (us) | t_quicksort (us) | t_mergesort (us) |" << endl;
    cout << setfill('-') << setw(85) << "-" << endl << setfill(' ');
}

int main(int argc, char *argv[]){
    
    printCabecera();
    experimento("aleatorios1.txt");
    experimento("aleatorios2.txt");
    experimento("aleatorios3.txt");
    experimento("reales1.txt");
    experimento("reales2.txt");
    experimento("reales3.txt");
    experimento("reales4.txt");


    cout << setfill('-') << setw(85) << "-" << endl << setfill(' ');

    return 0;
}