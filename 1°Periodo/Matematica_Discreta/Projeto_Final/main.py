from Conjuntos import *
from Relacoes import *
from Grafos import *
from Logica import *

def menu():
    print("\n===== Sistema de Operações com Conjuntos =====")
    print("1 - União")
    print("2 - Interseção")
    print("3 - Diferença")
    print("4 - Diferença Simétrica")
    print("5 - Verificar Subconjunto")
    print("6 - Produto Cartesiano")
    print("7 - Verificar Relação Reflexiva")
    print("8 - Verificar Relação Simétrica")
    print("9 - Verificar Relação Transitiva")
    print("10 - Lógica AND")
    print("11 - Lógica OR")
    print("12 - Lógica NOT")
    print("13 - Implicação")
    print("14 - Grafo Básico")
    print("0 - Sair")


while True:
    menu()
    opcao = input("Escolha uma opção : ")
    match opcao:
        case "0":
            print("Encerrando...")
            break


while True:
    menu()
    opcao = input("Escolha uma opção: ")

    match opcao:
        case "0":
            print("Encerrando...")
            break

        case "1":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("União:", uniao(a, b))

        case "2":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("Interseção:", intersecao(a, b))

        case "3":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("Diferença A-B:", diferenca(a, b))

        case "4":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("Diferença Simétrica:", diferenca_simetrica(a, b))

        case "5":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("A é subconjunto de B?", verificar_subconjunto(a, b))
        case "6":
            a = ler_conjunto("A")
            b = ler_conjunto("B")
            print("Produto Cartesiano:", produto_cartesiano(a, b))

        case "7":
            conjunto = ler_conjunto("A")
            relacao = {(x, x) for x in conjunto}
            print("É reflexiva?", relacao_reflexiva(conjunto, relacao))

        case "8":
            relacao = {("1", "2"), ("2", "1")}
            print("É simétrica?", relacao_simetrica(relacao))

        case "9":
            relacao = {("1", "2"), ("2", "3"), ("1", "3")}
            print("É transitiva?", relacao_transitiva(relacao))
        case "10":
             p = input("P (True/False): ") == "True"
             q = input("Q (True/False): ") == "True"
             print("Resultado:", proposicao_and(p, q))

        case "11":
            p = input("P (True/False): ") == "True"
            q = input("Q (True/False): ") == "True"
            print("Resultado:", proposicao_or(p, q))

        case "12":
            p = input("P (True/False): ") == "True"
            print("Resultado:", proposicao_not(p))

        case "13":
            p = input("P (True/False): ") == "True"
            q = input("Q (True/False): ") == "True"
            print("Resultado:", implicacao(p, q))

        case "14":
            grafo = criar_grafo()
            adicionar_aresta(grafo, "A", "B")
            adicionar_aresta(grafo, "A", "C")
            adicionar_aresta(grafo, "B", "C")
            mostrar_grafo(grafo)
            print("Grau de A:", grau_vertice(grafo, "A"))
        case _:
            print("Opção inválida!")

                
