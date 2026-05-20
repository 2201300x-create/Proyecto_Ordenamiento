import pandas as pd
import matplotlib.pyplot as plt

# Leer CSV
df = pd.read_csv("resultados.csv")

# Ver columnas detectadas
print(df.columns)

# Obtener algoritmos únicos
algoritmos = df["algoritmo"].unique()

# Crear gráfica
plt.figure(figsize=(10,6))

for alg in algoritmos:

    sub = df[df["algoritmo"] == alg]

    plt.plot(
        sub["tamaño"],
        sub["time_ms"],
        marker='o',
        label=alg
    )

# Etiquetas
plt.xlabel("Tamaño del arreglo (n)")
plt.ylabel("Tiempo (ms)")
plt.title("Comparación de algoritmos de ordenamiento")

# Extras
plt.legend()
plt.grid(True)

# Guardar imagen
plt.savefig("grafica_tiempos.png")

# Mostrar gráfica
plt.show()