# Proyecto de Análisis de Algoritmos de Ordenamiento

Benchmark comparativo de cuatro algoritmos de ordenamiento evaluados sobre distintas distribuciones de datos, midiendo tiempo de ejecución, comparaciones y movimientos en memoria.

---

## Algoritmos implementados

| Algoritmo | Complejidad | Estable | Notas |
|---|---|---|---|
| Insertion Sort | O(n²) | ✅ Sí | Eficiente para arreglos pequeños o casi ordenados |
| Merge Sort | O(n log n) | ✅ Sí | Divide y vence, rendimiento consistente |
| Counting Sort | O(n) | ✅ Sí | Lineal; no usa comparaciones, depende del rango de valores |
| Introsort | O(n log n) | ❌ No | Híbrido: QuickSort + HeapSort + Insertion Sort |

## Distribuciones de datos probadas

- **Uniforme** – valores aleatorios en rango [0, 9999]
- **Ordenado** – arreglo ya ordenado de menor a mayor
- **Reverso** – arreglo ordenado de mayor a menor
- **Casi ordenado** – ordenado con ~5% de elementos permutados
- **Duplicados** – valores en rango [0, 4], altísima repetición

## Tamaños de entrada

`100, 200, 300, 400, 500, 1000, 2500, 5000, 7000, 7500`

Cada combinación (algoritmo × distribución × tamaño) se repite **3 veces** para promediar resultados.

---

## Estructura del proyecto

```
Proyecto_Ordenamiento/
├── src/
│   ├── main.c          # Benchmark principal, genera resultados.csv
│   ├── algoritmos.c    # Implementación de los 4 algoritmos
│   ├── algoritmos.h
│   ├── datasets.c      # Generadores de distribuciones
│   └── datasets.h
├── graficar.py         # Menú interactivo para visualizar resultados
├── Makefile
└── README.md
```

---

## Compilación y ejecución

### Requisitos
- GCC con soporte para `math.h` (flag `-lm`)
- Python 3 con `pandas` y `matplotlib` (para graficar)

### Compilar y ejecutar el benchmark

```bash
make        # Compila el proyecto
make run    # Compila y ejecuta (genera resultados.csv)
make clean  # Elimina el ejecutable
```

O manualmente:

```bash
gcc -Wall -O2 src/main.c src/algoritmos.c src/datasets.c -o benchmark -lm
./benchmark
```

Esto genera el archivo `resultados.csv` en el directorio raíz.

### Visualizar resultados

```bash
python graficar.py
```

El script presenta un menú interactivo para elegir la distribución y el algoritmo a graficar. Las imágenes se guardan automáticamente como `.png`.

---

## Salida del benchmark

El archivo `resultados.csv` tiene el siguiente formato:

```
algoritmo,tamaño,distribucion,repeticion,time_ms,comparaciones,swaps,estable
Insertion,100,uniform,1,0.0450,2341,3102,SI
Counting,100,uniform,1,0.0120,NA,200,SI
...
```

> **Nota:** La columna `comparaciones` aparece como `NA` para Counting Sort, ya que este algoritmo no realiza comparaciones entre elementos.

---

## Métricas registradas

- `time_ms` – tiempo de ejecución en milisegundos (`clock()`)
- `comparaciones` – número de comparaciones entre elementos
- `swaps` – número de movimientos/copias en memoria
- `estable` – indica si el algoritmo preserva el orden relativo de elementos iguales