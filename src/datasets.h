#ifndef DATASETS_H
#define DATASETS_H

// Esto gnenra un arreglo de tamaño n con la distribucion solicitada
void generar_uniform(int arr[], int n);
void generar_ordenado(int arr[], int n);
void generar_reverso(int arr[], int n);
void generar_casi(int arr[], int n);
void generar_duplicados(int arr[], int n);

// Funcion que sera de utilidad para imprimir el arreglo
void imprimir_arreglo(int arr[], int n);

#endif