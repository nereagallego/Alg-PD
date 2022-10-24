#pragma once

/**
 * @brief Cuenta la cantidad de dígitos que tiene el número n
 * 
 * @param n numero 
 * @return int 
 */
int countDigits(int n);


/**
 * @brief Devuelve el número máximo de cifras que hay en los números contenidos 
 * en arr
 * 
 * @param arr vector de números
 * @param n cantidad de números que hay en el vector
 * @return int 
 */
int maxCifras(int arr[], int n);


/**
 * @brief ordena los números en la cufra cuyo exponente se encuentra en exp
 * 
 * @param arr vector de números
 * @param exp cifra por la que se va a ordenar
 * @param n cantidad de números en el vector
 */
void sort (int arr[], int exp, int n);

/**
 * @brief Ordena el vector arr que contienen n numeros por el método radixsort
 * 
 * @param arr vector de números
 * @param n cantidad de números que hay en arr
 */
void radixsort(int arr[], int n);