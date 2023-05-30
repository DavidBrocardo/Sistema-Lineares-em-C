//Autor = David Antonio Brocardo 

#include <stdio.h>

double Newton(double x, double x1, double x2, double x3, double x4,
                             double y1, double y2, double y3, double y4) {
  double a[4] = {y1, y2, y3, y4};
  double b[3];
  b[0] = (a[1] - a[0]) / (x2 - x1);
  b[1] = ((a[2] - a[1]) / (x3 - x2) - (a[1] - a[0]) / (x2 - x1)) / (x3 - x1);
  b[2] = (((a[3] - a[2]) / (x4 - x3) - (a[2] - a[1]) / (x3 - x2)) / (x4 - x2) -
          ((a[2] - a[1]) / (x3 - x2) - (a[1] - a[0]) / (x2 - x1)) / (x3 - x1)) /
         (x4 - x1);

  return a[0] + b[0] * (x - x1) + b[1] * (x - x1) * (x - x2) +
         b[2] * (x - x1) * (x - x2) * (x - x3);
}

int main() {
  // Declaração de Variaveis 
   double x = 0;
  double x1 = 0;
  double x2 = 0 ;
  double x3 = 0;
  double x4 = 0;
  double y1 = 0;
  double y2 = 0; 
  double y3 = 0;
  double y4 = 0;
  double resultado = 0;
  
  // Entrada de Valores para o Calculo
  printf("Entre com os valores de X \n");
  printf(" X0 = ");
  scanf ("%lf", &x1);
  printf(" X1 = ");
  scanf ("%lf", &x2);
  printf(" X2 = ");
  scanf ("%lf", &x3);
  printf(" X3 = ");
  scanf ("%lf", &x4);
   printf("Entre com os valores de P \n");
   printf(" Y0 = ");
  scanf ("%lf" , &y1);
  printf(" Y1 = ");
  scanf ("%lf" , &y2);
  printf(" Y2 = ");
  scanf ("%lf" , &y3);
  printf(" Y3 = ");
  scanf ("%lf", &y4);
   printf("Entre com os valor de X que deseja descobrir \n");
  printf(" X = ");
  scanf ("%lf" , &x);
 
  // Formula responsavel pelo calulo 
  resultado = Newton(x, x1, x2, x3, x4, y1, y2, y3, y4);

    printf("O  valor do polinomio com  x = %.1lf é de: %.2lf\n", x, resultado);
  return 0;
}