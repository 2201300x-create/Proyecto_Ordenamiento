#include <stdio.h>
#include <stdlib.h>
#include "datasets.h"

// 1. Uniforme: Aleatorio uniforme
void generar_uniform(int arr[], int n){
	for (int i = 0; i < n; i++) {
		// Valores de 0 hasta 9999
		arr[i] = rand() % 10000;
	}
}

// 2. Ordenado: Ya ordenado de menor a mayor
void generar_ordenado(int arr[], int n){
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
}

// 3. Reverso. Ordenado de mayor a menor
void generar_reverso(int arr[], int n){
	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
}

// 4. Casi ordenado: Pocas permutaciones
void generar_casi(int arr[], int n){
	// Primero se ordena
	generar_ordenado(arr, n);

	// Se intercambia aproximadamente el 5% de los elementos
	int num_swaps = n * 0.05;

	if (num_swaps == 0) num_swaps = 1 // Al menos 1 swap si el arreglo es muy pequeño

		for (int i = 0; i < num_swaps; i++) {
			int idx1 = rand() % n;
			int idx2 = rand() % n;

			// Swap
			int temp = arr[idx1];
			arr[idx1] = arr[idx2];
			arr[idx2] = temp;
		}
}

// 5. Duplicado: Muchos repetidos (rango de valores muy pequeños)
void generar_duplicados(int arr[], int n){
	for (int i = 0; i < n; i++) {
		// Solo genera numeros de 0 a 4, garantizando altisima repeticion
		arr[i] = rand() % 5;
	}
}

// 6. Imprimir lo que se genero
void imprimir_arreglo(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[]);
	}
	printf("|n");
}