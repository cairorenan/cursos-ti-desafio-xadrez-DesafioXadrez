#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int xadrez[8][8];
void Dire(int op); // linha 32
void Bispo(int numero, int segundo_numero, char letra, char segunda_letra); // linha 77
void Torre(int numero, int segundo_numero, char letra, char segunda_letra); //linha 108
void Rainha(int numero, int segundo_numero, char letra, char segunda_letra); //linha 138
void Cavalo(int numero, int segundo_numero, char letra, char segunda_letra); //linha 181
int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //isso é pro terminal ler caracteres brasileiros tipo ç (só funciona em win)
    int op; //operação do switch
    do{
        printf("\n---Menu---");
        printf("\n1 - Bispo");
        printf("\n2 - Torre");
        printf("\n3 - Rainha");
        printf("\n4 - Cavalo");
        printf("\n0 - Sair\n");
        scanf("%d",&op);
        switch (op){
            case 1:
            case 2:
            case 3:
            case 4:
                Dire(op);
            break;
            case 0:
                return 0;
            break;
            default:
                printf("Invalido!\n");
            break;
        }
    }while(op!=0);
}
void Dire(int op){
    char entrada[3];
    char segunda_entrada[3];
    char letra, segunda_letra;
    int numero, segundo_numero;
    do{
        printf("informe primeiro a posição atual da peça Ex:E4: ");
        scanf("%2s", entrada); //%2s para ler apenas dois
        letra = entrada[0];
        numero = entrada [1] - '0'; //conversão por tabela ASCII, o número em char menos o valor ascii de '0' retornara o valor int da entrada
        if (numero > 8 || !strchr("ABCDEFGH", letra)){ //strchr procura se na string "ABCDEFGH" existe algum valor igual a variavel letra, ! é a inversão disso
            printf("Invalido!\n");
        }
    }while (numero > 8 || !strchr("ABCDEFGH", letra));    
    do{
        printf("informe agora a posição para onde a peça deve se mover: ");
        scanf("%2s", segunda_entrada);
        segunda_letra = segunda_entrada[0];
        segundo_numero = segunda_entrada[1] - '0';
        if (segundo_numero > 8 || !strchr("ABCDEFGH", segunda_letra)){
            printf("invalido!");
        }
    }while (segundo_numero > 8 || !strchr("ABCDEFGH", segunda_letra));
    switch (op) {
        case 1:
            Bispo(numero,segundo_numero,letra,segunda_letra);
            break;
        case 2:
            Torre(numero,segundo_numero,letra,segunda_letra);
            break;
        case 3:
            Rainha(numero,segundo_numero,letra,segunda_letra);
            break;
        case 4:
            Cavalo(numero,segundo_numero,letra,segunda_letra);
            break;
    }
}

char conversao_rapida(int numero){
    char letra = 'A' + (numero - 1);
    return letra;
}

void Bispo(int numero, int segundo_numero, char letra, char segunda_letra){
    int numero_dletra = letra - 'A' + 1;
    int numero_dletra2 = segunda_letra - 'A' + 1;
    while(numero != segundo_numero || numero_dletra != numero_dletra2){
        if (numero<segundo_numero && numero_dletra<numero_dletra2){
            numero++;
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero<segundo_numero && numero_dletra>numero_dletra2){
            numero++;
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra<numero_dletra2){
            numero--;
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra>numero_dletra2){
            numero --;
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }
    }
    printf("\n o bispo chegou ao destino \n");
}

void Torre(int numero, int segundo_numero, char letra, char segunda_letra){
    int numero_dletra = letra - 'A' + 1;
    int numero_dletra2 = segunda_letra - 'A' + 1;
    while(numero != segundo_numero || numero_dletra != numero_dletra2){
        if (numero==segundo_numero && numero_dletra<numero_dletra2){
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero==segundo_numero && numero_dletra>numero_dletra2){
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero<segundo_numero && numero_dletra==numero_dletra2){
            numero++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra==numero_dletra2){
            numero--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }
    }
    printf("\n a torre chega ao destino \n");
}

void Rainha(int numero, int segundo_numero, char letra, char segunda_letra){
    int numero_dletra = letra - 'A' + 1;
    int numero_dletra2 = segunda_letra - 'A' + 1;
    while(numero != segundo_numero || numero_dletra != numero_dletra2){
        if (numero<segundo_numero && numero_dletra<numero_dletra2){
            numero++;
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero<segundo_numero && numero_dletra>numero_dletra2){
            numero++;
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra<numero_dletra2){
            numero--;
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra>numero_dletra2){
            numero --;
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero==segundo_numero && numero_dletra<numero_dletra2){
            numero_dletra++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero==segundo_numero && numero_dletra>numero_dletra2){
            numero_dletra--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero<segundo_numero && numero_dletra==numero_dletra2){
            numero++;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }else if (numero>segundo_numero && numero_dletra==numero_dletra2){
            numero--;
            char caractere = conversao_rapida(numero_dletra);
            printf("\n a peça passa por %c%d", caractere, numero);
        }
    }
    printf("\n a rainha chegou ao destino \n");
}

void Cavalo(int numero, int segundo_numero, char letra, char segunda_letra){
    int numero_dletra = letra - 'A' + 1;
    int numero_dletra2 = segunda_letra - 'A' + 1;
    char caractere;
    int tempN;
    int tempL;
    if (numero<segundo_numero){
        if ((++numero)==segundo_numero){
            numero--;
            if (((tempN=numero), ++tempN == segundo_numero)&&((tempL = numero_dletra)+2==numero_dletra2)){
                numero++;
                numero_dletra+=2;
            }else if (((tempN=numero), ++tempN == segundo_numero)&&((tempL = numero_dletra)-2==numero_dletra2)){
                numero++;
                numero_dletra-=2;
            }
        }else{
            numero--; //por mais que a condição da linha 188 nao seja verdadeira a variavel numero ainda é incrementada
            if (((tempN=numero), (tempN+=2) == segundo_numero)&&((tempL = numero_dletra)-1==numero_dletra2)){
                numero+=2;
                numero_dletra--;
            }else if(((tempN=numero), (tempN+=2) == segundo_numero)&&((tempL = numero_dletra)+1==numero_dletra2)){
                numero+=2;
                numero_dletra++;
            }
        }
    }else{
        if ((--numero)==segundo_numero){
            numero++;
            if (((tempN=numero), --tempN == segundo_numero)&&((tempL = numero_dletra)+2==numero_dletra2)){
                numero--;
                numero_dletra+=2;
            }else if (((tempN=numero), --tempN == segundo_numero)&&((tempL = numero_dletra)-2==numero_dletra2)){
                numero--;
                numero_dletra-=2;
            }
        }else{
            numero++;
            if (((tempN=numero), (tempN-=2) == segundo_numero)&&((tempL = numero_dletra)+1==numero_dletra2)){
                numero-=2;
                numero_dletra++;
            }else if (((tempN=numero), (tempN-=2) == segundo_numero)&&((tempL = numero_dletra)-1==numero_dletra2)){
                numero-=2;
                numero_dletra--;
            }
        }
    }
    caractere = conversao_rapida(numero_dletra);
    printf("o cavalo chegou em %c%d", caractere, numero);
}