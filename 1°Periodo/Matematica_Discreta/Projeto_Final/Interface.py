import tkinter as tk
from tkinter import ttk, messagebox

from Conjuntos import *
from Relacoes import *
from Logica import *
from Grafos import *
from Arquivo import salvar_resultado, ler_historico, limpar_historico



def converter_conjunto(texto):
    return set(texto.split())



def calcular_uniao():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    resultado = uniao(a, b)

    texto = f"União: {resultado}"
    resultado_conjuntos.config(text=texto)

    salvar_resultado(texto)


def calcular_produto_cartesiano():
    a = converter_conjunto(entry_a_rel.get())
    b = converter_conjunto(entry_b_rel.get())

    resultado = produto_cartesiano(a, b)

    texto = f"Produto Cartesiano: {resultado}"
    resultado_relacoes.config(text=texto)

    salvar_resultado(texto)



def calcular_and():
    p = entry_p.get() == "True"
    q = entry_q.get() == "True"

    resultado = proposicao_and(p, q)

    texto = f"AND: {resultado}"
    resultado_logica.config(text=texto)

    salvar_resultado(texto)



grafo = criar_grafo()

def adicionar_no_grafo():
    origem = entry_origem.get()
    destino = entry_destino.get()

    adicionar_aresta(grafo, origem, destino)

    texto = str(grafo)
    resultado_grafo.config(text=texto)

    salvar_resultado(texto)




def mostrar_historico():
    historico = ler_historico()
    messagebox.showinfo("Histórico", historico)


def apagar_historico():
    limpar_historico()
    messagebox.showinfo("Histórico", "Histórico apagado com sucesso.")




janela = tk.Tk()
janela.title("Discrete Math Toolkit")
janela.geometry("700x550")
janela.configure(bg="#f0f0f0")

style = ttk.Style()
style.configure("TNotebook.Tab", font=("Arial", 11), padding=[15, 8])

abas = ttk.Notebook(janela)



aba_conjuntos = tk.Frame(abas)
abas.add(aba_conjuntos, text="Conjuntos")

tk.Label(aba_conjuntos, text="Conjunto A", font=("Arial", 12)).grid(row=0, column=0, padx=10, pady=10)

entry_a = tk.Entry(aba_conjuntos, width=25)
entry_a.grid(row=0, column=1, padx=10, pady=10)

tk.Label(aba_conjuntos, text="Conjunto B", font=("Arial", 12)).grid(row=1, column=0, padx=10, pady=10)

entry_b = tk.Entry(aba_conjuntos, width=25)
entry_b.grid(row=1, column=1, padx=10, pady=10)

tk.Button(
    aba_conjuntos,
    text="União",
    width=15,
    command=calcular_uniao
).grid(row=2, column=0, columnspan=2, pady=10)

resultado_conjuntos = tk.Label(aba_conjuntos, text="Resultado", font=("Arial", 12))
resultado_conjuntos.grid(row=3, column=0, columnspan=2, pady=20)


aba_relacoes = tk.Frame(abas)
abas.add(aba_relacoes, text="Relações")

tk.Label(aba_relacoes, text="Conjunto A", font=("Arial", 12)).grid(row=0, column=0, padx=10, pady=10)

entry_a_rel = tk.Entry(aba_relacoes, width=25)
entry_a_rel.grid(row=0, column=1, padx=10, pady=10)

tk.Label(aba_relacoes, text="Conjunto B", font=("Arial", 12)).grid(row=1, column=0, padx=10, pady=10)

entry_b_rel = tk.Entry(aba_relacoes, width=25)
entry_b_rel.grid(row=1, column=1, padx=10, pady=10)

tk.Button(
    aba_relacoes,
    text="Produto Cartesiano",
    width=15,
    command=calcular_produto_cartesiano
).grid(row=2, column=0, columnspan=2, pady=10)

resultado_relacoes = tk.Label(aba_relacoes, text="Resultado", font=("Arial", 12))
resultado_relacoes.grid(row=3, column=0, columnspan=2, pady=20)



aba_logica = tk.Frame(abas)
abas.add(aba_logica, text="Lógica")

tk.Label(aba_logica, text="P (True/False)", font=("Arial", 12)).grid(row=0, column=0, padx=10, pady=10)

entry_p = tk.Entry(aba_logica, width=25)
entry_p.grid(row=0, column=1, padx=10, pady=10)

tk.Label(aba_logica, text="Q (True/False)", font=("Arial", 12)).grid(row=1, column=0, padx=10, pady=10)

entry_q = tk.Entry(aba_logica, width=25)
entry_q.grid(row=1, column=1, padx=10, pady=10)

tk.Button(
    aba_logica,
    text="AND",
    width=15,
    command=calcular_and
).grid(row=2, column=0, columnspan=2, pady=10)

resultado_logica = tk.Label(aba_logica, text="Resultado", font=("Arial", 12))
resultado_logica.grid(row=3, column=0, columnspan=2, pady=20)



aba_grafos = tk.Frame(abas)
abas.add(aba_grafos, text="Grafos")

tk.Label(aba_grafos, text="Origem", font=("Arial", 12)).grid(row=0, column=0, padx=10, pady=10)

entry_origem = tk.Entry(aba_grafos, width=25)
entry_origem.grid(row=0, column=1, padx=10, pady=10)

tk.Label(aba_grafos, text="Destino", font=("Arial", 12)).grid(row=1, column=0, padx=10, pady=10)

entry_destino = tk.Entry(aba_grafos, width=25)
entry_destino.grid(row=1, column=1, padx=10, pady=10)

tk.Button(
    aba_grafos,
    text="Adicionar Aresta",
    width=15,
    command=adicionar_no_grafo
).grid(row=2, column=0, columnspan=2, pady=10)

resultado_grafo = tk.Label(aba_grafos, text="Grafo", font=("Arial", 12))
resultado_grafo.grid(row=3, column=0, columnspan=2, pady=20)


abas.pack(expand=1, fill="both")

frame_botoes = tk.Frame(janela)
frame_botoes.pack(pady=10)

tk.Button(
    frame_botoes,
    text="Ver Histórico",
    width=15,
    command=mostrar_historico
).pack(side="left", padx=10)

tk.Button(
    frame_botoes,
    text="Limpar Histórico",
    width=15,
    command=apagar_historico
).pack(side="left", padx=10)

janela.mainloop()