#include <stdio.h>
typedef struct aluno{
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
}Aluno;

void CadastrarAluno(){
    printf("ALuno Cadastrado\n");
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
    CadastrarAluno();
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