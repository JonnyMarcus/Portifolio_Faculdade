import tkinter as tk


def mostrar_tabela_verdade():
    janela = tk.Toplevel()

    janela.title("Tabela Verdade")

    texto = tk.Text(janela, width=35, height=10)
    texto.pack()

    cabecalho = "P\tQ\tAND\tOR\tImplica\n"
    texto.insert(tk.END, cabecalho)

    valores = [
        (True, True),
        (True, False),
        (False, True),
        (False, False)
    ]

    for p, q in valores:
        linha = f"{p}\t{q}\t{p and q}\t{p or q}\t{(not p) or q}\n"
        texto.insert(tk.END, linha)