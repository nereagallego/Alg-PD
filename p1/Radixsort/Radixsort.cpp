#include "Radixsort.hpp"

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

void sort (int arr[], int exp, int n){
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i ++){
        count[i] += count[i-1]; 
        cout << count[i] << " " << endl;
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

void readData(string filepath, list<int>& out) {
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

// void printArray(int arr[], int n){
//     for(int i = 0; i < n; i ++){
//         cout << i << ": " << arr[i] << endl ;
//     }
//     cout << endl;
// }

// int main(int argc, char *argv[]){
//     // int n = 10;
//     // int vector[n] = {4 , 85, 6 , 14, 98, 100, 8789, 234, 024, 45756};
//     std::list<int> numbers = std::list<int>();
//     string filepath = "chiki.txt";
//     readData(filepath, numbers);

//     int n = numbers.size();
//     int arr[n];
//     int k = 0;
//     for (int const &i: numbers) {
//         arr[k++] = i;
//     }
//     radixsort(arr, n);
//     printArray(arr, n);
//     return 0;
// }
