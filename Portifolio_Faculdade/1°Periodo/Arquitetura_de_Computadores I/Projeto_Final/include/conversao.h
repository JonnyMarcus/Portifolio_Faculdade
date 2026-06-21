#ifndef CONVERSOES_H
#define CONVERSOES_H

// Decimal -> outras bases
void decimal_para_binario(int n, char *resultado);
void decimal_para_octal(int n, char *resultado);
void decimal_para_hex(int n, char *resultado);

// Outras bases -> Decimal
int binario_para_decimal(const char *bin);
int octal_para_decimal(const char *oct);
int hex_para_decimal(const char *hex);

// Entre bases não-decimais
void binario_para_octal(const char *bin, char *resultado);
void octal_para_binario(const char *oct, char *resultado);
void binario_para_hex(const char *bin, char *resultado);
void hex_para_binario(const char *hex, char *resultado);

// Operações binárias
void soma_binaria(const char *a, const char *b, char *resultado);
int bits_necessarios(int n);

#endif
