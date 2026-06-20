#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include "utils.h"

void uniao(int A[], int nA, int B[], int nB);
void intersecao(int A[], int nA, int B[], int nB);
void diferenca(int A[], int nA, int B[], int nB);
void diferenca_simetrica(int A[], int nA, int B[], int nB);
void pertinencia(int A[], int nA, int x);
void menu_conjuntos();

#endif