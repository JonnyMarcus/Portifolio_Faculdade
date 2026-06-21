#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conversao.h"

void decimal_para_binario(int n, char *resultado)
{
    if (n == 0)
    {
        strcpy(resultado, "0");
        return;
    }

    char temp[65];
    int i = 0;
    int negativo = (n < 0);
    if (negativo)
        n = -n;

    while (n > 0)
    {
        temp[i++] = '0' + (n % 2);
        n /= 2;
    }
    if (negativo)
        temp[i++] = '-';
    temp[i] = '\0';

    // Inverte a string
    int len = strlen(temp);
    for (int j = 0; j < len; j++)
        resultado[j] = temp[len - 1 - j];
    resultado[len] = '\0';
}

void decimal_para_octal(int n, char *resultado)
{
    if (n == 0)
    {
        strcpy(resultado, "0");
        return;
    }

    char temp[32];
    int i = 0;
    int negativo = (n < 0);
    if (negativo)
        n = -n;

    while (n > 0)
    {
        temp[i++] = '0' + (n % 8);
        n /= 8;
    }
    if (negativo)
        temp[i++] = '-';
    temp[i] = '\0';

    int len = strlen(temp);
    for (int j = 0; j < len; j++)
        resultado[j] = temp[len - 1 - j];
    resultado[len] = '\0';
}

void decimal_para_hex(int n, char *resultado)
{
    if (n == 0)
    {
        strcpy(resultado, "0");
        return;
    }

    const char hex_chars[] = "0123456789ABCDEF";
    char temp[32];
    int i = 0;
    int negativo = (n < 0);
    if (negativo)
        n = -n;

    while (n > 0)
    {
        temp[i++] = hex_chars[n % 16];
        n /= 16;
    }
    if (negativo)
        temp[i++] = '-';
    temp[i] = '\0';

    int len = strlen(temp);
    for (int j = 0; j < len; j++)
        resultado[j] = temp[len - 1 - j];
    resultado[len] = '\0';
}

int binario_para_decimal(const char *bin)
{
    int resultado = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++)
    {
        if (bin[i] != '0' && bin[i] != '1')
            return -1; // inválido
        resultado = resultado * 2 + (bin[i] - '0');
    }
    return resultado;
}

int octal_para_decimal(const char *oct)
{
    int resultado = 0;
    int len = strlen(oct);
    for (int i = 0; i < len; i++)
    {
        if (oct[i] < '0' || oct[i] > '7')
            return -1;
        resultado = resultado * 8 + (oct[i] - '0');
    }
    return resultado;
}

int hex_para_decimal(const char *hex)
{
    int resultado = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++)
    {
        char c = hex[i];
        int val;
        if (c >= '0' && c <= '9')
            val = c - '0';
        else if (c >= 'A' && c <= 'F')
            val = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            val = c - 'a' + 10;
        else
            return -1;
        resultado = resultado * 16 + val;
    }
    return resultado;
}

void binario_para_octal(const char *bin, char *resultado)
{
    int dec = binario_para_decimal(bin);
    if (dec < 0)
    {
        strcpy(resultado, "ERRO");
        return;
    }
    decimal_para_octal(dec, resultado);
}

void octal_para_binario(const char *oct, char *resultado)
{
    int dec = octal_para_decimal(oct);
    if (dec < 0)
    {
        strcpy(resultado, "ERRO");
        return;
    }
    decimal_para_binario(dec, resultado);
}

void binario_para_hex(const char *bin, char *resultado)
{
    int dec = binario_para_decimal(bin);
    if (dec < 0)
    {
        strcpy(resultado, "ERRO");
        return;
    }
    decimal_para_hex(dec, resultado);
}

void hex_para_binario(const char *hex, char *resultado)
{
    int dec = hex_para_decimal(hex);
    if (dec < 0)
    {
        strcpy(resultado, "ERRO");
        return;
    }
    decimal_para_binario(dec, resultado);
}

void soma_binaria(const char *a, const char *b, char *resultado)
{
    int dec_a = binario_para_decimal(a);
    int dec_b = binario_para_decimal(b);
    if (dec_a < 0 || dec_b < 0)
    {
        strcpy(resultado, "ERRO");
        return;
    }
    decimal_para_binario(dec_a + dec_b, resultado);
}

int bits_necessarios(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        n = -n;
    int bits = 0;
    while (n > 0)
    {
        bits++;
        n >>= 1;
    }
    return bits;
}