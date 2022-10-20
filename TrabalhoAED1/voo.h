#ifndef VOO_H
#define VOO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct voo{

    char prefixo[MAX];
    char aeroportoOrigem[MAX];
    char aeroportoDestino[MAX];
    char aeronave[MAX];
    int horachegada, minutochegada;
    int horaduracao;
    int minutoduracao;
    int horapartida, minutopartida;

    struct voo *prox;

} Voo;

/**
 * @brief semCadastros, Verifica se a lista encadeada esta vazia
 * @param lista, lista que sera verificada
 * @return true se a lista esta vazia, caso contrario retorna false
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
int semCadastros(Voo *lista);

/**
 * @brief insereVoo, insere novo Voo no cadastro de Voos
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * @return lista atualizada
 * pre-condicao: Verifica se a lista esta vazia e insere as informacoes na
 * cabeca ou insere logo em seguida se a lista ja contem informacoes
 * pos-condicao: lista com o novo Voo inserido
 */
Voo* insereVoo(Voo* lista);

/**
 * @brief imprimeListaDeVoos, Exibe todos os cadastros de Voos
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * pre-condicao: nenhuma
 * pos-condicao: Os cadastros de Voo sao exibidos no console
 */
void imprimeListaDeVoos(Voo* lista);

/**
 * @brief consultarVoo, Consultar determinado voo
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * pre-condicao: nenhuma
 * pos-condicao: Determinado cadastro de voo exibido no console
 */
void consultarVoo(Voo* lista);

/**
 * @brief removerVoo, Remove um determinado Voo atraves da sigla do Voo
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * @return lista atualizada
 * pre-condicao: Nenhuma
 * pos-condicao: Lista com o voo removido
 */
Voo *removerVoo (Voo* lista);

/**
 * @brief menuVoos, Manipula todas funcoes do Voo, como inserir, exibir e remover
 * pre-condicao: Nenhuma
 * pos-condicao: operacao solicitada eh realizada
 */
void menuVoos();

#endif // VOO_H
