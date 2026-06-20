#include <stdio.h>

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
        }

    } while (opcao != 0);

    return 0;
}
