#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void hanoiDiferenciado (int altura, int origem[], int* indexO, int destino[], int*indexD, int aux[], int* indexA, int origemOriginal[], int destinoOriginal[], int auxOriginal[], int* indexOOriginal, int* indexDOriginal, int* indexAOriginal);

int pinosIguais(int origem[], int* indexO, int aux[], int* indexA, int destino[], int* indexD);
int elevado (int, int);

int origemI[21], destinoI[21], auxiliarI[21];
int indexOI, indexDI, indexAI;
int movs = 0, N;

int main(){

    int K;
    int origem[21], destino[21], aux[21];
    int indexO = 0, indexD = 0, indexA = 0;
    //int movs = 0;
    int i, j;

    //Tratamento para o caso de 1 disco e 1 movimento
    //Já que os vetores não foram inicializados, então resultaria em erro, ao printar 0 para vetores vazios, no caso, o vetor aux, que estaria vazio.
    origem[1] = 0;
    destino[1] = 0;
    aux[1] = 0;

    //N
    scanf("%d", &N);

    //Pinos
    //Origem
    scanf("%d", &indexOI);
    if (indexOI == 0){
        origemI[1] = 0;
        //indexOI = 1;
    }
    else{
        for (i = indexOI; i >= 1; i--){
            scanf(" %d", &origemI[i]);
        }
    }
    //Auxiliar
    scanf("%d", &indexAI);
    if (indexAI == 0){
        auxiliarI[1] = 0;
        //indexAI = 1;
    }
    else{
        for (i = indexAI; i >= 1; i--){
          scanf(" %d", &auxiliarI[i]);
        }    
    }
    
    //Destino
    scanf("%d", &indexDI);
    if (indexDI == 0){
        destinoI[1] = 0;
        //indexDI = 1;
    }
    else{
        for (i = indexDI; i >= 1; i--){
            scanf(" %d", &destinoI[i]);
        }
    }
    
    j = N;
    for(i = 1; i <= N; i++){
        origem[i] = j;
        j--;
    }
    indexO = N;
    hanoiDiferenciado(N, origem, &indexO, destino, &indexD, aux, &indexA, origem, destino, aux, &indexO, &indexD, &indexA);

    /*
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
    */
   //printf("%d\n", movs);
   //printf("%d", (int) ((elevado(2, N) - 1) - movs));
   //printf("%d", ((elevado(2, N) - 1 - movs)));
    return 0;
}

void hanoiDiferenciado (int altura, int origem[], int* indexO, int destino[], int*indexD, int aux[], int* indexA, int origemOriginal[], int destinoOriginal[], int auxOriginal[], int* indexOOriginal, int* indexDOriginal, int* indexAOriginal){
    if (pinosIguais(origemOriginal, indexOOriginal, auxOriginal, indexAOriginal, destinoOriginal, indexDOriginal))
        return;
    if (altura == 1){
        (*indexD)++;
        destino[*indexD] = origem[*indexO];
        origem[*indexO] = 0;
        (*indexO)--;
        movs++;
        //printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
    } 
    else{
        hanoiDiferenciado(altura-1, origem, indexO, aux, indexA, destino, indexD, origemOriginal, destinoOriginal, auxOriginal, indexOOriginal, indexDOriginal, indexAOriginal);
        if (pinosIguais(origemOriginal, indexOOriginal, auxOriginal, indexAOriginal, destinoOriginal, indexDOriginal)){
            return;
        }
        else{
            (*indexD)++;
            destino[*indexD] = origem[*indexO];
            origem[*indexO] = 0;
            (*indexO)--;
            movs++;
        }
        //printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
        hanoiDiferenciado(altura-1, aux, indexA, destino, indexD, origem, indexO, origemOriginal, destinoOriginal, auxOriginal, indexOOriginal, indexDOriginal, indexAOriginal);
    }
}

int pinosIguais(int origem[], int* indexO, int aux[], int* indexA, int destino[], int* indexD){
    int i;
    int diff = 1;
    if ((*indexO == indexOI) && (*indexA == indexAI) && (*indexD == indexDI)){
        for (i = indexOI; i >= 1; i--){
            if (origem[i] != origemI[i]){
                diff = 0;
                break;
            }
        }
        for (i = indexAI; i >= 1; i--){
            if (aux[i] != auxiliarI[i]){
                diff = 0;
                break;
            }
        }
        for (i = indexDI; i >= 1; i--){
            if (destino[i] != destinoI[i]){
                diff = 0;
                break;
            }
        }
        //printf("%d\n", movs);
        //printf("%d\n", elevado(2, N));
        if (diff == 1){
            printf("%d", ((elevado(2, N) - 1 - movs)));
            exit(0);
        }
    }
    return 0;
    
}

int elevado(int nro, int N){
    int i;
    int elevado = 1;

    for (i = N; i >= 1; i--){
        elevado *= nro;
    }

    return elevado;
}