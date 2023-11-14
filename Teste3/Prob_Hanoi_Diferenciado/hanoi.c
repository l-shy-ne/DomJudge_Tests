#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int disco;
    struct no* prox;
} No;

No pop(No*);
void push(No*, No);
void hanoi (int , No*, No*, No*, int*);

int main(){
    int N; //numero de discos
    int* K; //numero de jogadas

    No *pinoA; //pino origem
    No *pinoB; //pino auxiliar
    No *pinoC; //pino destino

    No discoAux;
    //leitura do numero de disco e jogadas
    scanf("%d %d", &N, K);

    for (int i = N; i > 0; i--){
        discoAux.disco = i;
        push(pinoA, discoAux);
    }

    hanoi(N, pinoA, pinoC, pinoB, K);

    return 0;
}

No pop (No* pino){
    No pinoAux;

    pinoAux.disco = pino->disco;
    pinoAux.prox = pino->prox;

    pino = pino->prox;

    return pinoAux;
}

void push(No* pino, No disco){
    No* novoPino = (No*) malloc(sizeof(No));
    novoPino->disco = disco.disco;
    novoPino->prox = pino;
}

void hanoi (int nDiscos, No* pinoA, No* pinoC, No* pinoB, int* movimentacoes){
    if (*movimentacoes == 0){
        return;
    }
    if (nDiscos == 1){
        push(pinoC, pop(pinoA));
        *movimentacoes -= 1;
    }
    else{
        hanoi(nDiscos-1, pinoA, pinoB, pinoC, movimentacoes);
        if (*movimentacoes == 0){
            return;
        }
        push(pinoC, pop(pinoA));
        *movimentacoes -= 1;
        hanoi(nDiscos-1, pinoB, pinoC, pinoA, movimentacoes);
    }

}


/*void hanoi (int altura, int origem, int destino, int aux){
    if (altura == 1){
        printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
    } 
    else{
        hanoi(altura-1, origem, aux, destino);
        printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
        hanoi(altura-1, aux, destino, origem);
    }
}*/