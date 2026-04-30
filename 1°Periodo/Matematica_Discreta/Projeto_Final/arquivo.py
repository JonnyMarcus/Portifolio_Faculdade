def salvar_resultado(texto):
    with open("historico.txt", "a", encoding="utf-8") as arquivo:
        arquivo.write(texto + "\n")