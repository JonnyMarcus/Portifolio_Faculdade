#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct aluno{
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
}Aluno;



void CadastrarAluno(Aluno alunos[],int *quantidade){
    if(*quantidade>=MAX_ALUNOS){
        printf("Limite de Alunos atingidos!\n");
        return;
    }
    Aluno novo_Aluno;

    printf("\n=== Cadastro de Aluno ===\n");

    printf("Matricula: ");
    scanf("%d",&novo_Aluno.matricula);

    printf("\n");
    getchar();

    printf("Nome: ");
    fgets(novo_Aluno.nome,100,stdin);
    novo_Aluno.nome[strcspn(novo_Aluno.nome, "\n")] = '\0';

    printf("Nota 1: ");
    scanf("%f",&novo_Aluno.nota_1);
    printf("\n");

    printf("Nota 2:" );
    scanf("%f",&novo_Aluno.nota_2);
    printf("\n");

    novo_Aluno.media =((novo_Aluno.nota_1 + novo_Aluno.nota_2)/2);

    
    alunos[*quantidade] = novo_Aluno;
    (*quantidade)++;

}
void ListarAluno(Aluno alunos[],int quantidade){
    if(quantidade==0){
        printf("Nenhum aluno Cadastrado\n");
        return;
    }
    printf("\n=== LISTA DE ALUNOS ===\n");
    for(int i=0;i>quantidade;i++){
        printf("\nAluno %d\n", i + 1);
        printf("Nome : %s \n",alunos[i].nome);
        printf("Matricula : %d \n",alunos[i].matricula);
        printf("nota 1 : %.2f \n",alunos[i].nota_1);
        printf("nota 2 : %.2f \n",alunos[i].nota_2);
        printf("Media : %.2f \n",alunos[i].media);
    }
    
}
void BuscarAluno(Aluno alunos[],int quantidade){
    int BuscarMatricula;
    int encontrado = 0;

    if(quantidade ==0){
        printf("Nenhum Aluno Cadastrado\n");
        return;
    }
    printf("Digite a matricula do Aluno : ");
    scanf("%d",&BuscarMatricula);

   for(int i = 0; i < quantidade; i++){
        if(alunos[i].matricula == BuscarMatricula){
            printf("\n=== ALUNO ENCONTRADO ===\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Nota 1: %.2f\n", alunos[i].nota_1);
            printf("Nota 2: %.2f\n", alunos[i].nota_2);
            printf("Media: %.2f\n", alunos[i].media);

            encontrado = 1;
            break;
        }
    }
        if(encontrado == 0){
            printf("Aluno nao encontrado!\n");
        }
}

void CalculandoMediaTurma(){
    printf("Calculando media da Turma\n");
}

int main(){
    Aluno alunos[MAX_ALUNOS];
    int quantidade = 0;
    int opcao;

do{
    printf("\n===== SISTEMA DE CADASTRO DE ALUNOS =====\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Calcular media da turma\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
switch (opcao)
{
case 1:
    printf("\n");
    CadastrarAluno(alunos, &quantidade);
    break;
case 2:
    printf("\n");
    ListarAluno(alunos, quantidade);
    break;
case 3:
    printf("\n");
    BuscarAluno(alunos, quantidade);
    break;
case 4:
    printf("\n");
    CalculandoMediaTurma();
    break;
case 0:
    printf("\n");
    printf("Saindo......\n");
    break;

default:
    printf("\n");
    printf("Opcao invalida! \n");
    break;
}


}while(opcao!=0);



    return 0;
}