#include <stdio.h>
#include "relacoes.h"

void produto_cartesiano(int A[], int nA, int B[], int nB)
{
    for (int i = 0; i < nA; i++)
    {
        for (int j = 0; j < nB; j++)
        {
            printf("(%i, %i) ", A[i], B[j]);
        }
    }
}
void verifica_reflexiva(int A[][100], int nA)
{
    int reflexiva = 1; // assume que é reflexiva

    for (int i = 0; i < nA; i++)
    {
        if (A[i][i] == 0)
        {
            reflexiva = 0;
        }
    }

    if (reflexiva == 1)
        printf("A relacao E reflexiva\n");
    else
        printf("A relacao NAO E reflexiva\n");
}
void verifica_simetrica(int A[][100], int nA)
{
    int simetrica = 1;

    for (int i = 0; i < nA; i++)
    {
        for (int j = 0; j < nA; j++)
        {
            if (A[i][j] != A[j][i])
            {
                simetrica = 0;
            }
        }
    }

    if (simetrica == 1)
        printf("A relacao E simetrica\n");
    else
        printf("A relacao NAO E simetrica\n");
}
void verifica_transitiva(int A[][MAX_ELEMENTOS], int nA)
{
    int transitiva = 1;

    for (int i = 0; i < nA; i++)
    {
        for (int j = 0; j < nA; j++)
        {
            for (int k = 0; k < nA; k++)
            {

                if (A[i][j] == 1 && A[j][k] == 1 && A[i][k] == 0)
                    transitiva = 0;
            }
        }
    }

    if (transitiva == 1)
        printf("A relacao E transitiva\n");
    else
        printf("A relacao NAO E transitiva\n");
}
void menu_relacoes()
{
    int opcao;
    int A[MAX_ELEMENTOS][MAX_ELEMENTOS] = {0};
    int B[MAX_ELEMENTOS], nB, nA;

    printf("Tamanho do conjunto: ");
    scanf("%d", &nA);

    printf("Digite a matriz de adjacencia (%dx%d) linha por linha:\n", nA, nA);
    for (int i = 0; i < nA; i++)
        for (int j = 0; j < nA; j++)
            scanf("%d", &A[i][j]);

    do
    {
        printf("\n=== RELACOES ===\n");
        printf("1 - Produto Cartesiano\n2 - Verificar Reflexiva\n3 - Verificar Simetrica\n4 - Verificar Transitiva\n0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Tamanho de B: ");
            scanf("%d", &nB);
            for (int i = 0; i < nB; i++)
            {
                printf("B[%d]: ", i);
                scanf("%d", &B[i]);
            }
            int Av[MAX_ELEMENTOS];
            for (int i = 0; i < nA; i++)
                Av[i] = i;
            produto_cartesiano(Av, nA, B, nB);
            break;
        case 2:
            verifica_reflexiva(A, nA);
            break;
        case 3:
            verifica_simetrica(A, nA);
            break;
        case 4:
            verifica_transitiva(A, nA);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}