#include "MergeSort/Mergesort.hpp"
#include "QuickSort/Quicksort.hpp"
//#include "Radixsort/Radixsort.hpp"
#include <fstream>
#include <string>
#include <iostream>


void printArray(int arr[], int n){
    for(int i = 0; i < n; i ++){
        cout << arr[i] << endl ;
    }
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

int main(int argc, char *argv[]){
    std::list<int> numbers = std::list<int>();
    string filepath = "chiki_copy.txt";

    readData(filepath, numbers);
    
    // int n = numbers.size();
    // int arr[n];
    // int k = 0;
    // for (int const &i: numbers) {
    //     arr[k++] = i;
    // }

    //int arr[] = { 1366326, 3314231, 905725, 4442643, 4052543, 429322, 3994976, 2881504, 397964, 928828, 682764, 4769791, 2221579, 820832, 4107754, 2602515, 2786677, 436757, 4887143, 1307511};
    int arr[] = { 10, 2, 8, 9, 4, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // int arr[] = { 10, 7, 8, 9, 1, 5 };
    // int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}