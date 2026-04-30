import matplotlib.pyplot as plt
from matplotlib.patches import Circle


def mostrar_venn(a, b):
    fig, ax = plt.subplots()

    circulo1 = Circle((0.4, 0.5), 0.3, alpha=0.5)
    circulo2 = Circle((0.6, 0.5), 0.3, alpha=0.5)

    ax.add_patch(circulo1)
    ax.add_patch(circulo2)

    texto_a = "\n".join(a - b)
    texto_b = "\n".join(b - a)
    texto_inter = "\n".join(a & b)

    plt.text(0.28, 0.5, texto_a)
    plt.text(0.68, 0.5, texto_b)
    plt.text(0.48, 0.5, texto_inter)

    plt.xlim(0, 1)
    plt.ylim(0, 1)

    plt.axis("off")

    plt.title("Diagrama de Venn")

    plt.show()