#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"voo.h"
#include"milhagem.h"
#include"interface.h"

/**
 * @brief caixaDialogoMenuInicial, Caixa de Dialogo do Menu Inicial
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoMenuInicial(){

    system("cls");
    printf("\n       -------------------------------------------------\n"
           "                            BEM VINDO                    \n"
           "       -------------------------------------------------\n\n"
           "                           MENU INICIAL\n"
           "                      [1] Cadastrar Voos\n"
           "                      [2] Programas de Milhagem\n"
           "                      [3] Sair\n"
           "                             >");
}

/**
 * @brief menuInicial, Verifica se usuario quer cadastrar Voos ou Participantes
 * pre-condicao: Nenhuma
 * pos-condicao: Operacao a ser realizada escolhida
 */
void menuInicial(){

    int opMenu;
    caixaDialogoMenuInicial();
    scanf("%d", &opMenu);

    if(opMenu == 1){
        menuVoos();
    }else if(opMenu == 2){
        menuMilhagem();
    }else if(opMenu == 3){
        menuSair();
    }
}

/**
 * @brief caixaDialogoMenuVoos, Caixa de Dialogo para Operacoes
 * dos Cadastros de Voos
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoMenuVoos(){

    printf("\n       -------------------------------------------------\n"
           "                       CADASTROS VOOS                   \n"
           "       -------------------------------------------------\n"
           "                      [1] Inserir Voo\n"
           "                      [2] Exibir Voos\n"
           "                      [3] Exibir um Voo\n"
           "                      [4] Excluir um Voo\n"
           "                      [5] Sair\n\n"
           "                    Digite a opcao desejada:\n"
           "                            >  ");
}

/**
 * @brief caixaDialogoMenuMilhagem, Caixa de Dialogo para Operacoes
 * dos Cadastros de Participantes
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoMenuMilhagem(){

    printf("\n       -------------------------------------------------\n"
           "              PARTICIPANTES DE PROGRAMAS DE MILHAGEM    \n"
           "       -------------------------------------------------\n"
           "                      [1] Inserir um Participante\n"
           "                      [2] Exibir Participantes\n"
           "                      [3] Exibir um Participante\n"
           "                      [4] Excluir um Participante\n"
           "                      [5] Sair\n\n"
           "                    Digite a opcao desejada:\n"
           "                            >  ");
}

/**
 * @brief menuSair, Verifica se o usuario quer sair ou voltar para Menu Inicial
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void menuSair(){

    printf("\n       -------------------------------------------------\n"
           "                           SAIR                  \n"
           "       -------------------------------------------------\n\n"
           "                   Deseja realmente sair?\n"
           "                  [1] Sim\n"
           "                  [2] Nao, voltar ao Menu Inicial\n"
           "                           >  ");
    int op;
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        getchar();
        exit(0);
    }else if(op == 2){
        menuInicial();
    }
}

/**
 * @brief operacaoRealizadaSucesso, Operacao foi realizada com Sucesso
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void operacaoRealizadaSucesso(){

    system("cls");
    printf("\n       -------------------------------------------------\n"
           "                  OPERACAO REALIZADA COM SUCESSO    \n"
           "       -------------------------------------------------\n");
    system("cls");
}

/**
 * @brief operacaoInvalida, Operacao nao eh valida
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void operacaoInvalida(){

    printf("\n       -------------------------------------------------\n"
           "                       OPERACAO INVALIDA   \n"
           "       -------------------------------------------------\n");
}


/**
 * @brief InserindoParticipante
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoInserindoParticipante(){

    printf("\n      --------------------------------------------------\n"
           "      INSERINDO NOVO PARTICIPANTE NO PROGRAMA DE MILHAGEM   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoInserirNovoVoo
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoInserirNovoVoo(){

    printf("\n      ---------------------------------------------------\n"
           "                    INSERINDO NOVO VOO   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoExcluirParticipante
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoExcluirParticipante(){

    printf("\n      ---------------------------------------------------\n"
           "        EXCLUINDO PARTICIPANTE DO PROGRAMA DE MILHAGEM   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoExcluirVoo
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoExcluirVoo(){

    printf("\n      ---------------------------------------------------\n"
           "                        EXCLUINDO UM VOO   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoListaParticipantes
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoListaParticipantes(){

    printf("\n      ---------------------------------------------------\n"
           "        LISTA DE PARTICIPANTES DO PROGRAMA DE MILHAGEM   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoListaVoos
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoListaVoos(){

    printf("      ---------------------------------------------------\n"
           "                    LISTA DE TODOS OS VOOS   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoConsultarUmParticipante
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoConsultarUmParticipante(){

    printf("\n      ---------------------------------------------------\n"
           "                  CONSULTANDO UM PARTICIPANTE   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief caixaDialogoConsultarUmVoo
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void caixaDialogoConsultarUmVoo(){

    printf("\n      ---------------------------------------------------\n"
           "                     CONSULTANDO UM VOO   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief dadosParticipante
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void dadosParticipante(){

    printf("\n      ---------------------------------------------------\n"
           "                     DADOS DO PARTICIPANTE   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief dadosVoo
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void dadosVoo(){

    printf("\n      ---------------------------------------------------\n"
           "                        DADOS DO VOO   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief naoHaParticipantes
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void naoHaParticipantes(){
    printf("\n      ---------------------------------------------------\n"
           "          NAO HA PARTICIPANTES DE PROGRAMA DE MILHAGEM   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief naoHaVoos
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void naoHaVoos(){
    printf("\n      ---------------------------------------------------\n"
           "                       NAO HA VOOS CADASTRADOS   \n"
           "      ---------------------------------------------------\n");
}

/**
 * @brief msgAlerta
 * pre-condicao: Nenhuma
 * pos-condicao: Nenhuma
 */
void msgAlerta(){
    printf("\n                           ALERTA   \n\n");
}
