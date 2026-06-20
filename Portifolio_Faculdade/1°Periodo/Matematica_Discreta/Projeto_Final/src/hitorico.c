#include <stdio.h>
#include "historico.h"

void salva_historico(char *mensagem)
{
    FILE *arquivo = fopen("historico.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    fprintf(arquivo, "%s\n", mensagem);
    fclose(arquivo);
}
void consulta_historico()
{
    FILE *arquivo = fopen("historico.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    char linha[200];
    while (fgets(linha, 200, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    fclose(arquivo);
}
void limpar_historico()
{
    FILE *arquivo = fopen("historico.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao limpar historico\n");
        return;
    }
    fclose(arquivo);
    printf("Historico limpo com sucesso\n");
}
void menu_historico()
{
}