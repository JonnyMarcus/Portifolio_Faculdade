#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void limpar_tela(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pausar(void)
{
    printf("\n  Pressione ENTER para continuar...");
    limpar_buffer();
    getchar();
}

void exibir_cabecalho(void)
{
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║    Simulador de Conversao Numerica e Memoria         ║\n");
    printf("║    Arquitetura de Computadores I — Jonny Marcus      ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n\n");
}

void exibir_separador(void)
{
    printf("\n  ──────────────────────────────────────────────────\n\n");
}

// Retorna 1 se leu com sucesso, 0 se entrada inválida
int ler_inteiro(const char *msg, int *valor)
{
    printf("%s", msg);
    if (scanf("%d", valor) != 1)
    {
        limpar_buffer();
        return 0;
    }
    limpar_buffer();
    return 1;
}

void ler_string(const char *msg, char *buffer, int tamanho)
{
    printf("%s", msg);
    if (fgets(buffer, tamanho, stdin))
    {
        // Remove newline
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}