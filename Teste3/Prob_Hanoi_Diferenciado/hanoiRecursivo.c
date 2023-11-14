#include <stdio.h>

void hanoiDiferenciado(int altura, int origem[], int* indexO, int destino[], int*indexD, int aux[], int* indexA, int* movs, int N);

int main(){

    int N, K;
    int origem[21], destino[21], aux[21];
    int indexO = 0, indexD = 0, indexA = 0;
    int movs = 0;
    int i, j;

    //Tratamento para o caso de 1 disco e 1 movimento
    //Já que os vetores não foram inicializados, então resultaria em erro, ao printar 0 para vetores vazios, no caso, o vetor aux, que estaria vazio.
    origem[1] = 0;
    destino[1] = 0;
    aux[1] = 0;
    
    scanf("%d %d", &N, &K);

    j = N;
    for(i = 1; i <= N; i++){
        origem[i] = j;
        j--;
    }
    indexO = N;
    hanoiDiferenciado(N, origem, &indexO, destino, &indexD, aux, &indexA, &movs, K);

    if (origem[1] == 0){
        printf("0");
    }
    else{
        for (i = indexO; i >= 1; i--){
            printf("%d ", origem[i]);
        }
    }
    printf("\n");
    if (aux[1] == 0){
        printf("0");
    }
    else{
        for (i = indexA; i >= 1; i--){
            printf("%d ", aux[i]);
        }
    }
    printf("\n");
    if (destino[1] == 0){
        printf("0");
    }
    else{
        for (i = indexD; i >= 1; i--){
            printf("%d ", destino[i]);
        }
    }

    return 0;
}

void hanoiDiferenciado (int altura, int origem[], int* indexO, int destino[], int*indexD, int aux[], int* indexA, int* movs, int K){
    if (*movs == K)
        return;
    if (altura == 1){
        (*indexD)++;
        destino[*indexD] = origem[*indexO];
        origem[*indexO] = 0;
        (*indexO)--;
        (*movs)++;
        //printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
    } 
    else{
        hanoiDiferenciado(altura-1, origem, indexO, aux, indexA, destino, indexD, movs, K);
        if (*movs == K)
            return;
        (*indexD)++;
        destino[*indexD] = origem[*indexO];
        origem[*indexO] = 0;
        (*indexO)--;
        (*movs)++;
        //printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
        hanoiDiferenciado(altura-1, aux, indexA, destino, indexD, origem, indexO,movs, K);
    }
}