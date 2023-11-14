#include <stdio.h>
#include <string.h>


int romanoParaDecimal();
void decimalParaRomano();
int valorRomano(char);



int main(){
    
    int N, i, tipo;
    int totalRomano = 0, romano = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++){
        scanf("%d ", &tipo);
        if (tipo == 1){
            //lê um número romano
            totalRomano += romanoParaDecimal();
        }
        if (tipo == 2){
            //lê um número decimal
            decimalParaRomano();
        }
    }

    printf("%d", totalRomano);

    return 0;
}

void decimalParaRomano(){
    int valoresDecimais[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* simbolosRomanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int numero = 0;
    char nroRomano[100];

    scanf("%d", &numero);

    for (int i = 0; i < 13; i++){
        while(numero >= valoresDecimais[i]){
            numero -= valoresDecimais[i];
            strcat(nroRomano, simbolosRomanos[i]);
        }
    }

    printf("%s\n", nroRomano);
    nroRomano[0] = '\0';
}

int romanoParaDecimal(){
    char romano[100];   
    int i = 0;
    char letra;
    int numLetra;
    int total = 0;

    scanf("%s", romano);

    letra = romano[i];
    numLetra = valorRomano(letra);

    while (letra != '\0'){
        if (romano[i+1] != '\0'){
            if (numLetra < valorRomano(romano[i+1])){
                total += (valorRomano(romano[i+1]) - numLetra);
                i++;
            }
            else{
                total += numLetra;
            }
        }
        else{
            total += numLetra;
        }
        i++;
        letra = romano[i];
        numLetra = valorRomano(letra);
    }
    
    printf("%d\n", total);

    return total;
}

int valorRomano(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}