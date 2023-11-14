#include <stdio.h>

int ePalindromo(char*, char*, int, int);

int main(){
    char palavra[2001];
    unsigned int i = 0;
    int tamanho = 0, tamanhoOriginal = 0;
    int maiorP = 0;
    //OBSERVAÇÕES
    //Parece que usará backtracking como no problema das N-Rainhas
    //Por exemplo, começaríamos das duas extremidades e poderíamos iterar do último caractere até o primeiro buscando um
    //caractere igual, se encontrassemos compararíamos os caracteres seguintes (a partir daqui tem que ser igual até o final)
    //se não encontrar, voltaria ao caractere à esquerda anterior e iteraríamos novamente com o segundo caractere à esquerda

    scanf("%s", palavra);

    //descobre o tamanho da palavra lida
    while(palavra[tamanho] != '\0')  
        tamanho++;
    
    tamanho--;
    tamanhoOriginal = tamanho;
    i = 0;
    while (*(palavra+i) != '\0'){
        //Achou duas letra iguais nos opostos do vetor
        //if (*(palavra+i) == *(palavra+tamanho)){    
            //verifica se a partir dessa letra iguais, há um palíndromo
            if (ePalindromo((palavra+0), (palavra+0), i, tamanho)){
                //se é um palíndromo, mas da mesma letra, então o maior é 1
                if (tamanho-i == 0){
                    if (1 > maiorP)
                        maiorP = 1;
                }
                //senão é a diferença
                else{
                    if (((tamanho-i)+1) > maiorP)
                        maiorP = (tamanho-i)+1;
                }
            }
        //}
        //se tamanho chegou em i, reseta o ciclo, começando pela próxima letra da esquerda
        if (i == tamanho){
            i++;
            tamanho = tamanhoOriginal;
        }
        //se não, passa para letra à esquerda da letra à direita
        else{
            tamanho--;
        }
    }

    printf("%d", maiorP);
    return 0;
}

/*
int ePalindromo(char* inicio, char* fim, int posI, int posF){
    while(posI <= posF){
        if (*(inicio+posI) == *(fim+posF)){
            posI++;
            posF--;
        }
        else   
            return 0;
    }
    return 1;
}
*/
int ePalindromo(char *inicio, char *fim, int posI, int posF) {
    if (posI > posF) {
        return 1;
    }

    if (*(inicio + posI) == *(fim + posF)) {
        return ePalindromo(inicio, fim, posI + 1, posF - 1);
    } else {
        return 0;
    }
}
