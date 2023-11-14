#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[19];
    int identificacao;
    float salarioHora;
    int nHoras;
} salario;


int main(){
    //freopen("input.txt","r",stdin);//redirects standard input
    //freopen("output.txt","w",stdout);//redirects standard output
    int N, M;
    int contaM = 0;
    int i, j, op, identFunc, salvo = 0;
    char nome[19];
    float salarioBruto = 0, desconto = 0, salarioLiq = 0, fator = 0, acerto = 0;
    salario vet[1000];

    //leitura de N e M
    scanf("%d %d", &N, &M);

    //entrada de N funcionarios
    for (i = 0; i < N; i++){
        scanf("%s %d %f %d", vet[i].nome, &vet[i].identificacao, &vet[i].salarioHora, &vet[i].nHoras);
    }

    //M operações
    for (i = 0; i < M; i++){
        contaM = M - 1;
        scanf("%d ", &op);
        //recebe nro de identificacao
        if(op == 1){
            scanf("%d", &identFunc);
            for (j = 0; j < N; j++){
                if (identFunc == vet[j].identificacao){
                    salvo = j;
                    break;
                }
            }
            printf("%s %d\n", vet[salvo].nome, vet[salvo].nHoras);
            /*if(contaM > 0){
                printf("\n");
                contaM--;
            }*/

        }
        if(op == 2){
            scanf("%s", nome);
            for( j = 0; j < N; j++){
                if (strcmp(nome, vet[j].nome) == 0){
                    salvo = j;
                }
            }
            salarioBruto = 0;
            salarioBruto = vet[salvo].nHoras * vet[salvo].salarioHora;
            printf("%d %.2f\n", vet[salvo].identificacao, salarioBruto);
            /*if(contaM > 0){
                printf("\n");
                contaM--;
            }*/
        }
        if(op ==3){
            scanf("%d", &identFunc);
            for (j = 0; j < N; j++){
                if (identFunc == vet[j].identificacao){
                    salvo = j;
                    break;
                }
            }
            //salario bruto
            salarioBruto = 0;
            salarioBruto = vet[salvo].nHoras * vet[salvo].salarioHora;
            //desconto
            if (salarioBruto <= 1999.99){
                fator = acerto = 0;
            }
            if (salarioBruto >= 2000 && salarioBruto <= 4999.99){
                fator = 0.1;
                acerto = 200.00;
            }
            if (salarioBruto >= 5000){
                fator = 0.25;
                acerto = 950.00;
            }
            desconto = ((fator * salarioBruto) - acerto);
            //salario liquido (salario bruto - desconte)
            salarioLiq = salarioBruto - ((fator * salarioBruto) - acerto);
            
            printf("%s %.2f %.2f\n", vet[salvo].nome, ((fator * salarioBruto) - acerto), (salarioBruto - ((fator * salarioBruto) - acerto)));
            /*if(contaM > 0){
                printf("\n");
                contaM--;
            }*/
        }
    }

}