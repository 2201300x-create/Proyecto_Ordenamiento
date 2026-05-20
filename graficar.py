import pandas as pd
import matplotlib.pyplot as plt

# Leer CSV
df = pd.read_csv("resultados.csv")

# Obtener algoritmos únicos
algoritmos = df["algoritmo"].unique()

# ===== Tiempo =====
plt.figure(figsize=(10,6))

for alg in algoritmos:
    sub = df[df["algoritmo"] == alg]
    plt.plot(sub["n"], sub["time_ms"], marker='o', label=alg)

plt.xlabel("Tamaño del arreglo (n)")
plt.ylabel("Tiempo (ms)")
plt.title("Tiempo de ejecución")
plt.legend()
plt.grid()

plt.savefig("grafica_tiempos.png")
plt.show()
