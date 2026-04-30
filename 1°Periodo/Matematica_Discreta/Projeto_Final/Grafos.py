def criar_grafo():
    return {}


def adicionar_aresta(grafo, origem, destino):
    if origem not in grafo:
        grafo[origem] = []

    grafo[origem].append(destino)


def mostrar_grafo(grafo):
    for vertice in grafo:
        print(f"{vertice} -> {grafo[vertice]}")


def grau_vertice(grafo, vertice):
    if vertice in grafo:
        return len(grafo[vertice])
    return 0