//Autor = David Antonio Brocardo 

#include <stdio.h>

double Lagrange(double x, double x1, double x2, double x3,
                              double y1, double y2, double y3) {
  return y1 * (x - x2) * (x - x3) / ((x1 - x2) * (x1 - x3)) +
         y2 * (x - x1) * (x - x3) / ((x2 - x1) * (x2 - x3)) +
         y3 * (x - x1) * (x - x2) / ((x3 - x1) * (x3 - x2));
}

int main() {
    // Declaração das variaveis
  double x = 0;
  double x1 = 0;
  double x2 = 0 ;
  double x3 = 0;
  double y1 = 0;
  double y2 = 0; 
  double y3 = 0;
  
  printf("Entre com os valores de X \n");
  printf(" X0 = ");
  scanf ("%lf", &x1);
  printf(" X1 = ");
  scanf ("%lf", &x2);
  printf(" X2 = ");
  scanf ("%lf", &x3);
   printf("Entre com os valores de P \n");
   printf(" Y0 = ");
  scanf ("%lf" , &y1);
  printf(" Y1 = ");
  scanf ("%lf" , &y2);
  printf(" Y2 = ");
  scanf ("%lf" , &y3);
   printf("Entre com os valor de X que deseja descobrir \n");
  printf(" X = ");
  scanf ("%lf" , &x);
  
  // chama a funcao para o calculo 
  double result = Lagrange(x, x1, x2, x3, y1, y2, y3);
  printf("O  valor do polinomio com  x = %.3lf é de: %.3lf\n", x, result);
  return 0;
}