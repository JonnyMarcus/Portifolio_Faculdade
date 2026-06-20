#include <stdio.h>
#include "logica.h"

int op_and(int p, int q)
{
    return p && q;
}

int op_or(int p, int q)
{
    return p || q;
}

int op_not(int p)
{
    return !p;
}

int op_xor(int p, int q)
{
    return p != q;
}

int op_implicacao(int p, int q)
{
    return !p || q;
}

int op_bicondicional(int p, int q)
{
    return p == q;
}

void tabela_verdade()
{
    printf("\np\tq\tAND\tOR\tXOR\tIMP\tBIC\n");
    printf("------------------------------------------------\n");
    for (int p = 0; p <= 1; p++)
        for (int q = 0; q <= 1; q++)
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
                   p, q,
                   op_and(p, q),
                   op_or(p, q),
                   op_xor(p, q),
                   op_implicacao(p, q),
                   op_bicondicional(p, q));
}

void menu_logica()
{
    int opcao, p, q;

    printf("Digite p (0 ou 1): ");
    scanf("%d", &p);
    printf("Digite q (0 ou 1): ");
    scanf("%d", &q);

    do
    {
        printf("\n=== LOGICA ===\n");
        printf("1 - AND\n2 - OR\n3 - NOT\n4 - XOR\n5 - Implicacao\n6 - Bicondicional\n7 - Tabela Verdade\n0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Resultado: %d\n", op_and(p, q));
            break;
        case 2:
            printf("Resultado: %d\n", op_or(p, q));
            break;
        case 3:
            printf("Resultado: %d\n", op_not(p));
            break;
        case 4:
            printf("Resultado: %d\n", op_xor(p, q));
            break;
        case 5:
            printf("Resultado: %d\n", op_implicacao(p, q));
            break;
        case 6:
            printf("Resultado: %d\n", op_bicondicional(p, q));
            break;
        case 7:
            tabela_verdade();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}