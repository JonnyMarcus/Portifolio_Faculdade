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
void verifica_reflexivo(int A[][], int nA)
{
    for (int i = 0; i < nA; i++)
    {
    }
}
