//
// Created by Usuario on 26-Nov-26.
//

#include "jogos.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrar_jogo(int i) {
    if (vetor_jogos[i] == NULL) {
        vetor_jogos[i] = malloc(sizeof(Jogos));
        vetor_jogos[i]->id = i;
        fflush(stdin);
        printf("Digite título: \n");
        gets(vetor_jogos[i]->titulo);
        fflush(stdin);
        printf("Digite nome da desenvolvedora: \n");
        gets(vetor_jogos[i]->desenvolvedora);
        fflush(stdin);
        printf("Digite o preco do jogo: \n");
        scanf("%f", &vetor_jogos[i]->preco);
        fflush(stdin);
        printf("Digite a quantidade de horas jogadas\n");
        scanf("%f", &vetor_jogos[i]->horas_jogadas);
    }
}

void imprimir_unico(int i) {
    if (vetor_jogos[i] != NULL) {
        printf("Titulo: %s\n", vetor_jogos[i]->titulo);
        printf("Desenvolvedora: %s\n", vetor_jogos[i]->desenvolvedora);
        printf("Preco: R$%.2f\n", vetor_jogos[i]->preco);
        printf("Horas jogadas: %.2f\n", vetor_jogos[i]->horas_jogadas);
        printf("\n");
    } else {
        printf("Jogo não encontrado\n\n");
    }
}

void imprimir_todos() {
    for (int i = 0; i < MAX; i++) {
        if (vetor_jogos[i] != NULL) {
            imprimir_unico(i);
        } else {
            return;
        }
    }
}

int maior_horas_jogadas() {
    int index = 0;
    float n_horas = vetor_jogos[0]->horas_jogadas;
    for (int i = 1; i < MAX; i++) {
        if (vetor_jogos[i] != NULL) {
            if (vetor_jogos[i]->horas_jogadas > n_horas) {
                n_horas = vetor_jogos[i]->horas_jogadas;
                index = i;
            }
        } else {
            break;
        }
    }
    return index;
}

void relatorio() {
    int jogo_horas = maior_horas_jogadas();
    printf("Jogos com mais horas jogadas: %s\n", vetor_jogos[jogo_horas]->titulo);
    printf("Com %f horas jogadas\n\n", vetor_jogos[jogo_horas]->horas_jogadas);
}