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
void ListarAluno(){
    printf("Listar ALunos\n");
}
void BuscarAluno(){
    printf("Buscar Aluno\n");
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
    ListarAluno();
    break;
case 3:
    printf("\n");
    BuscarAluno();
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