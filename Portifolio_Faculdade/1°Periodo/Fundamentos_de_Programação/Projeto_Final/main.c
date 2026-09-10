#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct
{
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
} Aluno;

// CRUD
void cadastra_aluno(Aluno vetor[], int *quantidade)
{

    if (*quantidade >= MAX)
    {
        printf("lista de alunos esta cheia");
        return;
    }

    printf("escreva o nome do aluno \n");
    fgets(vetor[*quantidade].nome, 100, stdin);
    char *pos = strchr(vetor[*quantidade].nome, '\n');
    if (!pos)
    {
        printf("erro alocar nome");
    }
    else
    {
        *pos = '\0';
    }
    printf("escreva a matricula do aluno\n");
    scanf("%d", &vetor[*quantidade].matricula);
    printf("escreva a nota 1 do aluno\n");
    scanf("%f", &vetor[*quantidade].nota_1);
    printf("escreva a nota 2 do aluno \n");
    scanf("%f", &vetor[*quantidade].nota_2);

    vetor[*quantidade].media = calcula_media(vetor[*quantidade].nota_1, vetor[*quantidade].nota_2);
    (*quantidade)++;
}
float calcula_media(float N1, float N2)
{
    float media;
    media = (N1 + N2) / 2;
    return media;
}
void remove_aluno(Aluno vetor[], int *quantidade)
{
    int matricula;
    printf("escreva o numero de matricula do aluno:\n");
    scanf("%d", &matricula);
    int index = buscar_aluno(vetor, *quantidade, matricula);
    if (index == -1)
    {
        printf("aluno nao encontrado\n");
    }
    else
    {
        printf("Removendo...");
        for (int i = index; i < *quantidade - 1; i++)
        {
            vetor[i] = vetor[i + 1];
        }
        (*quantidade)--;
        salva_aluno(vetor, quantidade);
    }
}
void lista_alunos(Aluno vetor[], int quantidade)
{

    if (quantidade == 0)
    {
        printf("nao tem alunos salvos na lista");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("=====================================");
        printf("Matricula:%d \n", vetor[i].matricula);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Nota 1: %.2f \n", vetor[i].nota_1);
        printf("Nota 2: %.2f \n", vetor[i].nota_2);
        printf("Média: %.2f \n", vetor[i].media);
        printf("\n");
    }
}

int buscar_aluno(Aluno vetor[], int quantidade, int matricula)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (vetor[i].matricula == matricula)
        {
            return i;
        }
    }

    return -1;
}
void edita_aluno(Aluno vetor[], int *quantidade)
{
    int matricula;
    printf("escreva o numero de matricula do aluno:\n");
    scanf("%d", &matricula);
    int index = buscar_aluno(vetor, *quantidade, matricula);
    if (index == -1)
    {
        printf("aluno nao encontrado");
    }
    else
    {
        printf("escreva novo o nome do aluno \n");
        fgets(vetor[index].nome, 100, stdin);
        char *pos = strchr(vetor[index].nome, '\n');
        if (!pos)
        {
            printf("erro alocar nome");
        }
        else
        {
            *pos = '\0';
        }
        printf("escreva nova a nota 1 do aluno\n");
        scanf("%f", &vetor[index].nota_1);
        printf("escreva nova a nota 2 do aluno \n");
        scanf("%f", &vetor[index].nota_2);
        vetor[index].media = calcula_media(vetor[index].nota_1, vetor[index].nota_2);
        salva_aluno(vetor, quantidade);
    }
}
// Calculo
float calcula_media_alunos(Aluno vetor[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("nao tem alunos salvos na lista");
        return -1;
    }
    float media = 0;
    for (int i = 0; i < quantidade; i++)
    {
        media += vetor[i].media;
    }
    media = media / quantidade;
    return media;
}
void mostra_situacao(Aluno vetor[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("nao tem alunos salvos na lista");
        return;
    }
    for (int i = 0; i < quantidade; i++)
    {
        if (vetor[i].media >= 6)
        {
            printf("%s -- Aprovado", vetor[i].nome);
        }
        if (vetor[i].media < 6)
        {
            printf("%s -- Reprovado", vetor[i].nome);
        }
    }
}
// Persistencia
void salva_aluno(Aluno vetor[], int *quantidade)
{
    FILE *arquivo = fopen("dados.txt", "w");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo \n");
        return;
    }
    ordena_por_nome(vetor, *quantidade);
    for (int i = 0; i < *quantidade; i++)
    {
        fprintf(arquivo, "%d;%s;%.2f;%.2f;%.2f\n", vetor[i].matricula, vetor[i].nome, vetor[i].nota_1, vetor[i].nota_2, vetor[i].media);
    }

    fclose(arquivo);
}
void carrega_aluno(Aluno vetor[], int *quantidade)
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    int i = 0;
    while (fscanf(arquivo, "%d;%99[^;];%f;%f;%f", &vetor[*quantidade].matricula, vetor[*quantidade].nome, &vetor[*quantidade].nota_1, &vetor[*quantidade].nota_2, &vetor[*quantidade].media) == 5)
        (*quantidade)++;

    fclose(arquivo);
}
// ordenação
void ordena_por_nome(Aluno vetor[], int quantidade)
{
    for (int i = 0; i < quantidade - 1; i++)
    {
        for (int j = 0; j < quantidade - i - 1; j++)
        {
            int strc = strcmp(vetor[j].nome, vetor[j + 1].nome);
            if (strc > 0)
            {
                Aluno temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
            else
            {
            }
        }
    }
}
int main()
{

    Aluno alunos[MAX];
    int opcao, matricula, quantidade = 0;

    carrega_aluno(alunos, &quantidade);
    do
    {
        printf("1. para cadastrar um aluno");
        printf("2. para remover um aluno");
        printf("3. para listar alunos");
        printf("4. para editar um aluno");
        printf("5. para buscar um aluno");
        printf("6. mostra situação dos alunos");
        printf("7. mostra media da turma");
        printf("0. Sair");
        printf("escolha uma opção");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
        {
            printf("Saindo ...");
            salva_aluno(alunos, &quantidade);
            break;
        }

        case 1:
        {
            cadastra_aluno(alunos, &quantidade);
            salva_aluno(alunos, &quantidade);
            break;
        }
        case 2:
        {

            remove_aluno(alunos, &quantidade);
            break;
        }
        case 3:
        {
            lista_alunos(alunos, quantidade);
            break;
        }
        case 4:
            edita_aluno(alunos, &quantidade);
            break;
        case 5:
        {
            printf("escreva o numero de matricula do aluno:\n");
            scanf("%d", &matricula);
            int index = buscar_aluno(alunos, quantidade, matricula);
            if (index == -1)
            {
                printf("aluno nao encontrado\n");
            }
            else
            {
                printf("=====================================");
                printf("Matricula:%d \n", alunos[index].matricula);
                printf("Nome: %s\n", alunos[index].nome);
                printf("Nota 1: %.2f \n", alunos[index].nota_1);
                printf("Nota 2: %.2f \n", alunos[index].nota_2);
                printf("Média: %.2f \n", alunos[index].media);
                printf("\n");
            }
            break;
        }
        case 6:
        {
            mostra_situacao(alunos, quantidade);
            break;
        }
        case 7:
        {
            float mediatotal = calcula_media_alunos(alunos, quantidade);
            if (mediatotal == -1)
            {
                printf("erro lista vazia");
            }
            else
            {
                printf("%.2f", mediatotal);
            }

            break;
        }
        default:
            printf("erro, opçao nao existe...");
            break;
        }
    } while (opcao != 0);
    return 0;
}