#include <stdio.h>
#include "grafo.h"

void cria_grafo(grafo *g)
{

    for (int i = 0; i < MAX_ELEMENTOS; i++)
    {
        for (int j = 0; j < MAX_ELEMENTOS; j++)
        {
            g->adj[i][j] = 0;
        }
    }
    g->nVertices = 0;
    printf("grafo criado com sucesso");
}
void inseri_vertice(grafo *g)
{
    if (g->nVertices == MAX_ELEMENTOS)
    {
        printf("ERRO matrix cheia \n");
    }
    else
    {
        g->nVertices++;
        printf("Vertice inserida com sucesso");
    }
}
void inserir_aresta(grafo *g)
{
    int i, j;
    scanf("%d %d", &i, &j);

    if (i >= g->nVertices || j >= g->nVertices)
        printf("Vertice invalido\n");
    else
    {
        g->adj[i][j] = 1;
        g->adj[j][i] = 1;
        printf("Aresta inserida com sucesso\n");
    }
}