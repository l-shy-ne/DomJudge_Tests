#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[19];
    int identificacao;
    float salarioHora;
    int nHoras;
} salario;

typedef struct{
    int tipo;
    int identificacao;
    char nome[19];
} operacao;

int main(){
    int N, M;
    int contaM = 0;
    int i, j, op, identFunc, salvo = 0;
    char nome[19];
    long double salarioBruto = 0, desconto = 0, salarioLiq = 0, fator = 0, acerto = 0;
    salario vet[1000];
    operacao ops[1000];
    
    //freopen("input.txt","r",stdin);//redirects standard input
    //freopen("output.txt","w+",stdout);//redirects standard output

    //leitura de N e M
    scanf("%d %d", &N, &M);

    //entrada de N funcionarios
    for (i = 0; i < N; i++){
        scanf("%s %d %f %d", vet[i].nome, &vet[i].identificacao, &vet[i].salarioHora, &vet[i].nHoras);
    }

    //M operações
    for (i = 0; i < M; i++){
        scanf("%d ", &ops[i].tipo);
        //recebe a identificacao
        if (ops[i].tipo == 1 || ops[i].tipo == 3){
            scanf("%d", &ops[i].identificacao);
        }
        //recebe o nome
        if (ops[i].tipo == 2){
            scanf("%s", ops[i].nome);
        }
    }

    //M saídas
    contaM = M -1;
    for (i = 0; i < M; i++){
        if (ops[i].tipo == 1){
            for (j = 0; j < N; j++){
                if (ops[i].identificacao == vet[j].identificacao){
                    salvo = j;
                    break;
                }
            }
            printf("%s %d\n", vet[salvo].nome, vet[salvo].nHoras);
        }
        if (ops[i].tipo == 2){
            for( j = 0; j < N; j++){
                if (strcmp(ops[i].nome, vet[j].nome) == 0){
                    salvo = j;
                }
            }
            salarioBruto = 0;
            salarioBruto = vet[salvo].nHoras * vet[salvo].salarioHora;
            printf("%d %.2Lf\n", vet[salvo].identificacao, salarioBruto);
        }
        if (ops[i].tipo == 3){
            for (j = 0; j < N; j++){
                if (ops[i].identificacao == vet[j].identificacao){
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
            desconto = (fator * salarioBruto) - acerto;
            //salario liquido (salario bruto - desconte)
            salarioLiq = salarioBruto - desconto;
            
            printf("%s %.2Lf %.2Lf\n", vet[salvo].nome, desconto, salarioLiq);
        }
        /*if (contaM > 0){
            printf("\n");
            contaM-=1;
        }*/
    }
    return 0;
}