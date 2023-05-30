

#include <stdio.h>

int main(void) {

float MatrizU[3][3];

float MatrizL[3][3];

int MP[3][1];

// Prencher as matrizes

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

scanf("%f", &MatrizU[i][j]);

if (i == j) {

MatrizL[i][j] = 1;

}

if (j > i) {

MatrizL[i][j] = 0;

}

}

}

printf("\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 1; j++) {

scanf("%d", &MP[i][j]);

}

}

printf("\n");

printf("Matriz do sistema:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

printf(" %.3f ", MatrizU[i][j]);

}

printf("\n");

}

// Primeiro Passo

int menor =

10000000; // recebe um numero grande afim de achar um menor na comparação

int posiMenor = 0;

int MatrizInt = 0;

for (int i = 0; i < 3; i++) {

MatrizInt = (int)MatrizU[i][0];

if (abs(MatrizInt) < menor) {

menor = MatrizU[i][0];

posiMenor = i;

}

}

float pivo = MatrizU[posiMenor][0];

float mult;

for (int i = posiMenor + 1; i < 3; i++) {

mult = MatrizU[i][0] / (pivo);

// printf("%.f\n", mult);

MatrizL[i][0] = mult;

for (int j = 0; j < 3; j++) {

MatrizU[i][j] = MatrizU[i][j] - mult * MatrizU[0][j];

}

}

printf("\n");

printf("Determinar primeira coluna e primeira linha de L/U:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

printf(" %.3f ", MatrizU[i][j]);

}

printf("\n");

}

// Caso o valor da linha 3 seja maior que na dois, troca as linhas de lugar

int cont;

float valor1;

float valor2;

/*

if (MatrizU[1][1] < 0) {

valor1 = MatrizU[1][1] * -1;

}

if (MatrizU[2][1] < 0) {

valor2 = MatrizU[2][1] * -1;

}

if (valor1 < valor2) {

float valorAux = 0;

int ValorAuxP = 0;

ValorAuxP = MP[1][0];

MP[1][0] = MP[2][0];

MP[2][0] = ValorAuxP;

cont = 1;

for (int j = 0; j < 3; j++) {

valorAux = MatrizU[1][j];

MatrizU[1][j] = MatrizU[2][j];

MatrizU[2][j] = valorAux;

}

}

*/

// Segundo Passo

mult = MatrizU[2][1] / MatrizU[1][1];

MatrizL[2][1] = mult;

for (int j = 0; j < 3; j++) {

MatrizU[2][j] = MatrizU[2][j] - (mult * MatrizU[1][j]);

}

printf("\n");

printf("Determinar segunda coluna e segunda linha de L/U:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

printf(" %.3f ", MatrizU[i][j]);

}

printf("\n");

}

// Passo 3

// Matriz U

printf("Matriz U:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

printf(" %.3f ", MatrizU[i][j]);

}

printf("\n");

}

// Matriz U

printf("Matriz L:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 3; j++) {

printf(" %.3f ", MatrizL[i][j]);

}

printf("\n");

}

printf("Matriz P:\n");

for (int i = 0; i < 3; i++) {

for (int j = 0; j < 1; j++) {

printf(" %d ", MP[i][j]);

}

printf("\n");

}

printf("Calcular a solução do sistema Ly = B\n");

float M_B[3][1];

M_B[0][0] = MP[0][0];

M_B[1][0] = MP[1][0];

M_B[2][0] = MP[2][0];

float y1 = (M_B[0][0] / MatrizL[0][0]);

float y2 = (M_B[1][0] - (MatrizL[1][0] * y1));

float y3 = (M_B[2][0] - (MatrizL[2][0] * y1 + (MatrizL[2][1] * y2)));

printf("L1.y1 = %.f \n", y1);

printf("L1.y2 = %.2f \n", y2);

printf("L1.y3 = %.2f \n", y3);

float x3 = (y3) / (MatrizU[2][2]);

float x2 = (y2 - MatrizU[1][2] * x3) / (MatrizU[1][1]);

float x1 = (y1 - (MatrizU[0][1] * x2 + MatrizU[0][2] * x3)) / (MatrizU[0][0]);

printf("\n");

printf("U1.x1 = %.3f \n", x1);

printf("U1.x2 = %.3f \n", x2);

printf("U1.x3 = %.3f \n", x3);

return 0;

}