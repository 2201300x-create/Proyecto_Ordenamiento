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
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
				j--;
			} else {
				break;
			}
		}
		arr[j + 1] = key;
		//Contamos la insercion final del "key"
		(*swaps)++;
	}
}

// 2. Counting Sort O(n) - Lineal
void counting_sort(int arr[], int n, long long *comps, long long *swaps){
	// Para Couting Sort, las comparaciones no aplican, se reportara NA despues.
	// Solo se contara los movimientos/copias de elementos.

	if (n <= 1) return;

	// Encontrar el valor maximo ppara saber el tamaña del arreglo de conteo
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int *count = (int *)calloc(max + 1, sizeof(int));
	int *output = (int *)malloc(n * sizeof(int));

	// Conteo de la frecuencia
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// Acumulativo
	for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        // Movimiento hacia el arreglo auxiliar
        (*swaps)++; 
    }

    // Copiar de vuelta al arreglo original
    for (int i = 0; i < n; i++) {
    	arr[i] = output[i];
    	// Movimiento de vuelta al ariginal
    	(*swaps)++;
    }

    free(count);
    free(output);
}

// 3. Merge Sort O(n log n) - Estable
void merge(int arr[], int l, int m, int r, long long *comps, long long *swaps) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		(*swaps)++;
	}

	for (int j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		(*swaps)++;
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		(*comps)++;
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		(*swaps)++;
		k++;
	}

	while (i < n1) {
        arr[k] = L[i];
        (*swaps)++;
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        (*swaps)++;
        j++; k++;
    }

    free(L);
    free(R);	
}

void merge_sort(int arr[], int l, int r, long long *comps, long long *swaps){
	if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m, comps, swaps);
        merge_sort(arr, m + 1, r, comps, swaps);
        merge(arr, l, m, r, comps, swaps);
    }
}

// 4. Introsort (Hibrido) - Inestable
void swap_elementos(int *a, int *b, long long *swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    // 3 movimientos en memoria para un intercambio
    (*swaps) += 3;
}

// Helper: Heapify para el HeapSort interno
void heapify(int arr[], int n, int i, long long *comps, long long *swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*comps)++;
    if (left < n && arr[left] > arr[largest]) largest = left;
    
    (*comps)++;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap_elementos(&arr[i], &arr[largest], swaps);
        heapify(arr, n, largest, comps, swaps);
    }
}

// Helper: HeapSort
void heap_sort(int arr[], int n, long long *comps, long long *swaps) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comps, swaps);
    for (int i = n - 1; i > 0; i--) {
        swap_elementos(&arr[0], &arr[i], swaps);
        heapify(arr, i, 0, comps, swaps);
    }
}

// Helper: Partición de QuickSort
int particion(int arr[], int low, int high, long long *comps, long long *swaps) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        (*comps)++;
        if (arr[j] < pivot) {
            i++;
            swap_elementos(&arr[i], &arr[j], swaps);
        }
    }
    swap_elementos(&arr[i + 1], &arr[high], swaps);
    return (i + 1);
}

// Motor de Introsort
void introsort_util(int arr[], int low, int high, int depthLimit, long long *comps, long long *swaps) {
    int size = high - low + 1;
    if (size < 16) {
        // Para subarreglos pequeños, Insertion Sort es más rápido
        insertion_sort(arr + low, size, comps, swaps);
        return;
    }
    if (depthLimit == 0) {
        // Si hay mucha recursión, cambiamos a HeapSort
        heap_sort(arr + low, size, comps, swaps);
        return;
    }
    int pi = particion(arr, low, high, comps, swaps);
    introsort_util(arr, low, pi - 1, depthLimit - 1, comps, swaps);
    introsort_util(arr, pi + 1, high, depthLimit - 1, comps, swaps);
}

// Función principal que llama el main
void introsort(int arr[], int n, long long *comps, long long *swaps) {
    int depthLimit = 2 * log(n); // Límite matemático de profundidad
    introsort_util(arr, 0, n - 1, depthLimit, comps, swaps);
}