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