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
}
