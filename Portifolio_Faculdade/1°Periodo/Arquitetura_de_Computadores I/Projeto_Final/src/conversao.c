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
void binario_octal()
{
    char binario[50];

    printf("escreva o numero binario: ");
    scanf("%s", binario);

    printf("Octal: ");
    int valor;
    for (int i = 0; binario[i] != '\0'; i += 3)
    {
        int valor = 0;
        for (int j = 0; j < 3; j++)
        {
            valor = valor * 2 + (binario[i + j] - '0');
        }
        printf("%d", valor);
    }
    printf("\n");
}

void octal_binario()
{
    char octal[50];

    printf("escreva o numero octal: ");
    scanf("%s", octal);

    printf("Binario: ");

    for (int i = 0; octal[i] != '\0'; i++)
    {

        int valor;
        if (octal[i] >= '0' && octal[i] <= '7')
            valor = octal[i] - '0';
        for (int j = 2; j >= 0; j--)
        {
            printf("%d", (valor >> j) & 1);
        }
    }
    printf("\n");
}

void menu_conversao()
{
    int opcao;

    do
    {
        printf("\n=== CONVERSAO ===\n");
        printf("1. converte decimal para binario\n");
        printf("2. converte binario para decimal\n");
        printf("3. converte binario para octal\n");
        printf("4. converte octal para binario\n");
        printf("5. converte binario para hexadicimal\n");
        printf("6. converte hexadecimal para binario\n");
        printf("0. sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            decimal_binario();
            break;

        case 2:
            binario_decimal();
            break;

        case 3:
            binario_octal();
            break;

        case 4:
            octal_binario();
            break;

        case 5:
            binario_hexadecimal();
            break;

        case 6:
            hexadecimal_binario();
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}
