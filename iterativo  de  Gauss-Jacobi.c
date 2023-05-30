#include <stdio.h>
/*
valor de e :
0.01
valor max de interações : 
10
Digite os valores numericos referentes a função
2 1 2
3 5 -4
Qual a aproximação inicial ?
0 0
*/
int main(void) {
  int k = 0;
  int kMax = 0;
  float x1In, x2In =0;
  float e = 0;
  float Er = 1;
  printf("valor de e :\n");
  scanf("%f", &e);
  printf("valor max de interações : \n");
  scanf("%d", &kMax);
  float x1[kMax];
  float x2[kMax];
  printf("Digite os valores numericos referentes a função\n");
  float Funcao[2][3];
  for (int i =0; i < 2 ; i++){
    for (int j =0; j < 3 ; j++){
         scanf("%f", &Funcao[i][j]);
      }
  }
  printf("Qual a aproximação inicial ?\n");
  scanf("%d %d", &x2In,&x2In);  
  x1[1]=x1In;
  x2[1]=x2In;
  while ((k <= kMax) && (Er > e)){
    k=k+1;
    if(k >= kMax){
      break;
    }
    x1[k+1] = (Funcao[0][2] - (Funcao[0][1] *x2[k]) ) / Funcao[0][0];
    x2[k+1] = (Funcao[1][2] - (Funcao[1][0] *x1[k]) ) / Funcao[1][1];
    x1In = x1[k+1] - x1[k];
    x2In = x2[k+1] - x2[k];
    Er = sqrt(pow(x1In,2)+pow(x2In,2));
    printf("%.3f\n", Er);
    
    
   
  }
  printf("Solução obtida:\n");
  printf("%.3f %.3f\n" , x1[k], x2[k]);
  printf(" Condicao de parada %.4f\n", Er);
  
  
  return 0;
}