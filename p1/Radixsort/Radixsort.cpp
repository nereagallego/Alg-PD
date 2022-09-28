#include "Radixsort.hpp"

int countDigits(int n){
    string aux = to_string(n);
    return aux.size();
}

int maxCifras(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void sort (int arr[], int exp, int n){
    int output[n], count[10] = {0};

    for (int i = 0; i < n; i++){
    //    cout << arr[i] << " " << (arr[i]/exp)%10 << endl;
        count[(arr[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i ++){
        count[i] += count[i-1]; 
    //    cout << count[i] << " ";
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

void printVector(int arr[], int n){
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void radixsort(int arr[], int n){
    int max = maxCifras(arr, n);
    
    for (int exp = 1 ; exp > 0; exp *= 10){
        sort(arr, exp, n);
     //   printVector(arr,n);
    }
}

// int main(int argc, char *argv[]){
//     int n = 10;
//     int vector[n] = {4 , 85, 6 , 14, 98, 100, 8789, 234, 024, 45756};
//     printVector(vector, n);
//     radixsort(vector, n);
//     printVector(vector,n);
//     return 0;
// }
