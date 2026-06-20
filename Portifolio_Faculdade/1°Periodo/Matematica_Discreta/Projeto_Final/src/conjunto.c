#include <stdio.h>
#include "conjuntos.h"

int contem(int v[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return 1;
    return 0;
}
void uniao(int A[], int nA, int B[], int nB)
{
    int resultado[MAX_ELEMENTOS];
    int nR = 0;

    for (int i = 0; i < nA; i++)
        resultado[nR++] = A[i];

    for (int i = 0; i < nB; i++)
        if (!contem(resultado, nR, B[i]))
            resultado[nR++] = B[i];

    printf("Uniao: { ");
    for (int i = 0; i < nR; i++)
        printf("%d ", resultado[i]);
    printf("}\n");
}
void intersecao(int A[], int nA, int B[], int nB)
{
    printf("Intersecao: { ");
    for (int i = 0; i < nA; i++)
        if (contem(B, nB, A[i]))
            printf("%d ", A[i]);
    printf("}\n");
}
void diferenca(int A[], int nA, int B[], int nB)
{
    printf("Diferenca (A - B): { ");
    for (int i = 0; i < nA; i++)
        if (!contem(B, nB, A[i]))
            printf("%d ", A[i]);
    printf("}\n");
}
void diferenca_simetrica(int A[], int nA, int B[], int nB)
{
    printf("Diferenca Simetrica: { ");
    for (int i = 0; i < nA; i++)
        if (!contem(B, nB, A[i]))
            printf("%d ", A[i]);
    for (int i = 0; i < nB; i++)
        if (!contem(A, nA, B[i]))
            printf("%d ", B[i]);
    printf("}\n");
}