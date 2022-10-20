#ifndef MILHAGEM_H
#define MILHAGEM_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 50

typedef struct milhagem{

    char nomePrograma[MAX];
    char nome[MAX];
    char cpf[12];
    char categoria[MAX];
    double saldoMilhas;

    struct milhagem *prox;

}Pessoa;

/**
 * @brief semCadastroMilhagem, Verifica se a lista encadeada esta vazia
 * @param lista, lista de participantes que sera usada
 * @return true se a lista esta vazia, caso contrario retorna false
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
int semCadastroMilhagem(Pessoa *lista);

/**
 * @brief inserirParticipante, Insere novo participante no programa de milhagem
 * @param lista, lista de participantes
 * @return lista atualizada
 * pre-condicao: nenhuma
 * pos-condicao: lista com o novo participante inserido
 */
Pessoa* inserirParticipante(Pessoa* lista);

/**
 * @brief imprimirListaParticipantes, Imprimir lista de participantes de milhagem
 * @param lista, lista de participantes
 * pre-condicao: Nenhuma
 * pos-condicao: Imprime no console a lista de todos participantes
 */
void imprimirListaParticipantes(Pessoa* lista);

/**
 * @brief consultarParticipante, Consulta e imprimir dados de UM participante
 * @param lista, lista de participantes do programa de Milhagem
 * @return nenhum
 * pre-condicao: Nenhuma
 * pos-condicao: Dados de UM participante impresso no console
 */
void *consultarParticipante(Pessoa *lista);

/**
 * @brief removerParticipante, Remover um participante de programa de milhagem
 * @param lista, Lista no qual o participante sera removido
 * @return lista atualizada
 * pre-condicao: Nenhuma
 * pos-condicao: Participante removido da lista
 */
Pessoa *removerParticipante(Pessoa* lista);

/**
 * @brief menuMilhagem, Manipula todos operacoes dos Participantes, incluir, exibir e remover
 * pre-condicao: Nenhuma
 * pos-condicao: operacao solicitada eh realizada
 */
void menuMilhagem();

#endif // MILHAGEM_H

