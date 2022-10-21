#include "Radixsort.hpp"
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include "iostream"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <list>

using namespace std;

// Cuenta la cantidad de dígitos de un número
int countDigits(int n){
    string aux = to_string(n);
    return aux.size();
}

// Devuelve 
int maxCifras(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int max(int arr[], int n){
    int max = 0;
    for(int i = 1; i < n; i ++){
        if(arr[i] > max)
            max = i;
    }
    return max;
}

int min(int arr[], int n){
    int min = arr[0];
    for(int i = 1; i < n; i ++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

void sort (int arr[], int exp, int n){
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i ++){
        count[i] += count[i-1]; 
    //    cout << count[i] << " " << endl;
    }
 //   cout << endl;

    for(int i = n-1; i >= 0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n){
    int max = maxCifras(arr, n);
    
    for (int exp = 1 ; max/exp > 0; exp *= 10){
        sort(arr, exp, n);
     //   printVector(arr,n);
    }
}
