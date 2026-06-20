#ifndef RELACOES_H
#define RELACOES_H

#include "utils.h"

void produto_cartesiano(int A[], int nA, int B[], int nB);
void verifica_reflexiva(int A[][MAX_ELEMENTOS], int nA);
void verifica_simetrica(int A[][MAX_ELEMENTOS], int nA);
void verifica_transitiva(int A[][MAX_ELEMENTOS], int nA);
void menu_relacoes();

#endif