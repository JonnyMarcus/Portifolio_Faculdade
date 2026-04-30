def ler_conjunto(nome):
    entrada = input(f"Digite os elementos do conjunto {nome} separados por espaço: ")
    return set(entrada.split())

def uniao(a, b):
    return a | b


def intersecao(a, b):
    return a & b


def diferenca(a, b):
    return a - b


def diferenca_simetrica(a, b):
    return a ^ b


def verificar_subconjunto(a, b):
    return a.issubset(b)