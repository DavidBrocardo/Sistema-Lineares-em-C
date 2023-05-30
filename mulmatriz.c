#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *arquivo;
/*
Exemplo de Matriz
3 2
2 2
2 3
1 0
4 5
3 1 
2 4
*/
// Funcao responsavel por alocar as matrizes
double **Alocar_matriz_real (int m, int n) {
  double **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */
  if (m < 1 || n < 1) { /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return (NULL);
     }
  /* aloca as linhas da matriz */
  v = (double **) calloc (m, sizeof(double *));	/* Um vetor de m ponteiros para float */
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
      v[i] = (double*) calloc (n, sizeof(double));	/* m vetores de n floats */
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v); /* retorna o ponteiro para a matriz */
}

//Metodo de multiplicao de matrizes classico
void MulM1M2(double **M1, double **M2,double **MR,int l1, int c1, int l2, int c2){
  double aux;
 
  for(int i = 0; i < l1; i++){  
    for( int j = 0;  j < c2; j++){
              
			   for(int x = 0; x < l2; x++) {
				    aux +=  M1[i][x] * M2[x][j];
			     }
         
			   MR[i][j] = aux;
         aux =0;
    }
  }
  
  
}
//Metodo de multiplicao ultilizando a Matriz transposta
void MulM1M2T(double **M1, double **M2T, double **MR, int l1, int c1, int l2, int c2){
  double aux;
 
  for(int i = 0; i < l1; i++){  
    for( int j = 0;  j < c2; j++){
              
			   for(int x = 0; x < l2; x++) {
				    aux +=  M1[i][x] * M2T[x][j];
			     }
         
			   MR[i][j] = aux;
         aux =0;
    }
  }
  
}

// Funcao responsavel por calcular a transposta
void transpostaM2(double **M2, double **M2T, int l2, int c2)
{
  for (int i = 0; i < l2; i++) {
      for (int j = 0; j < c2; j++) {
        M2T[j][i] = M2[i][j];
        }
    }
}
int main( int argc, char *argv[ ] ){
  int c1 = 0, c2 = 0; //Numero de colunas
  int l1 , l2 = 0; //Numero de linhas
  double aux; // Variavel auxilar a multiplicação
  char *metodo;  // armazena o tipo da mult
  // variaveis responsavel pelo calculo do tempo
  float tempo = 0.0;
  clock_t inicio, fim;

  /*     --- INICIO ---    */
    
    l1 = atoi(argv[1]);
    c1 = atoi(argv[2]);
    l2 = atoi(argv[3]);
    c2 = atoi(argv[4]);
     
    metodo = argv[5];   
  /*scanf("%c",&metodo);
  scanf("%d %d %d %d" ,&l1 , &c1, &l2 , &c2);*/
  //printf("Rodou");
  //matrizes  a serem alocadas
  double **Matriz1;
  double **Matriz2;
  double **Matriz2TP;
  double **MResul ;
  // Arquivo para registro de tempo de execução  
    //abre o arquivo de dados 
  if(!(arquivo = fopen("tempoExec.txt","rb+")))
  {
    printf("\nErro : não foi possivel abrir o arquivo de dados\n");
    printf("\nCriando novo arquivo de dados ... \n");
    arquivo= fopen("dados.dat","wb+");
  }
  Matriz1 = Alocar_matriz_real (l1, c1);
  Matriz2 = Alocar_matriz_real (l2, c2);
  Matriz2TP = Alocar_matriz_real (c2, l2);
  MResul = Alocar_matriz_real (l1, c2);
  if(c1 == l2){
    for (int i = 0; i < l1; i++) {
      for (int j = 0; j < c1; j++) {
        //scanf("%lf", &Matriz1[i][j]);
         Matriz1[i][j] = ((double) rand()) / ( double ) RAND_MAX;
      }
    }
    for (int i = 0; i < l2; i++) {
      for (int j = 0; j < c2; j++) {
       // scanf("%lf", &Matriz2[i][j]);
        Matriz2[i][j] = ((double) rand()) / ( double ) RAND_MAX;
      }
    }
    //Chama o calculo classico
if(strcmp(metodo,"c")==0){       
      inicio = clock();
      // aqui está o código que deseja mensurar tempo
      MulM1M2( Matriz1 ,Matriz2, MResul, l1,  c1,  l2,  c2);
      fim = clock();
    }else{
      inicio = clock();
      // aqui está o código que deseja mensurar tempo
      transpostaM2(Matriz2, Matriz2TP,  l2,  c2);
      MulM1M2T( Matriz1 ,Matriz2TP, MResul, l1,  c1,  l2,  c2);
      fim = clock();
    }
      
    // cálculo para apresentação em segundos
    tempo = (float) (((fim - inicio ) + 0.0) / CLOCKS_PER_SEC);
   // fprintf(fp, “ %f\n”,tempo);
    

   // printf("%f\n", tempo);
    
    /*for(int i = 0; i < l1; i++){  
      for( int j = 0;  j < c2; j++){
        printf("%.2lf  ", MResul[i][j]);
        }
      printf("\n");
    }*/
  }else{
    printf("! TAMANHO NAO SUPORTADO !");
  }
 
  



  
  return 0;
}
