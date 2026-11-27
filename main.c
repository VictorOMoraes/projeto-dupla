#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"
#define ARQUIVO "C:\\Users\\Usuario\\Documents\\Fatec\\ling_prog\\projeto-dupla\\dados.txt"

p_jogos vetor_jogos[MAX];

int inicializar() {
    for (int j = 0; j < MAX; j++) {
        vetor_jogos[j] = NULL;
    }
    char linha[256];
    int i = 0;
    FILE *fp = fopen(ARQUIVO, "r");
    if (fp != NULL) {
        while (fgets(linha, 256, fp) != NULL) {
            vetor_jogos[i] = malloc(sizeof(Jogos));
            linha[strcspn(linha, "\n")] = 0;
            sscanf(linha, "%d;%100[^;];%50[^;];%f;%f",
            &vetor_jogos[i]->id, vetor_jogos[i]->titulo, vetor_jogos[i]->desenvolvedora, &vetor_jogos[i]->preco, &vetor_jogos[i]->horas_jogadas);
            i++;
        }
    } else {
        printf("Sem dados iniciais\n");
    }
    fclose(fp);
    return i;
}

int salvar_sair() {
    FILE *fp = fopen(ARQUIVO, "w");
    if (fp == NULL) {
        printf("Erro ao salvar arquivo");
        return 0;
    }
    for (int i = 0; i < MAX; i++) {
        if (vetor_jogos[i] != NULL) {
            fprintf(fp, "%d;%s;%s;%f;%f\n",
            vetor_jogos[i]->id, vetor_jogos[i]->titulo, vetor_jogos[i]->desenvolvedora, vetor_jogos[i]->preco, vetor_jogos[i]->horas_jogadas);
        } else {
            break;
        }
    }
    fclose(fp);
    return 1;
}

int main(void) {
    const int i = inicializar();

    int opcao = 0;
    do {
        int p = 0;
        printf("====== MENU ========\n");
        printf("1. Cadastrar jogo\n");
        printf("2. Imprimir unico jogo\n");
        printf("3. Imprimir todos os jogos\n");
        printf("4. Relatorio: jogo com mais horas jogadas\n");
        printf("9. Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar_jogo(i);
                fflush(stdin);
                printf("aperte enter para prosseguir\n");
                getchar();
                break;
            case 2:
                printf("Digite ID de jogo para imprimir\n");
                scanf("%d", &p);
                imprimir_unico(p);
                fflush(stdin);
                printf("aperte enter para prosseguir\n");
                getchar();
                break;
            case 3:
                imprimir_todos();
                fflush(stdin);
                printf("aperte enter para prosseguir\n");
                getchar();
                break;
            case 4:
                relatorio();
                fflush(stdin);
                printf("aperte enter para prosseguir\n");
                getchar();
                break;
            case 9:
                if (salvar_sair() == 0) {
                    printf("Erro ao salvar arquivo\n");
                } else {
                    printf("Arquivo salvo com sucesso\n");
                }
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 9);
    return 0;
}

