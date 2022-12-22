#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("************************************\n");
    printf("* Bem-vindo ao jogo de Adivinhacao *\n");
    printf("************************************\n");

    //compilar e gerar o .exe
    //gcc .\adivinhacao.c -o adivinhacao.exe

    int nivel;
    int totaldetentativas;
    int chute;
    int ganhou = 0;
    double pontos = 1000;
    int acertou;

    /*
    gerando número secreto randomico a partir do tempo (segundos)
    após gerar o número, pegar o resto da divisão com 100 para diminui-lo */
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil | (2) Medio | (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    for(int i = 1; i <= totaldetentativas; i++){
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        printf("Tentativa %d, numero %d!", i, chute);

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("\nParabens, voce acertou com %d tentativas!", i);
            break;
        } 
        else if(maior) {
                printf("\nSeu chute foi maior do que o numero secreto\n");
            }
            else {
                printf("\nSeu chute foi menor do que o numero secreto\n");
            }
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("\nVoce fez %.2f pontos\n", pontos);
    
    if(acertou){
        printf("Obrigado por jogar!\n");
    }
    else{
        printf("\nVoce perdeu, tente novamente\n");
        printf("O numero secreto era %d", numerosecreto);
    }
}