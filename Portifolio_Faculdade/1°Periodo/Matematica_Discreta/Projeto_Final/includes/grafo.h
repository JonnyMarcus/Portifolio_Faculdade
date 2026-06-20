#ifndef GRAFO_H
#define GRAFO_H
#include "utils.h"

typedef struct
{
    int adj[MAX_ELEMENTOS][MAX_ELEMENTOS];
    int nVertices;

} grafo;

void cria_grafo(grafo *g);

void inseri_vertice(grafo *g);

void inseri_aresta(grafo *g);

void grau_vertice(grafo *g);

void BFS(grafo *g);

void DFS(grafo *g);

void menu_grafo(grafo *g);

#endif