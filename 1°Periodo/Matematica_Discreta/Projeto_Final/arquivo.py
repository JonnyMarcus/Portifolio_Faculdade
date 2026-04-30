def salvar_resultado(texto):
    with open("historico.txt", "a", encoding="utf-8") as arquivo:
        arquivo.write(texto + "\n")


def ler_historico():
    try:
        with open("historico.txt", "r", encoding="utf-8") as arquivo:
            return arquivo.read()
    except FileNotFoundError:
        return "Histórico vazio."


def limpar_historico():
    with open("historico.txt", "w", encoding="utf-8") as arquivo:
        arquivo.write("")
