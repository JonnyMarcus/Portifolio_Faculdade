#ifndef MEMORIA_H
#define MEMORIA_H

#define TAM_MEMORIA 256

typedef struct
{
    unsigned char celulas[TAM_MEMORIA];
    int ocupado[TAM_MEMORIA];
} Memoria;

void memoria_inicializar(Memoria *mem);
int memoria_armazenar(Memoria *mem, int endereco, int valor);
int memoria_ler(Memoria *mem, int endereco);
void memoria_exibir_mapa(Memoria *mem, int inicio, int fim);
void memoria_calcular_espaco(int bits, int *bytes, int *palavras);
void memoria_simular_enderecos(int quantidade_bytes);

#endif