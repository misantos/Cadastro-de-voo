#include <stdio.h>
#include <stdlib.h>
#include <interface.h>
#include <voo.h>


/**
 * @brief semCadastros, Verifica se a lista encadeada esta vazia
 * @param lista, lista que sera verificada
 * @return true se a lista esta vazia, caso contrario retorna false
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
int semCadastros(Voo *lista){

    return(lista == NULL);
}

/**
 * @brief insereVoo, insere novo Voo no cadastro de Voos
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * @return lista atualizada
 * pre-condicao: nenhuma
 * pos-condicao: lista com o novo Voo inserido
 */
Voo* insereVoo(Voo* lista){

    char prefixo[MAX];
    char aeroportoOrigem[MAX];
    char aeroportoDestino[MAX];
    char aeronave[MAX];
    int horachegada, minutochegada, horaduracao, minutoduracao;
    int horapartida, minutopartida;

    caixaDialogoInserirNovoVoo();
    printf("\n           Digite o prefixo do voo: ");
    fgets(prefixo, MAX+1, stdin);
    strtok("\n",prefixo);


    printf("           Digite o Aerorporto de origem: ");
    fgets(aeroportoOrigem, MAX+1, stdin);
    strtok("\n", aeroportoOrigem);

    printf("           Aeroporto de Destino: ");
    fgets(aeroportoDestino, MAX + 1, stdin);
    strtok("\n",aeroportoDestino);

    // verifica se aeroporto de origem e destino sao iguais
    while(strcmp(aeroportoOrigem, aeroportoDestino) == 0){
        msgAlerta();
        printf("           O aeroporto de destino NAO pode ser o mesmo de origem.\n");
        printf("           Digite novamentente o Aeroporto de Destino: ");
        fgets(aeroportoDestino, MAX + 1, stdin);
        strtok(aeroportoDestino,"\n");
    }

    printf("           Horario de saida do voo (hh:mm): ");
    scanf("%d %d", &(horapartida), &(minutopartida));

    // verifica se o horario de partida esta correto
    while((horapartida < 0 || horapartida > 23) || (minutopartida < 0 || minutopartida > 59)){
        msgAlerta();
        printf("           Horario Invalido.\n");
        printf("           Digite novamente o Horario de Partida do voo (hh:mm): ");
        scanf("%d %d", &(horapartida), &(minutopartida));
    }

    printf("           Horario de chegada do voo (hh:mm): ");
    scanf("%d %d", &(horachegada), &(minutochegada));

     // verifica se o horario de chegada esta correto
    while((horachegada < 0 || horachegada > 23) || (minutochegada < 0 || minutochegada > 59)){
        msgAlerta();
        printf("           Horario Invalido.\n");
        printf("           Digite novamente o Horario de chegada do voo (hh:mm): ");
        scanf("%d %d", &(horachegada), &(minutochegada));
    }

    printf("           Duracao do voo (hh:mm): ");
    scanf("%d %d", &(horaduracao), &(minutoduracao));
    setbuf(stdin,NULL);

     // verifica se o horario de duracao esta correto
    while((horaduracao < 0 || horaduracao > 23) || (minutoduracao < 0 || minutoduracao > 59)){
        msgAlerta();
        printf("           Horario Invalido.\n");
        printf("           Digite novamente a duracao do voo (hh:mm): ");
        scanf("%d %d", &(horaduracao), &(minutoduracao));

        setbuf(stdin,NULL);
    }

    printf("           Tipo da aeronave: ");
    fgets(aeronave, MAX + 1, stdin);
    strtok(aeronave,"\n");

    Voo* nova=(Voo*)malloc(sizeof(Voo));

    // se a lista de Voos esta vazia, cria novo Voo
    if(semCadastros(lista)){

        strcpy(nova->prefixo,prefixo);
        strcpy(nova->aeroportoOrigem, aeroportoOrigem);
        strcpy(nova->aeroportoDestino, aeroportoDestino);
        nova->horapartida = horapartida;
        nova->minutopartida = minutopartida;
        nova->horachegada = horachegada;
        nova->minutochegada = minutochegada;
        nova->horaduracao = horaduracao;
        nova->minutoduracao = minutoduracao;
        strcpy(nova->aeronave, aeronave);
        nova->prox=NULL;

        return nova;

    // senao, insere no final da lita
    }else{

        Voo* aux = lista;

        while(aux->prox != NULL){

            aux=aux->prox;
        }

        strcpy(nova->prefixo,prefixo);
        strcpy(nova->aeroportoOrigem, aeroportoOrigem);
        strcpy(nova->aeroportoDestino, aeroportoDestino);
        nova->horapartida = horapartida;
        nova->minutopartida = minutopartida;
        nova->horachegada = horachegada;
        nova->minutochegada = minutochegada;
        nova->horaduracao = horaduracao;
        nova->minutoduracao = minutoduracao;
        strcpy(nova->aeronave, aeronave);
        nova->prox=NULL;
        aux->prox=nova;

        return lista;
    }

}

/**
 * @brief imprimeListaDeVoos, Exibe todos os cadastros de Voos
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * pre-condicao: nenhuma
 * pos-condicao: Os cadastros de Voo sao exibidos no console
 */
void imprimeListaDeVoos(Voo* lista){

    // confere se ha voos cadastrados
    if(semCadastros(lista)){

        // se nao haver, imprime menu de Voos
        naoHaVoos();
        menuVoos();

    // senao, imprime lista com todos os voos
    }else{
        caixaDialogoListaVoos();
        while(lista!=NULL){

            printf("\n                  Prefixo do voo: %s", (lista->prefixo));
            printf("                  Aeroporto de origem: %s", lista->aeroportoOrigem);
            printf("                  Aeroporto de Destino: %s", lista->aeroportoDestino);
            printf("                  Horario de saida do voo: %02d:%02d\n", lista->horapartida, lista->minutopartida);
            printf("                  Horario de chegada do voo: %02d:%02d\n", lista->horachegada, lista->minutochegada);
            printf("                  Duracao do voo: %02d:%02d\n", lista->horaduracao, lista->minutoduracao);
            printf("                  Aeronave: %s\n", lista->aeronave);

            lista = lista->prox;
        }
        printf("\n\n");
    }
}

/**
 * @brief removerVoo, Remove um determinado Voo atraves da sigla do Voo
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * @return lista atualizada
 * pre-condicao: Nenhuma
 * pos-condicao: Lista com o voo removido
 */
Voo *removerVoo (Voo* lista){

    Voo* anterior = lista;
    Voo* atual = lista;
    char prefixo[MAX];

    caixaDialogoExcluirVoo();
    printf("        Digite o prefixo do voo que deseja remover:\n"
           "                        > ");
    fgets(prefixo, MAX+1, stdin);
    strtok("\n",prefixo);

    // percorre a lista ate encontrar o voo atraves do prefixo
    while( atual != NULL && strcmp(prefixo, atual->prefixo)!=0){

        anterior = atual;

        atual=atual->prox;
    }

    // encontra o elemente e remove-o
    if(atual != NULL){

        if(atual==lista)
            lista=lista->prox;
        else
            anterior->prox = atual->prox;

        printf("\n\n                 Voo removido com sucesso!                  \n\n");
        free(atual);
    }
    else
        printf("\n\n                  Prefixo NAO encontrado!                  \n\n");
    return lista;
}

/**
 * @brief consultarVoo, Consultar determinado voo
 * @param lista, lista com ou sem informacoes de cadastro de Voos
 * pre-condicao: nenhuma
 * pos-condicao: Determinado cadastro de voo exibido no console
 */
void consultarVoo(Voo* lista){

    Voo* atual = lista;
    char prefixo[MAX];

    system("cls");
    caixaDialogoConsultarUmVoo();
    printf("           Digite a sigla do voo que deseja consultar:\n"
           "                        > ");
    fgets(prefixo, MAX+1, stdin);
    strtok("\n",prefixo);

    // percorrer lista ate encontrar o voo atraves do prefixo
    while( atual != NULL && strcmp(prefixo, atual->prefixo)!=0){

        atual=atual->prox;
    }

    // se chegou no fim da lista e nao encontrou
    if(atual==NULL){
        printf("\n\n                  Prefixo NAO encontrado!                  \n\n");

    // se encontrou
    }else{
        dadosVoo();
        printf("\n                  Prefixo do voo: %s", (atual->prefixo));
        printf("                  Aeroporto de origem: %s", atual->aeroportoOrigem);
        printf("                  Aeroporto de Destino: %s", atual->aeroportoDestino);
        printf("                  Horario de saida do voo: %02d:%02d\n", atual->horapartida, atual->minutopartida);
        printf("                  Horario de chegada do voo: %02d:%02d\n", atual->horachegada, atual->minutochegada);
        printf("                  Duracao do voo: %02d:%02d\n", atual->horaduracao, atual->minutoduracao);
        printf("                  Aeronave: %s\n", atual->aeronave);
    }
}

/**
 * @brief menuVoos, Manipula todas funcoes do Voo, como inserir, exibir e remover
 * pre-condicao: Nenhuma
 * pos-condicao: operacao solicitada eh realizada
 */
void menuVoos(){

    Voo *voo = (Voo*)malloc(sizeof(Voo));
    voo = NULL;

    int opVoo;

    caixaDialogoMenuVoos();
    scanf("%d", &opVoo);
    setbuf(stdin,NULL);
    printf("\n");

    while (opVoo != 0) {
        switch (opVoo) {

        // insere novo voo
        case 1:
            system("cls");
            voo = insereVoo(voo);
            operacaoRealizadaSucesso();
            getchar();
            system("cls");
            break;

        // imprime lista de todos voos
        case 2:
            system("cls");
            imprimeListaDeVoos(voo);
            system("pause");
            system("cls");
            break;

        // consulta UM voo
        case 3:
            consultarVoo(voo);
            system("pause");
            system("cls");
            break;

        // remove um cadasro de voo
        case 4:
            voo = removerVoo(voo);
            getchar();
            system("cls");
            break;

        // confirma se o usuario quer sair
        case 5:
            menuSair();
            break;


        default:
            operacaoInvalida();
        }
        caixaDialogoMenuVoos();
        scanf("%d", &opVoo);
        setbuf(stdin,NULL);
        printf("\n");
    }
}
