#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "datasets.h"
#include "algoritmos.h"

// Definir los tamaños que se propuso en el documento del proyecto
int size[] = { 100, 200, 300, 400, 500, 1000, 2500, 5000, 7000};
int num_sizes = 9;

// Nombres para las celdas del CSV
const char* dist_names[] = {"uniform", "..."};
const char* algo_name[] = {"Insertion", "Merge", "Counting", "Introsort"};
// Propiedad para la estabilidad de cada uno
const char* estable[] = {"SI", "SI", "SI", "NO"};

int main() {

}