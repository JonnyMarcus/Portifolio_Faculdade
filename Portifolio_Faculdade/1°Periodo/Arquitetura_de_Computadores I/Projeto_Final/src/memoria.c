#include <stdio.h>
#include <string.h>
#include "memoria.h"
#include "conversao.h"

void memoria_inicializar(Memoria *mem)
{
    memset(mem->celulas, 0, sizeof(mem->celulas));
    memset(mem->ocupado, 0, sizeof(mem->ocupado));
}

int memoria_armazenar(Memoria *mem, int endereco, int valor)
{
    if (endereco < 0 || endereco >= TAM_MEMORIA)
    {
        printf("  [ERRO] Endereco 0x%02X fora do intervalo.\n", endereco);
        return 0;
    }
    mem->celulas[endereco] = (unsigned char)(valor & 0xFF);
    mem->ocupado[endereco] = 1;
    return 1;
}

int memoria_ler(Memoria *mem, int endereco)
{
    if (endereco < 0 || endereco >= TAM_MEMORIA)
        return -1;
    return mem->celulas[endereco];
}

void memoria_exibir_mapa(Memoria *mem, int inicio, int fim)
{
    if (inicio < 0)
        inicio = 0;
    if (fim >= TAM_MEMORIA)
        fim = TAM_MEMORIA - 1;

    printf("\n  +----------+----------+----------+---------+\n");
    printf("  | Endereco |  Decimal |  Binario | Ocupado |\n");
    printf("  +----------+----------+----------+---------+\n");

    char bin[10];
    for (int i = inicio; i <= fim; i++)
    {
        decimal_para_binario(mem->celulas[i], bin);
        printf("  |  0x%02X    |   %3d    | %8s |   %s   |\n",
               i, mem->celulas[i], bin, mem->ocupado[i] ? "S" : "N");
    }
    printf("  +----------+----------+----------+---------+\n");
}

void memoria_calcular_espaco(int bits, int *bytes, int *palavras)
{
    *bytes = (bits + 7) / 8;
    *palavras = (*bytes + 3) / 4;
}

void memoria_simular_enderecos(int quantidade_bytes)
{
    printf("\n  Simulacao de enderecos para %d byte(s):\n\n", quantidade_bytes);
    printf("  Byte | Endereco\n");
    printf("  -----|----------\n");
    for (int i = 0; i < quantidade_bytes && i < 16; i++)
    {
        printf("   %3d | 0x%04X\n", i + 1, i);
    }
    if (quantidade_bytes > 16)
        printf("   ... (exibindo apenas os 16 primeiros enderecos)\n");
}