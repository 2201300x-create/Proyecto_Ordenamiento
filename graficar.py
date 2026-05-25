import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("resultados.csv")

# Promediar las 3 repeticiones
promedio = df.groupby(["algoritmo", "tamaño", "distribucion"])["time_ms"].mean().reset_index()

distribuciones = promedio["distribucion"].unique()
algoritmos = promedio["algoritmo"].unique()

fig, axes = plt.subplots(2, 3, figsize=(16, 9), sharey=False)
axes = axes.flatten()

for i, dist in enumerate(distribuciones):
    ax = axes[i]
    sub_dist = promedio[promedio["distribucion"] == dist]
    for alg in algoritmos:
        sub = sub_dist[sub_dist["algoritmo"] == alg]
        ax.plot(sub["tamaño"], sub["time_ms"], marker='o', label=alg)
    ax.set_title(f"Distribución: {dist}")
    ax.set_xlabel("Tamaño (n)")
    ax.set_ylabel("Tiempo (ms)")
    ax.legend(fontsize=7)
    ax.grid(True)

# Ocultar el subplot sobrante si hay 5 distribuciones
for j in range(len(distribuciones), len(axes)):
    axes[j].set_visible(False)

plt.suptitle("Comparación de algoritmos por distribución", fontsize=13)
plt.tight_layout()
plt.savefig("grafica_tiempos.png")
plt.show()