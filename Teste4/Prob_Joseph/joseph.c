#include <stdio.h>
#include <stdlib.h>

typedef struct joseph
{
    int I, K, O;
    struct joseph *prox;
} joseph;

int main()
{
    joseph *inicioLista = NULL;
    joseph *novoElemento = (joseph *)malloc(sizeof(joseph));
    joseph *elementoAnterior = NULL;

    joseph *aux = NULL;
    joseph *atual = NULL;

    int N, i, kAux = 0;

    freopen("teste.txt","r",stdin);//redirects standard input

    scanf("%d", &N);

    i = 1;
    scanf("%d %d", &novoElemento->K, &novoElemento->O);
    novoElemento->I = i;
    inicioLista = novoElemento;
    for (i = 2; i <= N; i++)
    {
        elementoAnterior = novoElemento;
        novoElemento = (joseph*) malloc(sizeof(joseph));
        scanf("%d %d", &novoElemento->K, &novoElemento->O);
        novoElemento->I = i;
        elementoAnterior->prox = novoElemento;
    }
    novoElemento->prox = inicioLista;

    atual = inicioLista;
    while (N > 1){
        kAux = atual->K;
        i = 1;
        while (i != kAux){
            atual = atual->prox;
            if (atual->O == -1){
                atual = atual->prox;
            }else {
                atual = atual->prox;
                i++;
            }
        }
        if (atual->O == 0){
            atual->O = -1;
            printf("Remove: %d\n", atual->I);
            elementoAnterior = atual;
            N--;
            while (atual->O == -1)
                atual = atual->prox;
        }
        else{
            atual->O = -1;
            printf("Remove: %d\n", atual->I);
            elementoAnterior->O = 0;
            printf("Restaura: %d\n", elementoAnterior->I);
            while (atual->O == -1)
                atual = atual->prox;
        }
    }

    printf("%d", atual->K);

    return 0;
}
