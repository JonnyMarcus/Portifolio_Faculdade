#include <stdio.h>
#include "utils.h"

void limpar_tela()
{
    system("clear ||  cls");
}

void pausar()
{
    printf("\nPrecione ENTER para continuar... ");
    getchar();
    getchar();
}