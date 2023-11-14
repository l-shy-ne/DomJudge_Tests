#include<stdio.h>
#include<string.h>

typedef struct salarioHaha
{
    char nome[18];
    int identificacao;
    float salarioHora;
    int nHoras;
} salario;


int main(){

    salario empregados[1000];
    int N, M;
    int i, j, contasM;
    int op, identificacao;
    char nome[19];
    float salarioBruto, fator, acerto, desconto, salarioLiquido;

    //freopen("input.txt","r",stdin);//redirects standard input
    //freopen("output.txt","w+",stdout);//redirects standard output

    scanf("%d %d ", &N, &M);

    for (i = 0; i < N; i++){
        scanf("%s %d %f %d", empregados[i].nome, &empregados[i].identificacao, &empregados[i].salarioHora, &empregados[i].nHoras);
    }

    contasM = M-1;
    for (i = 0; i < M; i++){
        scanf("%d ", &op);
        if (op == 1){
            scanf("%d", &identificacao);
            for (j = 0; j < N; j++){
                if (identificacao == empregados[j].identificacao){
                    printf("%s %d", empregados[j].nome, empregados[j].nHoras);
                    if (contasM > 0){
                        printf("\n");
                        contasM--;
                    }
                    break;
                }
            }
        }
        if (op == 2){
            scanf("%s", nome);
            for (j = 0; j < N; j++){
                if (strcmp(nome, empregados[j].nome) == 0){ 
                    //calculo do salario bruto
                    salarioBruto = empregados[j].nHoras * empregados[j].salarioHora;
                    //imprime identificacao e salarioBruto
                    printf("%d %.2f", empregados[j].identificacao, salarioBruto);
                    if (contasM > 0){
                        printf("\n");
                        contasM--;
                    }
                    break;
                }
            }
        }
        if (op == 3){
            scanf("%d", &identificacao);
            for (j = 0; j < N; j++){
                if (identificacao == empregados[j].identificacao){
                    //calculo do salario bruto
                    salarioBruto = empregados[j].nHoras * empregados[j].salarioHora;
                    //calculo do fator e acerto
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
                    //calculo do desconto
                    desconto = (fator * salarioBruto) - acerto;
                    //calculo do salario liquido
                    salarioLiquido = salarioBruto - desconto;
                    printf("%s %.2f %.2f", empregados[j].nome, desconto, salarioLiquido);
                    if (contasM > 0){
                        printf("\n");
                        contasM--;
                    }
                    break;
                }   
            }
        }
    }


    return 0;
}