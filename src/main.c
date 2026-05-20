#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "datasets.h"
#include "algoritmos.h"

// Definir los tamaños que se propuso en el documento del proyecto
int sizes[] = { 100, 200, 300, 400, 500, 1000, 2500, 5000, 7000};
int num_sizes = 9;

// Nombres para las celdas del CSV
const char* dist_names[] = {"uniform", "ordenado", "reverso", "casi", "duplicados"};
const char* algo_names[] = {"Insertion", "Merge", "Counting", "Introsort"};
// Propiedad para la estabilidad de cada uno
const char* estable[] = {"SI", "SI", "SI", "NO"};

int main() {
	// Abrir/Crear el archivo CSV
	FILE *fp = fopen("resultados.csv", "w");
	if (fp == NULL) {
		printf("ERROR: No se pudo crear el archivo CSV.\n");
		return 1;
	}

	// Escribir la cabecera del CSV
	fprintf(fp, "algoritmo,tamaño,distribucion,repeticion,time_ms,comparaciones,swaps,estable\n");

	// Semilla para los numeros aleatorios
	srand(time(NULL));

	// Bucle 1: Tamaño
	for (int s = 0; s < num_sizes; s++) {
		int n = sizes[s];
		int *base_arr = (int *)malloc(n * sizeof(int));
		int *test_arr = (int *)malloc(n * sizeof(int));

		// Bucle 2: Distribucion
		for (int d = 0; d < 5; d++) {
			// Bucle 3: Repeticiones de minimo 3
			for (int rep = 1; rep <= 3; rep++) {
				// Generar el arreglo base segun la distribucion
				switch(d) {
					case 0:
						generar_uniform(base_arr, n);
						break;
					case 1:
						generar_ordenado(base_arr, n);
						break;
					case 2:
						generar_reverso(base_arr, n);
						break;
					case 3:
						generar_casi(base_arr, n);
						break;
					case 4:
						generar_duplicados(base_arr, n);
						break;
				}

				// Bucle 4: Algoritmos de 0 a 3
				for (int a = 0; a < 4; a++) {
					// Copiar el arreglo para que todos los algoritmos exactamente lo mismo
					memcpy(test_arr, base_arr, n * sizeof(int));

					long long comps = 0;
					long long swaps = 0;
					clock_t start, end;
					double cpu_time_used;

					// Iniciar cronometro y ejecutar algoritmo
					start = clock();
					switch (a) {
						case 0:
							insertion_sort(test_arr, n, &comps, &swaps);
							break;
						case 1:
							merge_sort(test_arr, 0, n - 1, &comps, &swaps);
							break;
						case 2:
							counting_sort(test_arr, n, &comps, &swaps);
							break;
						case 3:
							introsort(test_arr, n, &comps, &swaps);
							break;
					}
					end = clock();

					// Calcular el tiempo en ms
					cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;

					// Escribir en el CSV
					if (a == 2) {
						// Counting Sort no usa comparaciones
						fprintf(fp, "%s,%d,%s,%d,%.4f,NA,%ld,%s\n", algo_names[a], n, dist_names[d], rep, cpu_time_used, (long)swaps, estable[a]);
					} else {
						fprintf(fp, "%s,%d,%s,%d,%.4f,%ld,%ld,%s\n", algo_names[a], n, dist_names[d], rep, cpu_time_used, (long)comps, (long)swaps, estable[a]);
					}					
				}
			}
		}
		free(base_arr);
		free(test_arr);
		printf("Completado tamaño: %d\n", n);
	}
	fclose(fp);
    printf("\n [INFO]: Resultados guardados en 'resultados.csv'.\n");
    return 0;
}