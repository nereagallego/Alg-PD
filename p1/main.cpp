#include "MergeSort/Mergesort.hpp"
#include "QuickSort/Quicksort.hpp"
#include "Radixsort/Radixsort.hpp"
#include <fstream>
#include <string>
#include <iostream>




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

int main(int argc, char *argv[]){
    std::list<int> numbers = std::list<int>();
    string filepath = "rand_input.txt";

    readData(filepath, numbers);
    
    int n = numbers.size();
    int arr[n];
    int k = 0;
    for (int const &i: numbers) {
        arr[k++] = i;
    }

    radixsort(arr, n);
    cout << "Sorted array: \n";
    printVector(arr, n);
    return 0;
}