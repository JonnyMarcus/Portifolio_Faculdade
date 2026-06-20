#include <stdio.h>
#include "conjuntos.h"
#include "logica.h"
#include "relacoes.h"
#include "historico.h"
#include "grafo.h"

int main()
{
    int opcao;

    do
    {

        printf("1 - Conjuntos\n");
        printf("2 - Relacoes\n");
        printf("3 - Logica\n");
        printf("4 - Grafos\n");
        printf("5 - Historico\n");
        printf("0 - Sair\n");

        printf("Digite um numero(0 para sair): ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_conjuntos();
            break;
        case 2:
            menu_relacoes();
            break;
        case 3:
            menu_logica();
            break;
        case 4:
            menu_grafo();
            break;
        case 5:
            menu_historico();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
