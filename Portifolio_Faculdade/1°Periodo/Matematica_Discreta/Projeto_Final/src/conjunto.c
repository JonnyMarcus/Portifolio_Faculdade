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
void pertinencia(int A[], int nA, int x)
{
    if (contem(A, nA, x))
        printf("%d pertence ao conjunto.\n", x);
    else
        printf("%d nao pertence ao conjunto.\n", x);
}

void menu_conjuntos()
{
    int opcao, A[MAX_ELEMENTOS], B[MAX_ELEMENTOS], nA, nB, x;

    printf("Quantos elementos tem A? ");
    scanf("%d", &nA);
    for (int i = 0; i < nA; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Quantos elementos tem B? ");
    scanf("%d", &nB);
    for (int i = 0; i < nB; i++)
    {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    do
    {
        printf("\n=== CONJUNTOS ===\n");
        printf("1 - Uniao\n");
        printf("2 - Intersecao\n");
        printf("3 - Diferenca\n");
        printf("4 - Diferenca Simetrica\n");
        printf("5 - Pertinencia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            uniao(A, nA, B, nB);
            break;
        case 2:
            intersecao(A, nA, B, nB);
            break;
        case 3:
            diferenca(A, nA, B, nB);
            break;
        case 4:
            diferenca_simetrica(A, nA, B, nB);
            break;
        case 5:
            printf("Digite o elemento: ");
            scanf("%d", &x);
            pertinencia(A, nA, x);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}