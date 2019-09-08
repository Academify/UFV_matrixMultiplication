<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
    
int main(){
  int n;

  // Descrição:

  // mat1x - Número de linhas da primeira matriz
  // mat1y - Número de colunas da primeira matriz
  // mat2x - Número de linhas da segunda matriz
  // mat2y - Número de colunas da segunda matriz

  scanf("%d", &n); // Lê a ordem das matrizes
  printf("\n");


    long int **matriz1 = (long int**)malloc(n * sizeof(long int*)); // Alocou um vetor de ponteiros onde em cada índice será alocado um vetor

    for (int i = 0; i < n; i++){
      matriz1[i] = (long int*) malloc(n * sizeof(long int)); // Alocou os vetores de inteiro
      for (int j = 0; j < n; j++){
        matriz1[i][j] = 0; // Inicializa os vetores com 0;
      }
    }

    long int **matriz2 = (long int**)malloc(n * sizeof(long int*));

    for (int i = 0; i < n; i++){
      matriz2[i] = (long int*) malloc(n * sizeof(long int));
      for (int j = 0; j < n; j++){
        matriz2[i][j] = 0;
      }
      
    }

    long int **matriz3 = (long int**) malloc(n * sizeof(long int*));

    for (int i = 0; i < n; i++){
      matriz3[i] = (long int*) malloc(n * sizeof(long int));
      for (int j = 0; j < n; j++){
        matriz3[i][j] = 0;
      }
    }

    leMatriz(matriz1, n);
    leMatriz(matriz2, n);

    imprimeMatriz(matriz1, n); // Retirar isso
    imprimeMatriz(matriz2, n); // Retirar isso

    
    multiplicarMatrizes(matriz1, matriz2, matriz3, n);

    imprimeMatriz(matriz3, n); // Imprime a matriz resultante


    liberaMemoria(matriz1, n);
    liberaMemoria(matriz2, n);
    liberaMemoria(matriz3, n);
  

  return 0;
}

// Função inultilizada por conta da minha descoberta que as matrizes são quadradas de mesma ordem

/* int validaOperacao(int j, int m){
  if (j == m){
    return 1;
  }else{
    return 0;
  }
} */

void leMatriz(long int** matriz, long int n){
  for (int i = 0; i < n; i++){
    for(int j=0; j < n; j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  printf("\n");
}

void imprimeMatriz(long int** matriz, long int n){
  for (int i = 0; i < n; i++){
    for(int j=0; j < n; j++){
      printf("%d", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void multiplicarMatrizes(long int** matriz1, long int** matriz2, long int** matriz3, int n){
  //Fazer a função de multiplicar aqui
  printf("Chegou até aqui\n");
}

void liberaMemoria(long int** matriz, long int* linhas){
  for (int i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
}

=======
#include <stdio.h>
#include <stdlib.h>


// PROTOTIPOS
void leMatriz(int** matriz, int numLinhas);
void imprimeMatriz(int** matriz, int numLinhas);
void multiplicarMatrizes(int** matriz_1, int** matriz_2, int** matriz_3, int numLinhas);
void liberaMemoria(int** matriz, int linhas);
void autoAlocMAtriz(int** alocarMatriz, int numlinhas);


int main(int argc, char *argv[]){

	int DEBUG_MODE = 0;
	if (argc > 1) DEBUG_MODE = 1;


	int n;


	scanf("%d", &n); // Lê a ordem das matrizes
	printf("\n");

	// Alocação das matrizes a seram usadas
    int **matriz1 = (int**)malloc(n * sizeof(int*)); 
	autoAlocMAtriz(matriz1, n);

    int **matriz2 = (int**)malloc(n * sizeof(int*));
	autoAlocMAtriz(matriz2, n);

    int **matriz3 = (int**) malloc(n * sizeof(int*));
	autoAlocMAtriz(matriz3, n);


	// Le as matrizes 1 e 2
    leMatriz(matriz1, n);
    leMatriz(matriz2, n);
	
	// DEBUG MODE
	if (DEBUG_MODE == 1){
		printf("Matriz 1\n");
		imprimeMatriz(matriz1, n);
		printf("Matriz 2\n");
		imprimeMatriz(matriz2, n);
	}

	// Realiza a multiplicação das matrizes
    multiplicarMatrizes(matriz1, matriz2, matriz3, n);

	// Imprime a matriz resultante da multiplicação
    imprimeMatriz(matriz3, n); 

	// Desaloca as matrizes usadas
    liberaMemoria(matriz1, n);
    liberaMemoria(matriz2, n);
    liberaMemoria(matriz3, n);
  

  return 0;
}


void leMatriz(int** matriz, int numLinhas){
	for (int i = 0; i < numLinhas; i++){
    	for(int j = 0; j < numLinhas; j++){
      		scanf("%d", &matriz[i][j]);
    	}
  	}
}

void imprimeMatriz(int** matriz, int numLinhas){
  	for (int i = 0; i < numLinhas; i++){
		for(int j = 0; j < numLinhas; j++){
    		printf("%d ", matriz[i][j]);
    	}
    	printf("\n");
  	}
  	printf("\n");
}

void multiplicarMatrizes(int** matriz_1, int** matriz_2, int** matriz_3, int numLinhas){
	
	int multiplicador = 0;
	for (int i = 0; i < numLinhas; i++){
		for (int j = 0; j < numLinhas; j++){
			for (int k = 0; k < numLinhas; k++){
				multiplicador = multiplicador + matriz_1[i][k] * matriz_2[k][j];
			}

			matriz_3[i][j] = multiplicador;
			multiplicador = 0;
		}
	}
}

void liberaMemoria(int** matriz, int linhas){
  for (int i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
}

void autoAlocMAtriz(int** alocarMatriz, int numlinhas){

	for (int i = 0; i < numlinhas; i++){
		alocarMatriz[i] = (int*) malloc(numlinhas * sizeof(int)); 
    	for (int j = 0; j < numlinhas; j++){
    		// Inicializa os vetores com 0;
			alocarMatriz[i][j] = 0;
    	}
    }
}
>>>>>>> 85dbab0236d8a0a177ddfafdfed58ef0cc06c057
