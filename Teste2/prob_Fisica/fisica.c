#include <stdio.h>
#include <math.h>

void distanciaMRU();
void velocidadeMRU();
void tempoMRU();
void distanciaMRUV();
void velocidadeFinalMRUV();         
void velocidadeInicialMRUV();
void tempoTotalMRUV();

int main(){

    int N, O;
    int i;

    //freopen("input.txt","r",stdin);//redirects standard input
    //freopen("output.txt","w",stdout);//redirects standard output

    scanf("%d", &N);

    for (i = 0; i < N; i++){
        scanf("%d ", &O);
        switch (O)
        {
        case 1:
            distanciaMRU();
            break;
        case 2:
            velocidadeMRU();
            break;
        case 3:
            tempoMRU();
            break;
        case 4:
            distanciaMRUV();
            break;
        case 5:
            velocidadeFinalMRUV();
            break;
        case 6:
            velocidadeInicialMRUV();
            break;
        case 7:
            tempoTotalMRUV();
            break;
        default:
            break;
        }
    }
    return 0;
}

void distanciaMRU(){
    double T, V;

    scanf("%lf %lf", &T, &V);
    printf("%.2lf\n", (T*V));
}

void velocidadeMRU(){
    double S, T;

    scanf("%lf %lf", &S, &T);
    printf("%.2lf\n", (S/T));
}

void tempoMRU(){
    double S, V;

    scanf("%lf %lf", &S, &V);
    printf("%.2lf\n", (S/V));
}

void distanciaMRUV(){
    double V, A, T;

    scanf ("%lf %lf %lf", &V, &A, &T);
    printf("%.2lf\n", ((V*T) + (A*T*T/2)));
}
           
void velocidadeFinalMRUV(){
    double V, A, T;
    scanf("%lf %lf %lf", &V, &A, &T);
    printf("%.2lf\n", (V+(A*T)));
}
            
void velocidadeInicialMRUV(){
    double S, A, T;

    scanf("%lf %lf %lf", &S, &A, &T);
    printf("%.2lf\n", ((S-(A*T*T/2))/T));
}
            
void tempoTotalMRUV(){
    double S, V, A;

    scanf("%lf %lf %lf", &S, &V, &A);
    printf("%.2lf\n", (( ((-1.0)*V) + (sqrt((V*V)+(2*A*S)))  )/A));
}