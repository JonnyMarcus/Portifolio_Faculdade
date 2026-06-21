#include <stdio.h>
#include <string.h>
#include "conversao.h"

void binario_decimal()
{
    int decimal = 0;
    char bin[50];

    printf("escreva o numero binario: ");
    scanf("%s", bin);

    for (int i = 0; bin[i] != '\0'; i++)
    {
        int bit = bin[i] - '0';
        decimal = decimal * 2 + bit;
    }
    printf("\nDecimal: %d\n", decimal);
}

void decimal_binario()
{
    char bin[50];
    int dec;
    int i = 0;

    printf("escreva o decimal: ");
    scanf("%d", &dec);

    if (dec == 0)
    {
        printf("0\n");
        return;
    }

    while (dec > 0)
    {
        bin[i++] = dec % 2;
        dec = dec / 2;
    }

    printf("\nBinario: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", bin[j]);
    }
    printf("\n");
}

void binario_hexadecimal()
{
    char bin[50];
    char temp[50];
    temp[0] = '\0';

    printf("digite o numero binario: ");
    scanf("%s", bin);

    int len = strlen(bin);
    int resto = len % 4;
    if (resto != 0)
    {
        int faltam = 4 - resto;
        for (int i = 0; i < faltam; i++)
            strcat(temp, "0");
        strcat(temp, bin);
        strcpy(bin, temp);
    }

    printf("Hexadecimal: ");
    for (int i = 0; bin[i] != '\0'; i += 4)
    {
        int valor = 0;
        for (int j = 0; j < 4; j++)
            valor = valor * 2 + (bin[i + j] - '0');

        if (valor < 10)
            printf("%d", valor);
        else
            printf("%c", valor - 10 + 'A');
    }
    printf("\n");
}

void hexadecimal_binario()
{
    char hexadecimal[50];

    printf("escreva o numero hexadecimal: ");
    scanf("%s", hexadecimal);

    printf("Binario: ");

    for (int i = 0; hexadecimal[i] != '\0'; i++)
    {

        int valor;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
            valor = hexadecimal[i] - '0';
        else
            valor = hexadecimal[i] - 'A' + 10;
        for (int j = 3; j >= 0; j--)
        {
            printf("%d", (valor >> j) & 1);
        }
    }
    printf("\n");
}
void octal_binario()
{
    char binario[50];

    printf("escreva o numero binario: ");
    scanf("%s", binario);

    printf("Binario: ");

    for (int i = 0; binario[i] != '\0'; i++)
    {

        int valor;
        if (binario[i] >= '0' && binario[i] <= '9')
            valor = binario[i] - '0';
        else
            valor = binario[i] - 'A' + 10;
        for (int j = 2; j >= 0; j--)
        {
            printf("%d", (valor >> j) & 1);
        }
    }
    printf("\n");
}
void menu_conversao()
{
}