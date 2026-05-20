#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// Se pasan los punteros a comps (comparaciones) y swaps para que lleve el conteo
void insertion_sort(int arr[], int n, long long *comps, long long *swaps);
void counting_sort(int arr[], int n, long long *comps, long long *swaps);
void merge_sort(int arr[], int l, int r, long long *comps, long long *swaps);
void introsort(int arr[], int n, long long *comps, long long *swaps);

#endif