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

void grau_vertice(grafo *g)
{
    int v;
    printf("Digite o vertice: ");
    scanf("%d", &v);

    int grau = 0;
    for (int i = 0; i < MAX_ELEMENTOS; i++)
    {
        if (g->adj[v][i] == 1)
        {
            grau++;
        }
    }
    printf("Grau do vertice %d: %d\n", v, grau);
}
void BFS(grafo *g, int inicio)
{
    int visitado[MAX_ELEMENTOS] = {0};
    int fila[MAX_ELEMENTOS];
    int frente = 0, tras = 0;

    fila[tras++] = inicio;
    visitado[inicio] = 1;

    while (frente != tras)
    {
        // 1. remove o primeiro da fila
        int v = fila[frente++];

        // 2. imprime
        printf("%d ", v);

        // 3. percorre vizinhos
        for (int i = 0; i < g->nVertices; i++)
        {
            if (g->adj[v][i] == 1 && visitado[i] == 0)
            {
                visitado[i] = 1;
                fila[tras++] = i;
            }
        }
    }
}

void DFS(grafo *g, int inicio)
{
    int visitado[MAX_ELEMENTOS] = {0};
    int pilha[MAX_ELEMENTOS];
    int topo = 0;

    pilha[topo++] = inicio;
    visitado[inicio] = 1;

    while (topo > 0)
    {
        // 1. remove o primeiro da fila
        int v = pilha[--topo];

        // 2. imprime
        printf("%d ", v);

        // 3. percorre vizinhos
        for (int i = 0; i < g->nVertices; i++)
        {
            if (g->adj[v][i] == 1 && visitado[i] == 0)
            {
                visitado[i] = 1;
                pilha[topo++] = i;
            }
        }
    }
}
void menu_grafo()
{
    int opcao;
    grafo g;
    cria_grafo(&g);

    do
    {
        printf("\n=== GRAFOS ===\n");
        printf("1 - Inserir Vertice\n2 - Inserir Aresta\n3 - Grau do Vertice\n4 - BFS\n5 - DFS\n0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inseri_vertice(&g);
            break;
        case 2:
            inserir_aresta(&g);
            break;
        case 3:
            grau_vertice(&g);
            break;
        case 4:
            printf("Vertice inicial: ");
            int ini;
            scanf("%d", &ini);
            BFS(&g, ini);
            break;
        case 5:
            printf("Vertice inicial: ");
            int ini2;
            scanf("%d", &ini2);
            DFS(&g, ini2);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}
