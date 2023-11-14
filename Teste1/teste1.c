#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nome[21];
    double pesoW;
    int x, y, z;

} Planetas;

int main(){
    Planetas vet[10000];
    //puts("Sucesso ao alocar 10000 posições");

    int N, M, op;
    int pos1 = 0, pos2 = 0;
    double distancia = 0, xQuad = 0, yQuad = 0, zQuad = 0;
    char nome1[21], nome2[21];
    int i = 0;

    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++){
        scanf("%s %lf %d %d %d", vet[i].nome, &vet[i].pesoW, &vet[i].x, &vet[i].y, &vet[i].z);
        //printf("%s %.2f %d %d %d", vet[i].nome, vet[i].pesoW, vet[i].x, vet[i].y, vet[i].z);
    }
    for (i = 0; i < M; i++){
        int j = 0;
        scanf("%d", &op);
        //nome de dois planetas e distancia entre eles
        if (op == 1){
            scanf("%s %s", nome1, nome2);
            for(j = 0; j < N; j++){
                if (!strcmp(vet[j].nome, nome1)){
                    pos1 = j;
                }
                if (!strcmp(vet[j].nome, nome2)){
                    pos2 = j;
                }
            }
            xQuad = vet[pos2].x - vet[pos1].x;
            xQuad *= xQuad;
            yQuad = vet[pos2].y - vet[pos1].y;
            yQuad *= yQuad;
            zQuad = vet[pos2].z - vet[pos1].z;
            zQuad *= zQuad;
            distancia = sqrt((xQuad + yQuad + zQuad));
            printf("%.2lf\n", distancia);
        }
        //nome de um planeta e coordenadas dele
        if (op == 2){
            scanf("%s", nome1);
            for(j = 0; j < N; j++){
                if (!strcmp(vet[j].nome, nome1)){
                    pos1 = j;
                    printf ("%d %d %d\n", vet[pos1].x, vet[pos1].y, vet[pos1].z);
                }
            }
        }
        //nome de um planeta e seu peso
        if (op == 3){
            scanf("%s", nome1);
            for(j = 0; j < N; j++){
                if (!strcmp(vet[j].nome, nome1)){
                    pos1 = j;
                    printf("%.2lf\n", vet[pos1].pesoW);
                }
            }
        }
    }
   return 0;
}