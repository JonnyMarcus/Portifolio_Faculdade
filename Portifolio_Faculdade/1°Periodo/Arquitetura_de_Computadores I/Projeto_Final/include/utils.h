#ifndef UTILS_H
#define UTILS_H

void limpar_tela(void);
void limpar_buffer(void);
void pausar(void);
void exibir_cabecalho(void);
void exibir_separador(void);
int ler_inteiro(const char *msg, int *valor);
void ler_string(const char *msg, char *buffer, int tamanho);

#endif
