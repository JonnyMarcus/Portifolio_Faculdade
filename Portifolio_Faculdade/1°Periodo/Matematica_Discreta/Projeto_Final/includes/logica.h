#ifndef LOGICA_H
#define LOGICA_H

#include "utils.h"

int op_and(int p, int q);
int op_or(int p, int q);
int op_not(int p);
int op_xor(int p, int q);
int op_implicacao(int p, int q);
int op_bicondicional(int p, int q);
void tabela_verdade();
void menu_logica();

#endif