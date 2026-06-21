#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversao.h"
#include "memoria.h"
#include "utils.h"

void menu_conversoes(void)
{
    int opcao, valor;
    char entrada[65], saida[65];

    do
    {
        limpar_tela();
        exibir_cabecalho();
        printf("  ── CONVERSÕES NUMÉRICAS ──\n\n");
        printf("  [1]  Decimal  → Binário\n");
        printf("  [2]  Decimal  → Octal\n");
        printf("  [3]  Decimal  → Hexadecimal\n");
        printf("  [4]  Binário  → Decimal\n");
        printf("  [5]  Octal    → Decimal\n");
        printf("  [6]  Hex      → Decimal\n");
        printf("  [7]  Binário  → Octal\n");
        printf("  [8]  Octal    → Binário\n");
        printf("  [9]  Binário  → Hexadecimal\n");
        printf("  [10] Hex      → Binário\n");
        printf("  [0]  Voltar\n\n");

        if (!ler_inteiro("  Opcao: ", &opcao))
        {
            opcao = -1;
        }

        if (opcao == 0)
            break;

        exibir_separador();

        switch (opcao)
        {
        case 1:
            if (!ler_inteiro("  Decimal: ", &valor))
            {
                printf("  Entrada invalida.\n");
                break;
            }
            decimal_para_binario(valor, saida);
            printf("  %d (dec) = %s (bin)\n", valor, saida);
            break;
        case 2:
            if (!ler_inteiro("  Decimal: ", &valor))
            {
                printf("  Entrada invalida.\n");
                break;
            }
            decimal_para_octal(valor, saida);
            printf("  %d (dec) = %s (oct)\n", valor, saida);
            break;
        case 3:
            if (!ler_inteiro("  Decimal: ", &valor))
            {
                printf("  Entrada invalida.\n");
                break;
            }
            decimal_para_hex(valor, saida);
            printf("  %d (dec) = %s (hex)\n", valor, saida);
            break;
        case 4:
            ler_string("  Binario: ", entrada, sizeof(entrada));
            valor = binario_para_decimal(entrada);
            if (valor < 0)
                printf("  Entrada invalida.\n");
            else
                printf("  %s (bin) = %d (dec)\n", entrada, valor);
            break;
        case 5:
            ler_string("  Octal: ", entrada, sizeof(entrada));
            valor = octal_para_decimal(entrada);
            if (valor < 0)
                printf("  Entrada invalida.\n");
            else
                printf("  %s (oct) = %d (dec)\n", entrada, valor);
            break;
        case 6:
            ler_string("  Hexadecimal: ", entrada, sizeof(entrada));
            valor = hex_para_decimal(entrada);
            if (valor < 0)
                printf("  Entrada invalida.\n");
            else
                printf("  %s (hex) = %d (dec)\n", entrada, valor);
            break;
        case 7:
            ler_string("  Binario: ", entrada, sizeof(entrada));
            binario_para_octal(entrada, saida);
            printf("  %s (bin) = %s (oct)\n", entrada, saida);
            break;
        case 8:
            ler_string("  Octal: ", entrada, sizeof(entrada));
            octal_para_binario(entrada, saida);
            printf("  %s (oct) = %s (bin)\n", entrada, saida);
            break;
        case 9:
            ler_string("  Binario: ", entrada, sizeof(entrada));
            binario_para_hex(entrada, saida);
            printf("  %s (bin) = %s (hex)\n", entrada, saida);
            break;
        case 10:
            ler_string("  Hexadecimal: ", entrada, sizeof(entrada));
            hex_para_binario(entrada, saida);
            printf("  %s (hex) = %s (bin)\n", entrada, saida);
            break;
        default:
            printf("  Opcao invalida.\n");
        }

        pausar();
    } while (1);
}

void menu_operacoes_binarias(void)
{
    int opcao, valor;
    char a[65], b[65], resultado[65];

    do
    {
        limpar_tela();
        exibir_cabecalho();
        printf("  ── OPERAÇÕES BINÁRIAS ──\n\n");
        printf("  [1] Soma binária\n");
        printf("  [2] Bits necessários para representar N\n");
        printf("  [3] Converter bits → bytes\n");
        printf("  [0] Voltar\n\n");

        if (!ler_inteiro("  Opcao: ", &opcao))
        {
            opcao = -1;
        }
        if (opcao == 0)
            break;

        exibir_separador();

        switch (opcao)
        {
        case 1:
            ler_string("  Binario A: ", a, sizeof(a));
            ler_string("  Binario B: ", b, sizeof(b));
            soma_binaria(a, b, resultado);
            if (strcmp(resultado, "ERRO") == 0)
                printf("  Entrada invalida.\n");
            else
                printf("  %s + %s = %s\n", a, b, resultado);
            break;
        case 2:
            if (!ler_inteiro("  Valor decimal N: ", &valor))
            {
                printf("  Entrada invalida.\n");
                break;
            }
            printf("  Bits necessarios para %d: %d bit(s)\n", valor, bits_necessarios(valor));
            break;
        case 3:
            if (!ler_inteiro("  Quantidade de bits: ", &valor))
            {
                printf("  Entrada invalida.\n");
                break;
            }
            printf("  %d bit(s) = %d byte(s)\n", valor, (valor + 7) / 8);
            break;
        default:
            printf("  Opcao invalida.\n");
        }

        pausar();
    } while (1);
}

void menu_memoria(void)
{
    static Memoria mem;
    static int inicializado = 0;

    if (!inicializado)
    {
        memoria_inicializar(&mem);
        inicializado = 1;
    }

    int opcao, endereco, valor, bits, bytes, palavras;

    do
    {
        limpar_tela();
        exibir_cabecalho();
        printf("  ── SIMULAÇÕES DE MEMÓRIA ──\n\n");
        printf("  [1] Armazenar valor em um endereco\n");
        printf("  [2] Ler valor de um endereco\n");
        printf("  [3] Exibir mapa de memoria\n");
        printf("  [4] Calcular espaco (bits → bytes → palavras)\n");
        printf("  [5] Simular enderecos para N bytes\n");
        printf("  [0] Voltar\n\n");

        if (!ler_inteiro("  Opcao: ", &opcao))
        {
            opcao = -1;
        }
        if (opcao == 0)
            break;

        exibir_separador();

        switch (opcao)
        {
        case 1:
            if (!ler_inteiro("  Endereco (0-255): ", &endereco))
            {
                printf("  Invalido.\n");
                break;
            }
            if (!ler_inteiro("  Valor (0-255): ", &valor))
            {
                printf("  Invalido.\n");
                break;
            }
            if (memoria_armazenar(&mem, endereco, valor))
                printf("  Valor %d armazenado em 0x%02X.\n", valor & 0xFF, endereco);
            break;
        case 2:
            if (!ler_inteiro("  Endereco (0-255): ", &endereco))
            {
                printf("  Invalido.\n");
                break;
            }
            valor = memoria_ler(&mem, endereco);
            if (valor < 0)
                printf("  Endereco invalido.\n");
            else
            {
                char bin[10];
                decimal_para_binario(valor, bin);
                printf("  Endereco 0x%02X → Decimal: %d | Binario: %s\n", endereco, valor, bin);
            }
            break;
        case 3:
        {
            int ini, fim;
            if (!ler_inteiro("  Inicio (0-255): ", &ini))
            {
                printf("  Invalido.\n");
                break;
            }
            if (!ler_inteiro("  Fim   (0-255): ", &fim))
            {
                printf("  Invalido.\n");
                break;
            }
            memoria_exibir_mapa(&mem, ini, fim);
            break;
        }
        case 4:
            if (!ler_inteiro("  Quantidade de bits: ", &bits))
            {
                printf("  Invalido.\n");
                break;
            }
            memoria_calcular_espaco(bits, &bytes, &palavras);
            printf("  %d bit(s) → %d byte(s) → %d palavra(s) de 32 bits\n", bits, bytes, palavras);
            break;
        case 5:
            if (!ler_inteiro("  Quantidade de bytes: ", &bytes))
            {
                printf("  Invalido.\n");
                break;
            }
            memoria_simular_enderecos(bytes);
            break;
        default:
            printf("  Opcao invalida.\n");
        }

        pausar();
    } while (1);
}

void exibir_visao_completa(void)
{
    int valor;
    limpar_tela();
    exibir_cabecalho();
    printf("  ── VISÃO COMPLETA DE UM NÚMERO ──\n\n");

    if (!ler_inteiro("  Numero decimal: ", &valor))
    {
        printf("  Entrada invalida.\n");
        pausar();
        return;
    }

    char bin[65], oct[32], hex[32];
    decimal_para_binario(valor, bin);
    decimal_para_octal(valor, oct);
    decimal_para_hex(valor, hex);

    int bits = bits_necessarios(valor);
    int bytes, palavras;
    memoria_calcular_espaco(bits, &bytes, &palavras);

    exibir_separador();
    printf("  Decimal     : %d\n", valor);
    printf("  Binario     : %s\n", bin);
    printf("  Octal       : %s\n", oct);
    printf("  Hexadecimal : %s\n", hex);
    exibir_separador();
    printf("  Bits necessarios : %d\n", bits);
    printf("  Bytes ocupados   : %d\n", bytes);
    printf("  Palavras (32bit) : %d\n", palavras);

    pausar();
}

int main(void)
{
    int opcao;

    do
    {
        limpar_tela();
        exibir_cabecalho();
        printf("  ── MENU PRINCIPAL ──\n\n");
        printf("  [1] Conversoes Numericas\n");
        printf("  [2] Operacoes Binarias\n");
        printf("  [3] Simulacoes de Memoria\n");
        printf("  [4] Visao Completa de um Numero\n");
        printf("  [0] Sair\n\n");

        if (!ler_inteiro("  Opcao: ", &opcao))
        {
            opcao = -1;
        }

        switch (opcao)
        {
        case 1:
            menu_conversoes();
            break;
        case 2:
            menu_operacoes_binarias();
            break;
        case 3:
            menu_memoria();
            break;
        case 4:
            exibir_visao_completa();
            break;
        case 0:
            printf("\n  Encerrando. Ate mais!\n\n");
            break;
        default:
            printf("\n  Opcao invalida.\n");
            pausar();
            break;
        }
    } while (opcao != 0);

    return 0;
}
