#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "milhagem.h"
#define MAX 50

/**
 * @brief semCadastroMilhagem, Verifica se a lista encadeada esta vazia
 * @param lista, lista de participantes que sera usada
 * @return true se a lista esta vazia, caso contrario retorna false
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
int semCadastroMilhagem(Pessoa *lista){

    return(lista == NULL);
}

/**
 * @brief inserirParticipante, Insere novo participante no programa de milhagem
 * @param lista, lista de participantes
 * @return lista atualizada
 * pre-condicao: nenhuma
 * pos-condicao: lista com o novo participante inserido
 */
Pessoa* inserirParticipante(Pessoa* lista){

    char nomePrograma[MAX];
    char nome[MAX];
    char cpf[12];
    char categoria[MAX];
    double saldoMilhas;

    caixaDialogoInserindoParticipante();
    printf("\n           Digite o nome do programa: ");
    gets(nomePrograma);

    printf("           Digite o nome da pessoa: ");
    gets(nome);

    printf("           Digite o cpf: ");
    gets(cpf);
    setbuf(stdin,NULL);

    printf("           Digite a categoria: ");
    gets(categoria);

    printf("           Saldo de milhas: ");
    scanf("%lf", &saldoMilhas);

    Pessoa* nova = (Pessoa*)malloc(sizeof(Pessoa));

    // se nao ha participantes na lista, criar nova
    if(semCadastroMilhagem(lista)){

        strcpy(nova->nomePrograma,nomePrograma);
        strcpy(nova->nome, nome);
        strcpy(nova->cpf,cpf);
        strcpy(nova->categoria, categoria);
        nova->saldoMilhas = saldoMilhas;
        nova->prox=NULL;

        return nova;

    //senao, inserir na lista existente
    }else{
        Pessoa* aux = lista;

        while(aux->prox!=NULL){
            aux=aux->prox;
        }

        strcpy(nova->nomePrograma,nomePrograma);
        strcpy(nova->nome, nome);
        strcpy(nova->cpf, cpf);
        strcpy(nova->categoria, categoria);
        nova->saldoMilhas = saldoMilhas;
        nova->prox=NULL;
        aux->prox=nova;

        return lista;
    }
}


/**
 * @brief imprimirListaParticipantes, Imprimir lista de participantes de milhagem
 * @param lista, lista de participantes
 * pre-condicao: nenhuma
 * pos-condicao: imprime no console a lista de todos participantes
 */
void imprimirListaParticipantes(Pessoa* lista){

    //confere se ha particiantes no programa de milhagem
    if(semCadastroMilhagem(lista)){

        // se nao ha, avisa e retorna o menu de operacoes
        naoHaParticipantes();
        menuMilhagem();

    // se ha, retorna a lista de participantes
    }else{
        caixaDialogoListaParticipantes();
        while(lista!=NULL){

            printf("\n                  Nome do Programa: %s\n", lista->nomePrograma);
            printf("                  Nome do cliente: %s\n",lista->nome);
            printf("                  CPF do Cliente: %s\n", lista->cpf);
            printf("                  Categoria: %s\n", lista->categoria);
            printf("                  Saldo de Milhas: %.2lf\n", lista->saldoMilhas);
            printf("\n");

            lista=lista->prox;
        }
    }
}

/**
 * @brief consultarParticipante, Consulta e imprimir dados de UM participante
 * @param lista, lista de participantes do programa de Milhagem
 * @return nenhum
 * pre-condicao: Nenhuma
 * pos-condicao: Dados de UM participante impresso no console
 */
void *consultarParticipante(Pessoa *lista){

    Pessoa* atual = lista;
    char nroCPF[MAX];

    system("cls");
    caixaDialogoConsultarUmParticipante();
    printf("        Digite o CPF do Participante que deseja consultar:\n"
           "                        > ");
    gets(nroCPF);
    printf("\n");

    // percorre a lista ate encontrar o cpf do participante
    while( atual != NULL && strcmp(nroCPF, atual->cpf)!= 0){

        atual=atual->prox;
    }

    // se a lista chegou ao fim e nao encontrou o Participante
    if(atual == NULL){
        printf("\n\n                    Pessoa NAO encontrada                  \n\n");

    // se encontrou
    }else{

        dadosParticipante();
        printf("                  Nome do Programa: %s\n", atual->nomePrograma);
        printf("                  Nome do cliente: %s\n",atual->nome);
        printf("                  CPF do Cliente: %s\n", atual->cpf);
        printf("                  Categoria: %s\n", atual->categoria);
        printf("                  Saldo de Milhas: %.2lf\n", atual->saldoMilhas);
        printf("\n");
    }
}

/**
 * @brief removerParticipante, Remover um participante de programa de milhagem
 * @param lista, Lista no qual o participante sera removido
 * @return lista atualizada
 * pre-condicao:
 * pos-condicao: Participante removido da lista
 */
Pessoa *removerParticipante(Pessoa* lista){

    Pessoa* anterior = lista;
    Pessoa* atual = lista;
    char numeroCPF[MAX];

    caixaDialogoExcluirParticipante();
    printf("        Digite o CPF do Participante que deseja remover:\n"
           "                        >");
    gets(numeroCPF);

    // percorre a lista ate encontrar o cpf do participante
    while( atual != NULL && strcmp(numeroCPF, atual->cpf)!= 0){

        anterior = atual;

        atual = atual->prox;
    }

    // verifica se a lista nao chegou ao fim  e remove
    if(atual != NULL){

        if(atual==lista)
            lista=lista->prox;
        else
            anterior->prox = atual->prox;

        printf("\n\n               Participante removido com sucesso! \n\n");
        free(atual);
    }
    else printf("\n\n                 Participante NAO encontrado\n\n");

    return lista;
}

/**
 * @brief menuMilhagem, Manipula todos operacoes dos Participantes, incluir, exibir e remover
 * pre-condicao: Nenhuma
 * pos-condicao: operacao solicitada eh realizada
 */
void menuMilhagem(){

    Pessoa* participante = (Pessoa*)malloc(sizeof (Pessoa));
    participante = NULL;

    int opcaoMilhagem;

    caixaDialogoMenuMilhagem();
    scanf("%d", &opcaoMilhagem);
    setbuf(stdin,NULL);

    while (opcaoMilhagem!=0) {
        switch (opcaoMilhagem) {

        // inserer Novo participante no programa de milhagem
        case 1:
            system("cls");
            participante = inserirParticipante(participante);
            operacaoRealizadaSucesso();
            getchar();
            system("cls");
            break;

        // imprime lista de todos participantes
        case 2:
            system("cls");
            imprimirListaParticipantes(participante);
            getchar();
            system("cls");
            break;

        // consulta UM participante
        case 3:
            consultarParticipante(participante);
            getchar();
            system("cls");
            break;

        // remove um participante do programa de milhagem
        case 4:
            participante = removerParticipante(participante);
            getchar();
            system("cls");
            break;

        // confirma se o usuario quer sair
        case 5:
            menuSair();
            break;

        default:
            operacaoInvalida();
            system("pause");
        }
        caixaDialogoMenuMilhagem();
        scanf("%d", &opcaoMilhagem);
        setbuf(stdin,NULL);
    }
}

