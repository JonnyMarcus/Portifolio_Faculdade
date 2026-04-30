import tkinter as tk
from tkinter import ttk, messagebox

from Conjuntos import *
from Relacoes import *
from Logica import *
from Grafos import *
from Arquivo import salvar_resultado, ler_historico, limpar_historico
from Pdf_export import exportar_pdf
from Grafo_visual import mostrar_grafo
from Venn_visual import mostrar_venn
from Tabela_verdade import mostrar_tabela_verdade




def converter_conjunto(texto):
    return set(texto.split())




def calcular_uniao():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    texto = f"União: {uniao(a,b)}"
    resultado_conjuntos.config(text=texto)
    salvar_resultado(texto)


def calcular_intersecao():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    texto = f"Interseção: {intersecao(a,b)}"
    resultado_conjuntos.config(text=texto)
    salvar_resultado(texto)


def calcular_diferenca():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    texto = f"Diferença: {diferenca(a,b)}"
    resultado_conjuntos.config(text=texto)
    salvar_resultado(texto)


def calcular_diferenca_simetrica():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    texto = f"Diferença Simétrica: {diferenca_simetrica(a,b)}"
    resultado_conjuntos.config(text=texto)
    salvar_resultado(texto)


def exibir_venn():
    a = converter_conjunto(entry_a.get())
    b = converter_conjunto(entry_b.get())

    mostrar_venn(a, b)




def calcular_produto_cartesiano():
    a = converter_conjunto(entry_a_rel.get())
    b = converter_conjunto(entry_b_rel.get())

    texto = f"Produto Cartesiano: {produto_cartesiano(a,b)}"
    resultado_relacoes.config(text=texto)
    salvar_resultado(texto)


def verificar_reflexiva():
    a = converter_conjunto(entry_a_rel.get())
    relacao = {(x, x) for x in a}

    texto = f"Reflexiva: {relacao_reflexiva(a, relacao)}"
    resultado_relacoes.config(text=texto)
    salvar_resultado(texto)




def calcular_and():
    p = entry_p.get() == "True"
    q = entry_q.get() == "True"

    texto = f"AND: {proposicao_and(p,q)}"
    resultado_logica.config(text=texto)
    salvar_resultado(texto)


def calcular_or():
    p = entry_p.get() == "True"
    q = entry_q.get() == "True"

    texto = f"OR: {proposicao_or(p,q)}"
    resultado_logica.config(text=texto)
    salvar_resultado(texto)


def calcular_not():
    p = entry_p.get() == "True"

    texto = f"NOT: {proposicao_not(p)}"
    resultado_logica.config(text=texto)
    salvar_resultado(texto)


def calcular_implicacao():
    p = entry_p.get() == "True"
    q = entry_q.get() == "True"

    texto = f"Implicação: {implicacao(p,q)}"
    resultado_logica.config(text=texto)
    salvar_resultado(texto)




grafo = criar_grafo()


def adicionar_no_grafo():
    origem = entry_origem.get()
    destino = entry_destino.get()

    adicionar_aresta(grafo, origem, destino)

    texto = f"Grafo: {grafo}"
    resultado_grafo.config(text=texto)
    salvar_resultado(texto)


def calcular_grau():
    vertice = entry_origem.get()

    texto = f"Grau de {vertice}: {grau_vertice(grafo, vertice)}"
    resultado_grafo.config(text=texto)
    salvar_resultado(texto)


def exibir_grafo_visual():
    mostrar_grafo(grafo)




def mostrar_historico():
    messagebox.showinfo("Histórico", ler_historico())


def apagar_historico():
    limpar_historico()
    messagebox.showinfo("Histórico", "Histórico apagado.")


def gerar_pdf():
    historico = ler_historico()
    arquivo = exportar_pdf(historico)

    messagebox.showinfo("PDF", f"Gerado: {arquivo}")




janela = tk.Tk()
janela.title("Discrete Math Toolkit")
janela.geometry("800x650")

abas = ttk.Notebook(janela)




aba_conjuntos = tk.Frame(abas)
abas.add(aba_conjuntos, text="Conjuntos")

tk.Label(aba_conjuntos, text="Conjunto A").grid(row=0, column=0)
entry_a = tk.Entry(aba_conjuntos)
entry_a.grid(row=0, column=1)

tk.Label(aba_conjuntos, text="Conjunto B").grid(row=1, column=0)
entry_b = tk.Entry(aba_conjuntos)
entry_b.grid(row=1, column=1)

tk.Button(aba_conjuntos, text="União", command=calcular_uniao).grid(row=2, column=0)
tk.Button(aba_conjuntos, text="Interseção", command=calcular_intersecao).grid(row=2, column=1)

tk.Button(aba_conjuntos, text="Diferença", command=calcular_diferenca).grid(row=3, column=0)
tk.Button(aba_conjuntos, text="Dif. Simétrica", command=calcular_diferenca_simetrica).grid(row=3, column=1)

tk.Button(aba_conjuntos, text="Mostrar Venn", command=exibir_venn).grid(row=4, column=0)

resultado_conjuntos = tk.Label(aba_conjuntos, text="Resultado")
resultado_conjuntos.grid(row=5, column=0, columnspan=2)



aba_relacoes = tk.Frame(abas)
abas.add(aba_relacoes, text="Relações")

tk.Label(aba_relacoes, text="Conjunto A").grid(row=0, column=0)
entry_a_rel = tk.Entry(aba_relacoes)
entry_a_rel.grid(row=0, column=1)

tk.Label(aba_relacoes, text="Conjunto B").grid(row=1, column=0)
entry_b_rel = tk.Entry(aba_relacoes)
entry_b_rel.grid(row=1, column=1)

tk.Button(aba_relacoes, text="Produto Cartesiano", command=calcular_produto_cartesiano).grid(row=2, column=0)
tk.Button(aba_relacoes, text="Reflexiva", command=verificar_reflexiva).grid(row=2, column=1)

resultado_relacoes = tk.Label(aba_relacoes, text="Resultado")
resultado_relacoes.grid(row=3, column=0, columnspan=2)




aba_logica = tk.Frame(abas)
abas.add(aba_logica, text="Lógica")

tk.Label(aba_logica, text="P").grid(row=0, column=0)
entry_p = tk.Entry(aba_logica)
entry_p.grid(row=0, column=1)

tk.Label(aba_logica, text="Q").grid(row=1, column=0)
entry_q = tk.Entry(aba_logica)
entry_q.grid(row=1, column=1)

tk.Button(aba_logica, text="AND", command=calcular_and).grid(row=2, column=0)
tk.Button(aba_logica, text="OR", command=calcular_or).grid(row=2, column=1)

tk.Button(aba_logica, text="NOT", command=calcular_not).grid(row=3, column=0)
tk.Button(aba_logica, text="Implicação", command=calcular_implicacao).grid(row=3, column=1)

tk.Button(aba_logica, text="Tabela Verdade", command=mostrar_tabela_verdade).grid(row=4, column=0)

resultado_logica = tk.Label(aba_logica, text="Resultado")
resultado_logica.grid(row=5, column=0, columnspan=2)



aba_grafos = tk.Frame(abas)
abas.add(aba_grafos, text="Grafos")

tk.Label(aba_grafos, text="Origem").grid(row=0, column=0)
entry_origem = tk.Entry(aba_grafos)
entry_origem.grid(row=0, column=1)

tk.Label(aba_grafos, text="Destino").grid(row=1, column=0)
entry_destino = tk.Entry(aba_grafos)
entry_destino.grid(row=1, column=1)

tk.Button(aba_grafos, text="Adicionar Aresta", command=adicionar_no_grafo).grid(row=2, column=0)
tk.Button(aba_grafos, text="Grau", command=calcular_grau).grid(row=2, column=1)

tk.Button(aba_grafos, text="Mostrar Grafo", command=exibir_grafo_visual).grid(row=3, column=0)

resultado_grafo = tk.Label(aba_grafos, text="Resultado")
resultado_grafo.grid(row=4, column=0, columnspan=2)




abas.pack(expand=1, fill="both")

frame_botoes = tk.Frame(janela)
frame_botoes.pack(pady=10)

tk.Button(frame_botoes, text="Ver Histórico", command=mostrar_historico).pack(side="left", padx=10)
tk.Button(frame_botoes, text="Limpar Histórico", command=apagar_historico).pack(side="left", padx=10)
tk.Button(frame_botoes, text="Exportar PDF", command=gerar_pdf).pack(side="left", padx=10)

janela.mainloop()