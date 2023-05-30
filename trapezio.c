// Autor : David Antonio Brocardo 
#include <stdio.h>
#include <math.h>

double Funcaof(double x) {
    // Defina aqui a função a ser integrada
    double f =  pow(x,3) + 2;  // Deve colocar aqui a funcao do exercicio
    return f ;
}

double regraTrapezeio(double a, double b) {
    double h = (b - a) / 2;
    double sum = (Funcaof(a) + Funcaof(b));
     return h * sum;
}

double regraTrapezeioRepetida(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (Funcaof(a) + Funcaof(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += Funcaof(x);
    }

    return h * sum;
}

int main() {
    double a = 1.0;  // limite inferior
    double b = 5.0; // limite superior
    int n = 4;    // número de subintervalos

    printf("Pela Regra do trapezio Simples: \n");
    printf("%.0f\n", regraTrapezeio(a, b));
    printf("Pela Regra do trapezio repetida: \n");
    printf("%.0f\n", regraTrapezeioRepetida(a , b ,n ));
    return 0;
}
