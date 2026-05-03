#include <stdio.h>

void menu() {
    printf("\n=== SIMULADOR DE ARQUITETURA ===\n");
    printf("1. Conversao de numeros\n");
    printf("2. operaçoes binarias\n");
    printf("3. Simulador de memoria\n");
    printf("4. Calculo de bits/bytes\n");
    printf("0. Sair\n");
}
void menu_conversao(){

    printf("\n=== CONVERSAO DE NUMEROS ===\n");
    printf("1. Binario -> Decimal\n");
    printf("2. Decimal -> Binario\n");
    printf("3. Binario -> Hexadecimal\n");
    printf("4. Hexadecimal -> Binario\n");
    printf("5. Binario -> Octal\n");
    printf("6. Octal -> Binario\n");
    printf("0. Voltar\n");
}
void menu_operacoes(){
    printf("\n=== OPERACOES BINARIAS ===\n");
    printf("1. Soma Binaria \n");
    printf("2. Subtracao Binaria\n");
    printf("3. Multiplicação Binaria\n");
    printf("4. Divisao Binaria\n");
    printf("0. Sair\n");
}

int main(){
    int op, aux;

     do {
        menu();
        scanf("%d",&op);

        switch(op){
 case 1:
                do {
                    menu_conversao();
                    scanf("%d", &aux);

                    switch(aux) {
                        case 1: printf("Binario -> Decimal\n"); break;
                        case 2: printf("Decimal -> Binario\n"); break;
                        case 3: printf("Binario -> Hex\n"); break;
                        case 4: printf("Hex -> Binario\n"); break;
                        case 5: printf("Binario -> Octal\n"); break;
                        case 6: printf("Octal -> Binario\n"); break;
                    }

                } while(aux != 0);
                break;
            case 2:
                do {
                    menu_operacoes();
                    scanf("%d", &aux);

                    switch(aux) {
                        case 1: printf("Soma Binaria\n"); break;
                        case 2: printf("Subtracao Binaria\n"); break;
                        case 3: printf("Multiplicacao Binaria\n"); break;
                        case 4: printf("Divisao Binaria\n"); break;
                    }

                } while(aux != 0);
                break;

            case 3:
                printf("\n=== SIMULADOR DE MEMORIA ===\n");
                break;

            case 4:
                printf("\n=== CALCULO DE BITS/BYTES ===\n");
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(op != 0);

    return 0;
}