import matplotlib.pyplot as plt


def mostrar_grafo(grafo):
    plt.figure(figsize=(6, 6))

    posicoes = {}

    vertices = list(grafo.keys())

    for i, vertice in enumerate(vertices):
        posicoes[vertice] = (i, len(vertices) - i)

    # desenhar vértices
    for vertice, (x, y) in posicoes.items():
        plt.scatter(x, y, s=500)

        plt.text(
            x,
            y,
            vertice,
            fontsize=12,
            ha='center',
            va='center'
        )

    # desenhar arestas
    for origem in grafo:
        for destino in grafo[origem]:
            if destino in posicoes:
                x1, y1 = posicoes[origem]
                x2, y2 = posicoes[destino]

                plt.plot([x1, x2], [y1, y2])

    plt.title("Visualização do Grafo")

    plt.axis("off")

    plt.show()