#include <stdio.h>
#include <string.h>

#include "conversao.h"

void binario_decimal(){
    int decimal =0;
    char bin[50];
    
    printf("escreva o numero binario: ");
    scanf("%s",&bin);

    for(int i =0 ;bin[i] != "\0";i++){
        int bit = bin[i] - '0';
        decimal = decimal * 2 + bit;
    }
    printf("\nDecimal: %d\n", decimal);

}

void decimal_binario(){
    char bin[50];
    int dec;
    int i =0;

    printf("escreva o decimal:  ");
    scanf("%d",&dec);

    if (dec ==0){
        printf("0\n");
        return; 
    }

    printf("\nBinario: ");

    for(int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }

    printf("\n");
}
void binario_hexadecimal(){
    char bin[50];
    char temp[50];

    printf("digite o numero binario: ");
    scanf("%s",bin);

    int len = strlen(bin);
    int resto = len %4;
    if(resto !=0){
        int faltam = 4 - resto;
        for(int i = 0; i < faltam; i++) {
            strcat(temp, "0");
        }
        strcat(temp, bin);
        strcpy(bin, temp);
    }

    printf("Hexadecimal: ");
    for(int i = 0; bin[i] != '\0'; i += 4) {
        int valor = 0;

        for(int j = 0; j < 4; j++) {
            valor = valor * 2 + (bin[i + j] - '0');
        }

        
        if(valor < 10) {
            printf("%d", valor);
        } else {
            printf("%c", valor - 10 + 'A');
        }
    }

    printf("\n");
}













   
