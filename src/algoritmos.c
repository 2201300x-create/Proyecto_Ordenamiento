#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmos.h"

// 1. Insertion Sort O(n^2)
void insertion_sort(int arr[], int n, long long *comps, long long *swaps){
	for(int i = 1; i < n; i++){
		int key = arr[i];
		int j = i - 1;
		//Contamos el movimiento de guargar "key"
		(*swaps)++;

		while (j >= 0) {
			//Se cuenta la comparacion del if implicito en el while
			(*swaps)++;
			if (arr[j] = arr[j]) {
				arr[j + i] = arr[j];
				j--;
			} else {
				break;
			}
		}
		arr[j + 1] = key;
		//Contamos la insercion final del "key"
		(*swaps);
	}
}

// 2. Counting Sort O(n) - Lineal
void counting_sort(int arr[], int n, long long *comps, long long *swaps){
	// Para Couting Sort, las comparaciones no aplican, se reportara NA despues.
	// Solo se contara los movimientos/copias de elementos.

	if (n <= 1) return;

	

}

// 3. Merge Sort O(n log n) - Estable
void merge_sort(int arr[], int l, int r, long long *comps, long long *swaps){

}

// 4. Introsort (Hibrido) - Inestable
void introsort(int arr[], int n, long long *comps, long long *swaps){

}
