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
}