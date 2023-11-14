#include <stdio.h>
#include <stdlib.h>

typedef struct joseph{
    int I, K, O;
    struct joseph* prox;
} joseph;

int main(){
    joseph* inicioLista = NULL;
    joseph* anterior = NULL;
    joseph* atual = NULL;

    int N, i = 1;
    int kAux;
    int removidos[1000];
    int indiceRe = -1;


    atual = (joseph*) malloc(sizeof(joseph));

    //altera stdin padrão
    //freopen("teste.txt", "r", stdin);


    scanf("%d", &N);

    //primeiro elemento da lista circular
    scanf("%d %d", &atual->K, &atual->O);
    atual->I = i;
    inicioLista = atual;

    for (i = 2; i<= N; i++){
        atual->prox = (joseph*) malloc(sizeof(joseph));
        atual = atual->prox;
        scanf("%d %d", &atual->K, &atual->O);
        atual->I = i;
    }
    //fecha a lista circular
    atual->prox = inicioLista;

    //volta ao primeiro elemento da lista circular
    atual = inicioLista;
    kAux = atual->K;
    //enquanto existir mais de um elemento na lista circular
    while (N > 1){
        //percorre kAux elementos da lista não contando elementos já excluídos
        i = 1;
        while (i != kAux){
            atual = atual->prox;
            if (atual->O == -1)
                while (atual->O == -1)
                    atual = atual->prox;
            i++;
        }
        if (atual->O == 0){
            atual->O = -1;
            //printf("Remove: %d\n", atual->I);
            kAux = atual->K;
            //inicio da lista de remoção
            if (indiceRe == -1){
                removidos[0] = atual->I;
                indiceRe = 0;    
            }else{
                indiceRe++;
                removidos[indiceRe] = atual->I;
            }
            N--;
        }else{
            atual->O = -1;
            //printf("Remove %d\n", atual->I);
            kAux = atual->K;
            anterior = inicioLista;
            while (anterior->I != removidos[indiceRe])
                anterior = anterior->prox;
            anterior->O = 0;
            indiceRe--;
            //guarda o excluído depois de restaurar
            indiceRe++;
            removidos[indiceRe] = atual->I;
            //printf("Restaura %d\n", anterior->I);
        }
        while (atual->O == -1)
            atual = atual->prox;
    }

    printf("%d", atual->I);

    return 0;
}