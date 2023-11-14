#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines
#define MAX 1001

//Dados abstratos
typedef struct dicio{
    char nome[30];
    struct dicio* prox;   
} dicionario;

//Protótipo de funções
dicionario* insereLista(dicionario*);
dicionario* removeLista(dicionario*);
void mostraLista(dicionario*);

int main(){
    dicionario* inicioLista = NULL;
    int N, M;
    int op = 0;
    int i;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++){
        inicioLista = insereLista(inicioLista);
    }

    for (i = 0; i < M; i++){
        scanf("%d ", &op);
        if (op == 0){
            inicioLista = removeLista(inicioLista);
            mostraLista(inicioLista);
        }
        else
            inicioLista = insereLista(inicioLista);
    }
    
}

dicionario* insereLista(dicionario* inicioLista){
    
    dicionario* novaPalavra = (dicionario*) malloc(sizeof(dicionario));
    dicionario* aux = inicioLista;
    dicionario* anterior = NULL;

    //inicializa novaPalavra
    scanf("%s", novaPalavra->nome);
    novaPalavra->prox = NULL;

    //se lista vazia
    if (inicioLista == NULL){
        inicioLista = novaPalavra;
    }
    //procura posicao correta
    else{
        while (aux != NULL && strcmp(aux->nome, novaPalavra->nome) < 0){
            anterior = aux;
            aux = aux->prox;
        }
        //palavras iguais
        if (aux != NULL)
            if(strcmp(aux->nome, novaPalavra->nome) == 0)
                return inicioLista;
        
        //inserção no inicio
        if (anterior == NULL){
            novaPalavra->prox = inicioLista;
            inicioLista = novaPalavra;
        }
        //inserção no fim
        else if (aux == NULL){
            anterior->prox = novaPalavra;
        }
        //inserção no meio
        else{
            novaPalavra->prox = aux;
            anterior->prox = novaPalavra;
        }
    }
    return inicioLista;
}

dicionario* removeLista(dicionario* inicioLista){
    char nome[30];
    dicionario* aux = inicioLista;
    dicionario* anterior = inicioLista;

    scanf("%s", nome);

    //lista vazia
    if (aux == NULL)
        return NULL;
    
    //percorre a lista até encontrar o nome igual
    while (aux != NULL && strcmp(aux->nome, nome) != 0){
        anterior = aux;
        aux = aux->prox;
    }
    
    //se não encontrou o nome na lista
    if (aux == NULL)
        return inicioLista;
    //se encontrou
    else{
        //remoção no inicio
        if (aux == inicioLista){
            inicioLista = inicioLista->prox;
            free(aux);
        }
        //remoção no fim
        else if (aux->prox == NULL){
            anterior->prox = NULL;
            free(aux);
        }
        //remoção no meio
        else{
            anterior->prox = aux->prox;
            free(aux);
        }
    }
    return inicioLista;
}

void mostraLista(dicionario* inicioLista){
    dicionario* aux = inicioLista;

    if (aux == NULL){
        printf("NULL\n");
        return;
    }
    while (aux != NULL){
        printf("%s ", aux->nome);
        aux = aux->prox;
    }
    printf("\n");
}