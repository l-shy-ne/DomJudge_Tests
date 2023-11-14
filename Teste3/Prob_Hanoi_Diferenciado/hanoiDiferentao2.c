#include <stdio.h>

#define K 0

int main(){
    int origem[21], auxiliar[21], destino[21];
    int N;
    int i;

    origem[1] = 0;
    auxiliar[1] = 0;
    destino[1] = 0;
    
    //N
    scanf("%d", &N);

    //Pinos
    //Origem
    scanf("%d", &origem[K]);
    for (i = 1; i <= origem[K]; i++){
        scanf(" %d", &origem[i]);
    }
    //Auxiliar
    scanf("%d", &auxiliar[K]);
    for (i = 1; i <= auxiliar[K]; i++){
        scanf(" %d", &auxiliar[i]);
    }
    //Destino
    scanf("%d", &destino[K]);
    for (i = 1; i <= destino[K]; i++){
        scanf(" %d", &destino[i]);
    }
    
    hanoi(N, origem, destino, auxiliar);

    return 0;
}

void hanoi (int altura, int origem[], int destino[], int auxiliar[]){
    if (altura == 1){
        
        printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
    } 
    else{
        hanoi(altura-1, origem, auxiliar, destino);
        printf("Move disco %d de Pino %d para Pino %d\n", altura, origem, destino);
        hanoi(altura-1, auxiliar, destino, origem);
    }
}
