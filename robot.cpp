#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ESTACAO 51
#define ROBO 10
#define SUJEIRA 20
#define PAREDE 30
#define VAZIO 40
#define CAMINHO 80

int map[8][8];
int linhaS;
int colunaS;

struct robot {
    int x;
    int y;
    int linhaR;
    int colunaR;
    int contPassos;
};

void limpar() {
    system("clear");
}

void mapa() {
    limpar();
    printf("\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <= 8; j++) {
            if (j == 8) {
                printf("|");
            } else if (map[i][j] == ESTACAO) {
                printf("| E ");
            } else if (map[i][j] == ROBO) {
                printf("| @ ");
            } else if (map[i][j] == CAMINHO || map[i][j] == VAZIO) {
                printf("|   ");
            } else if (map[i][j] == SUJEIRA) {
                printf("|***");
            } else if (linhaS == -1 && colunaS == -1 && map[i][j] != ROBO && map[i][j] != SUJEIRA && map[i][j] != ESTACAO && map[i][j] != VAZIO) {
                map[i][j] = PAREDE;
                printf("|---");
            } else {
                printf("|   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void jogo() {
    struct robot r;
    int contSujeira = 0;
    r.contPassos = 0;
    int contador = 0;
    int a;
    int vetor[64][2];

    mapa();

    printf("Digite a linha do robô: ");
    scanf("%d", &r.linhaR);
    printf("Digite a coluna do robô: ");
    scanf("%d", &r.colunaR);

    map[r.linhaR][r.colunaR] = ROBO;

    do {
        mapa();
        printf("Quantidade de sujeiras: %d \n", contSujeira);
        printf("Digite a linha da sujeira: ");
        scanf("%d", &linhaS);
        printf("Digite a coluna da sujeira: ");
        scanf("%d", &colunaS);

        for (a = 0; a < 8; a++) {
            map[linhaS][colunaS] = SUJEIRA;
            vetor[a][a] = SUJEIRA;
            mapa();
        }

        contador++;
        contSujeira++;
    } while (linhaS != -1 && colunaS != -1);

    do {
        mapa();
        printf("Quantidade de sujeiras: %d \n", contSujeira - 1);
        printf("Quantidade de Passos: %d \n", r.contPassos);
        printf("O robô dará: %d passos, até limpar completamente o cômodo. \n", contador * 2 - 2);

        while (contSujeira != 0) {
            if (map[r.linhaR][r.colunaR + 1] == SUJEIRA && map[r.linhaR][r.colunaR + 1] != PAREDE) {
                map[r.linhaR][r.colunaR] = VAZIO;
                map[r.linhaR][r.colunaR + 1] = ROBO;
                r.colunaR++;
                contSujeira--;
                r.contPassos++;
                break;
            } else if (map[r.linhaR][r.colunaR - 1] == SUJEIRA && map[r.linhaR][r.colunaR - 1] != PAREDE) {
                map[r.linhaR][r.colunaR] = VAZIO;
                map[r.linhaR][r.colunaR - 1] = ROBO;
                r.colunaR--;
                contSujeira--;
                r.contPassos++;
                break;
            } else if (map[r.linhaR + 1][r.colunaR] == SUJEIRA && map[r.linhaR + 1][r.colunaR] != PAREDE) {
                map[r.linhaR][r.colunaR] = VAZIO;
                map[r.linhaR + 1][r.colunaR] = ROBO;
                r.linhaR++;
                r.contPassos++;
                contSujeira--;
                break;
            } else if (map[r.linhaR - 1][r.colunaR] == SUJEIRA && map[r.linhaR - 1][r.colunaR] != PAREDE) {
                map[r.linhaR][r.colunaR] = VAZIO;
                map[r.linhaR - 1][r.colunaR] = ROBO;
                r.linhaR--;
                r.contPassos++;
                contSujeira--;
                break;
            } else if (map[r.linhaR][r.colunaR - 1] == VAZIO && map[r.linhaR][r.colunaR - 1] != PAREDE) {
                map[r.linhaR][r.colunaR] = CAMINHO;
                map[r.linhaR][r.colunaR - 1] = ROBO;
                r.colunaR--;
                r.contPassos++;
                break;
            } else if (map[r.linhaR][r.colunaR + 1] == VAZIO && map[r.linhaR][r.colunaR + 1] != PAREDE) {
                map[r.linhaR][r.colunaR] = CAMINHO;
                map[r.linhaR][r.colunaR + 1] = ROBO;
                r.colunaR++;
                r.contPassos++;
                break;
            } else if (map[r.linhaR - 1][r.colunaR] == VAZIO && map[r.linhaR - 1][r.colunaR] != PAREDE) {
                map[r.linhaR][r.colunaR] = CAMINHO;
                map[r.linhaR - 1][r.colunaR] = ROBO;
                r.linhaR--;
                r.contPassos++;
                break;
            } else if (map[r.linhaR + 1][r.colunaR] == VAZIO && map[r.linhaR + 1][r.colunaR] != PAREDE) {
                map[r.linhaR][r.colunaR] = CAMINHO;
                map[r.linhaR + 1][r.colunaR] = ROBO;
                r.linhaR++;
                r.contPassos++;
                break;
            } else {
                mapa();
                sleep(1);
                printf("\n - Limpeza concluída! - \n");
                printf("\n \\o/ \n\n\n");
                sleep(2);
                return;
            }
        }

        sleep(1);
    } while (contSujeira >= 1 && r.contPassos <= (2 * contador - 2));
    
    system("exit");
}

int main(void) {
    jogo();
    return 0;
}
