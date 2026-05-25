import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos
df = pd.read_csv("resultados.csv")

# Promediar las 3 repeticiones
promedio = df.groupby(["algoritmo", "tamaño", "distribucion"])["time_ms"].mean().reset_index()

distribuciones = promedio["distribucion"].unique()
algoritmos = promedio["algoritmo"].unique()

def graficar_distribucion(dist, algoritmo_especifico=None):
    """
    Función que grafica una distribución. 
    Si algoritmo_especifico es None, grafica todos.
    Si se le pasa un algoritmo, solo grafica ese.
    """
    plt.figure(figsize=(10, 6))
    
    sub_dist = promedio[promedio["distribucion"] == dist]
    
    # Decidir qué algoritmos vamos a graficar
    algoritmos_a_graficar = [algoritmo_especifico] if algoritmo_especifico else algoritmos
    
    for alg in algoritmos_a_graficar:
        sub = sub_dist[sub_dist["algoritmo"] == alg]
        if not sub.empty:
            plt.plot(sub["tamaño"], sub["time_ms"], marker='o', label=alg)
            
    # Configurar el título dependiendo de si es uno o todos
    if algoritmo_especifico:
        plt.title(f"Distribución: {dist} - Algoritmo: {algoritmo_especifico}", fontsize=14)
        sufijo = f"_{algoritmo_especifico.replace(' ', '_')}"
    else:
        plt.title(f"Comparación de algoritmos - Distribución: {dist}", fontsize=14)
        sufijo = "_todos"
        
    plt.xlabel("Tamaño (n)", fontsize=12)
    plt.ylabel("Tiempo (ms)", fontsize=12)
    plt.legend(fontsize=10)
    plt.grid(True)
    plt.tight_layout()
    
    # Limpiar espacios en el nombre para el archivo
    nombre_archivo = f"grafica_{dist.replace(' ', '_')}{sufijo}.png"
    plt.savefig(nombre_archivo)
    print(f"\nGráfica generada y guardada como: {nombre_archivo}")
    
    plt.show()

# Bucle del menú principal
while True:
    print("\n" + "="*30)
    print("       MENÚ DE GRÁFICAS")
    print("="*30)
    
    for i, dist in enumerate(distribuciones):
        print(f"{i + 1}. Graficar distribución: {dist}")
    
    opcion_salir = len(distribuciones) + 1
    print(f"{opcion_salir}. Salir")
    print("="*30)
    
    opcion = input("\nElige una opción (número): ")
    
    try:
        opcion = int(opcion)
        if 1 <= opcion <= len(distribuciones):
            dist_seleccionada = distribuciones[opcion - 1]
            
            # --- INICIO DEL SUBMENÚ ---
            while True:
                print("\n" + "-"*40)
                print(f"  Submenú: Algoritmos para '{dist_seleccionada}'")
                print("-"*40)
                print("1. Mostrar TODOS los algoritmos")
                
                # Listar cada algoritmo individualmente
                for j, alg in enumerate(algoritmos):
                    print(f"{j + 2}. Mostrar solo: {alg}")
                
                opcion_volver = len(algoritmos) + 2
                print(f"{opcion_volver}. Volver al menú principal")
                print("-"*40)
                
                sub_opcion = input("\nElige una opción (número): ")
                
                try:
                    sub_opcion = int(sub_opcion)
                    if sub_opcion == 1:
                        # Graficar todos
                        graficar_distribucion(dist_seleccionada)
                        break # Sale del submenú después de graficar
                    elif 2 <= sub_opcion <= len(algoritmos) + 1:
                        # Graficar solo el específico
                        alg_seleccionado = algoritmos[sub_opcion - 2]
                        graficar_distribucion(dist_seleccionada, algoritmo_especifico=alg_seleccionado)
                        break # Sale del submenú después de graficar
                    elif sub_opcion == opcion_volver:
                        print("\nVolviendo al menú principal...")
                        break
                    else:
                        print(f"\nOpción inválida. Por favor ingresa un número entre 1 y {opcion_volver}.")
                except ValueError:
                    print("\nError: Por favor ingresa un número válido.")
            # --- FIN DEL SUBMENÚ ---
            
        elif opcion == opcion_salir:
            print("\nSaliendo del programa... ¡Hasta luego!")
            break
        else:
            print(f"\nOpción inválida. Por favor ingresa un número entre 1 y {opcion_salir}.")
    except ValueError:
        print("nError: Por favor ingresa un número válido.")