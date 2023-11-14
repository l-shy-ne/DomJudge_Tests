#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct outrafila
{
    int idade;
    int tempo;
    struct outrafila *prox;
} outrafila;

// Protótipos de funções
void insereFila(outrafila **, outrafila **, outrafila **, outrafila *, int *);
void removeFila(outrafila **, outrafila **);
void mostraFila(outrafila*, outrafila*);
void mostraBuffer(outrafila *);
void insereBuffer(outrafila **, outrafila *);

// Função main
int main()
{

    // Variaveis de Fila
    outrafila *inicioFila = NULL;
    outrafila *fimFila = NULL;
    outrafila *pessoa = NULL;
    outrafila *caixa = NULL;

    // Variaveis do Buffer (lista circular que ordena as entradas pelo tempo)
    outrafila *buffer = NULL;

    //
    outrafila *anterior = NULL;

    // Variaveis de Gerais
    int N, i;
    int timer, *ptimer;
    ptimer = &timer;

    // altera stdin
    //freopen("teste.txt", "r", stdin);

    // N
    scanf("%d", &N);

    // preenche buffer (lista circular ordenada pelo tempo)
    // FUNCIONANDO
    for (i = 0; i < N; i++){
        pessoa = (outrafila *)malloc(sizeof(outrafila));
        scanf("%d %d", &pessoa->idade, &pessoa->tempo);
        pessoa->prox = NULL;
        insereBuffer(&buffer, pessoa);
    }

    // FUNCIONANDO
    //mostraBuffer(buffer);

    // NÃO TERMINADO (TESTANDO)
    *ptimer = 0;
    for (i = 0; i < N; i++){
        pessoa = (outrafila *)malloc(sizeof(outrafila));
        pessoa->idade = buffer->idade;
        pessoa->tempo = buffer->tempo;
        pessoa->prox = NULL;
        insereFila(&inicioFila, &fimFila, &caixa, pessoa, ptimer);
        anterior = buffer;
        buffer = buffer->prox;
        if (i < N-1)
            *ptimer = (*ptimer) + (buffer->tempo - anterior->tempo);
        if (anterior->tempo != buffer->tempo)
            mostraFila(inicioFila, caixa);      
    }
    
    return 0;
}

/*
 * Função que mostra a Fila de pessoas
 */
void mostraFila(outrafila *inicioFila, outrafila* caixa)
{
    outrafila *aux = inicioFila;

    printf("%d ",caixa->idade);
    while (aux != NULL)
    {
        printf("%d ",aux->idade);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

/*
 * Função que mostra o buffer de pessoas recebidas do teclado
 */
void mostraBuffer(outrafila *buffer)
{
    outrafila *aux = buffer;

    printf("%d %d\n", aux->tempo, aux->idade);
    aux = aux->prox;
    while (aux != buffer)
    {
        printf("%d %d\n", aux->tempo, aux->idade);
        aux = aux->prox;
    }
    return;
}

/*
 * Função que insere as pessoas no buffer de acordo com o tempo de chegada
 */

void insereBuffer(outrafila **buffer, outrafila *pessoa)
{

    outrafila *aux = (*buffer);
    outrafila *anterior = (*buffer);

    // lista vazia
    if ((*buffer) == NULL)
    {
        (*buffer) = pessoa;
        (*buffer)->prox = (*buffer); // fecha lista circular
        return;
    }
    // lista com apenas um elemento
    if ((*buffer)->prox == (*buffer))
    {
        pessoa->prox = aux;
        aux->prox = pessoa;
        if (pessoa->tempo < (*buffer)->tempo)
            (*buffer) = pessoa;
        return;
    }
    // lista com pessoas
    // procura posição correta na lista
    while (anterior->prox != (*buffer) && aux->tempo < pessoa->tempo)
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == (*buffer) && pessoa->tempo < aux->tempo)
    {
        anterior = aux->prox;
        while (anterior->prox != aux)
        {
            anterior = anterior->prox;
        }
        anterior->prox = pessoa;
        pessoa->prox = (*buffer);
        (*buffer) = pessoa;
        return;
    }
    pessoa->prox = aux;
    anterior->prox = pessoa;
    if (pessoa->tempo < (*buffer)->tempo)
        (*buffer) = pessoa;
    return;
}

/*
 * Função que insere as pessoas na Fila propriamente dita
 * Precisa-se adicionar a função de timer ainda
 */
void insereFila(outrafila **inicioFila, outrafila **fimFila, outrafila **caixa, outrafila *pessoa, int *ptimer)
{

    outrafila *aux = (*inicioFila);
    outrafila *anterior = (*inicioFila);

    while ((*ptimer) >= 3){
        (*caixa) = NULL;
        *ptimer = (*ptimer) - 3;
        if ((*caixa) == NULL){
            (*caixa) = (*inicioFila);
            removeFila(inicioFila, fimFila);
        }
    }

    aux = (*inicioFila);
    anterior = (*inicioFila);

    // Fila vazia
    if ((*fimFila) == NULL){
        (*inicioFila) = (*fimFila) = pessoa;
        if ((*caixa) == NULL){
            (*caixa) = (*inicioFila);
            removeFila(inicioFila, fimFila);
        }
        return;
    }
    // Fila com pessoas
    else{
        // Fila prioritária
        if (pessoa->idade > 59){
            //antes da pessoa mais nova que o velho no começo da fila
            while (aux != NULL && aux->idade > pessoa->idade){
                anterior = aux;
                aux = aux->prox;
            }

            //inserção no início
            if (aux == (*inicioFila)){
                if (aux->idade < pessoa->idade){
                    pessoa->prox = aux;
                    (*inicioFila) = pessoa;
                    return;
                }else{
                    aux->prox = pessoa;
                    return;
                }
                
            }

            // chegou ao fim da fila (todos na fila são mais velhos que o velho)
            if (aux == NULL)
            {
                (*fimFila)->prox = pessoa;
                (*fimFila) = pessoa;
                return;
            }
            // idades iguais
            if (aux->idade == pessoa->idade)
            {
                while (aux != NULL && aux->idade == pessoa->idade)
                {
                    anterior = aux;
                    aux = aux->prox;
                }

                // achou uma pessoa mais jovem que o velho
                if (aux->idade < pessoa->idade)
                {
                    anterior->prox = pessoa;
                    pessoa->prox = aux;
                    return;
                }
                // chegou ao fim da fila e não achou alguém mais jovem que o velho
                if (aux == NULL)
                {
                    (*fimFila)->prox = pessoa;
                    (*fimFila) = pessoa;
                    return;
                }
            }

            // insere no meio da fila, achou alguém mais novo, logo, o velho é inserido depois dele
            if (aux->idade < pessoa->idade)
            {
                anterior->prox = pessoa;
                pessoa->prox = aux;
                return;
            }
        }
        // Fila normal
        else
        {
            (*fimFila)->prox = pessoa;
            (*fimFila) = pessoa;
            return;
        }
    }
}

/*
 * Função que remove as pessoas da fila
 */
void removeFila(outrafila **inicioFila, outrafila **fimFila)
{
    outrafila *aux = (*inicioFila);

    // remover o primeiro da fila
    (*inicioFila) = aux->prox;
    if ((*inicioFila) == NULL){
        (*fimFila) = NULL;
        return;
    }
    // free(aux);
    return;
}