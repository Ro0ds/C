#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("************************************\n");
    printf("* Bem-vindo ao jogo de Adivinhacao *\n");
    printf("************************************\n");

    //compilar e gerar o .exe
    //gcc .\adivinhacao.c -o adivinhacao.exe

    int numerosecreto = 42;
    int chute;
    int ganhou = 0;
    int tentativas = 1;

    while(!ganhou) {
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");
            tentativas--;
            continue;
        }

        printf("Tentativa %d, numero %d!", tentativas, chute);

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("\nParabens, voce acertou com %d tentativas!", tentativas);
            ganhou = 1;
        } 
        else if(maior) {
                printf("\nSeu chute foi maior do que o numero secreto\n");
            }
            else {
                printf("\nSeu chute foi menor do que o numero secreto\n");
            }
        tentativas++;
    }
    printf("\nObrigado por jogar!");
}