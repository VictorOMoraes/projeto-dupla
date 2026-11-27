//
// Created by Usuario on 26-Nov-26.
//

#ifndef PROJETO_DUPLA_JOGOS_H
#define PROJETO_DUPLA_JOGOS_H

#define MAX 100
typedef struct Jogos {
    int id;
    char titulo[100];
    char desenvolvedora[50];
    float preco;
    float horas_jogadas;
}Jogos;

typedef Jogos *p_jogos;
extern p_jogos vetor_jogos[MAX];

void cadastrar_jogo(int i);
void imprimir_unico(int i);
void imprimir_todos();
int maior_horas_jogadas();
void relatorio();
int salvar_sair();

#endif //PROJETO_DUPLA_JOGOS_H
