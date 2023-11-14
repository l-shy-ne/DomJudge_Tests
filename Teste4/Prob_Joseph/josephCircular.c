#include <stdio.h>
#include <stdlib.h>

typedef struct josephCircular
{
    int I, K, O;
    struct josephCircular* prox;
} joseph;


int main(){
    joseph* inicioLista = NULL;
    joseph* atual = (joseph*) malloc(sizeof(joseph));
    joseph* anterior = NULL;

    int N, i = 1, kAux;

    freopen("teste.txt","r",stdin);//redirects standard input

    scanf("%d", &N);

    inicioLista = atual;
    scanf("%d %d", &atual->K, &atual->O);
    atual->I = i;
    for (i = 2; i < N; i++){
        anterior = atual;
        atual->prox = (joseph*) malloc(sizeof(joseph));
        atual = atual->prox;
        anterior->prox = atual;
        scanf("%d %d", &atual->K, &atual->O);
        atual->I = i;
    }
    atual->prox = inicioLista;

    atual = inicioLista;
    kAux = atual->K;
    atual = atual->prox;
    while (N > 1){
        //percorre as K posições
        for (i = 0; i < kAux; i++){
            if (atual->O == -1){
                while (atual->O == -1)
                    atual = atual->prox;
            }else{
                atual = atual->prox;
            }
            i++;
        }
        while (atual->O == -1)
            atual = atual->prox;
        if (atual->O == 0){
            atual->O = -1;
            printf("Remove: %d\n", atual->I);
            anterior = atual;
            N--;
        }else{
            atual->O = -1;
            printf("Remove %d\n", atual->I);
            anterior->O = 0;
            printf("Restora %d\n", anterior->I);
        }
        while (atual->O == -1)
            atual = atual->prox;
        kAux = atual->K;
    }

    printf("%d", atual->I);

    return 0;
}