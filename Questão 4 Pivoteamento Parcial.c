

#include <stdio.h>

int main(void) {

float Matriz[3][4];

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

scanf("%f", &Matriz[i][j]);

}

}

printf("\n");

printf("Matriz aumentada do sitema:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

if (j == 3) {

printf(" | ");

}

printf(" %.2f ", Matriz[i][j]);

}

printf("\n");

}

// Achar o maior valor absoluto

printf("Determinar o pivo na primeira coluna\n");

int maior = 0;

int posiMaior = 0;

int MatrizInt = 0;

for (int i = 0; i < 3; i++) {

MatrizInt = (int)Matriz[i][0];

if (abs(MatrizInt) > maior) {

maior = Matriz[i][0];

posiMaior = i;

}

}

float pivo = Matriz[posiMaior][0];

// muda a linha inicial para a a que tem o maior valor

// so vai fazer isso se o valor já não esta no pivo

if (posiMaior != 0) {

int valorAux = 0;

for (int j = 0; j < 4; j++) {

valorAux = Matriz[posiMaior][j];

Matriz[posiMaior][j] = Matriz[0][j];

Matriz[0][j] = valorAux;

}

}

printf("\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

if (j == 3) {

printf(" | ");

}

printf(" %.2f ", Matriz[i][j]);

}

printf("\n");

}

// Contrução de matriz triangular

/*

1 -2 -1 7

4 2 -3 -1

-5 2 1 -15

1 1 1 1

2 1 -1 0

2 2 1 1

*/

printf("\n");

float mult;

for (int i = 1; i < 3; i++) {

mult = Matriz[i][0] / (pivo);

printf("%f",mult);

for (int j = 0; j < 4; j++) {

Matriz[i][j] = Matriz[i][j] - mult * Matriz[0][j];

}

}

printf("\n");

printf("Zerando os elementos abaixo do primeiro pivo \n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

if (j == 3) {

printf(" | ");

}

printf(" %.2f ", Matriz[i][j]);

}

printf("\n");

}

printf("\n");

// Caso o valor da linha 3 seja maior que na dois, troca as linhas de lugar

int cont;

float valor1;

float valor2;

valor1 = Matriz[1][1] ;

valor2 = Matriz[2][1];

if (valor1 < valor2) {

float valorAux = 0;

for (int j = 0; j < 3; j++) {

valorAux = Matriz[1][j];

Matriz[1][j] = Matriz[2][j];

Matriz[2][j] = valorAux;

}

}

pivo = Matriz[1][1];

printf("Pivo %.2f\n", pivo);

printf("\n");

printf("Determinar o pivo na segunda coluna\n");

// Achar o maior valor absoluto

maior = 0;

posiMaior = 0;

MatrizInt = 0;

mult = Matriz[2][1] / (pivo);

for (int j = 0; j < 4; j++) {

Matriz[2][j] = Matriz[2][j] - mult * Matriz[1][j];

}

// muda a linha inicial para a a que tem o maior valor

// so vai fazer isso se o valor já não esta no pivo

if (posiMaior != 0) {

int valorAux = 0;

for (int j = 0; j < 4; j++) {

valorAux = Matriz[posiMaior][j];

Matriz[posiMaior][j] = Matriz[1][j];

Matriz[1][j] = valorAux;

}

}

printf("\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

if (j == 3) {

printf(" | ");

}

printf(" %.2f ", Matriz[i][j]);

}

printf("\n");

}

printf("\n");

mult=0;

for (int i = 2; i < 3; i++) {

mult = Matriz[i][1] / (pivo);

for (int j = 0; j < 4; j++) {

Matriz[i][j] = Matriz[i][j] - mult * Matriz[0][j];

}

}

printf("Zerando os elementos abaixo do segundo pivo \n");

printf("\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 4; j++) {

if (j == 3) {

printf(" | ");

}

printf(" %.2f ", Matriz[i][j]);

}

printf("\n");

}

printf("\n");

printf("Calculo da Solução do Sistema: \n");

float x, y, z;

// Ex: 2z = 4 --> z = 4/2

z = Matriz[2][3] / Matriz[2][2];

// Ex: 2y + 2z = 10 --> y = (10 - 2z)/2

y = (Matriz[1][3] - (Matriz[1][2] * z)) / Matriz[1][1];

// Ex: 5x + 2y + 2z =10 --> x =( 10 -2y -2z )/ 5

x = (Matriz[0][3] - Matriz[0][2] * z - Matriz[0][1] * y) / Matriz[0][0];

printf("\n");

printf("O Resultado da Linha 1 é: \n");

printf("x = %.f\n", x);

printf("O Resultado da Linha 2 é: \n");

printf("y = %.f\n", y);

printf("O Resultado da Linha 3 é: \n");

printf("z = %.f\n", z);

return 0;
}