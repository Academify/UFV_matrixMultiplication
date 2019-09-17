#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    
    // - Grupo composto pelos alunos Renan Lopes - (97370) e Thiago Ferreira - (98893)

    // Considerações para a correção:
    
    // - Este arquivo contém o código para o método tradicional de multiplicação de matrizes
// ------------------------------------------------------------------------------------------------------------------------------------//

// - Aqui estão descritos os protótipos das funções usadas no método em questão

// - A função abaixo é responsável por realizar a leitura dos elementos de uma matriz
void leMatriz(long int** matriz, int numLinhas);

// - A função abaixo é responsável por imprimir os elementos de uma matriz
void imprimeMatriz(long int** matriz, int numLinhas);

// - A função abaixo é responsável por realizar o cálculo da multiplicação das matrizes A e B e guarda a resultado na matriz C
void multiplicarMatrizes(long int** matriz_1, long int** matriz_2, long int** matriz_3, int numLinhas);

// - A função abaixo é responsável por desalocar a memória alocada para uma determinada matriz
void liberaMemoria(long int** matriz, int linhas);

// - Função que, uma vez especificado um vetor de ponteiros de ponteiros, aloca um vetor de ponteiros de inteiro para cada posição do
//   primeiro vetor.
void autoAlocMatriz(long int** alocarMatriz, int numlinhas);

// - Função main ---------------------------------------------------------------------------------------------------------------------//

int main(int argc, char *argv[]){

	int n; // - Variável que armazena a ordem das matrizes

	scanf("%d", &n); // Lê a ordem das matrizes
	

	// - Alocação das matrizes a seram usadas
    long int **matriz1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matriz1, n);

    long int **matriz2 = (long int**)malloc(n * sizeof(long int*));
	autoAlocMatriz(matriz2, n);

    long int **matriz3 = (long int**) malloc(n * sizeof(long int*));
	autoAlocMatriz(matriz3, n);


	// Le as matrizes 1 e 2
    leMatriz(matriz1, n);
    leMatriz(matriz2, n);
	

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

// - Abaixo estão todas as funções cujo funcionamento foi descrito no início deste arquivo

void leMatriz(long int** matriz, int numLinhas){
	for (int i = 0; i < numLinhas; i++){
    	for(int j = 0; j < numLinhas; j++){
      		scanf("%ld", &matriz[i][j]);
    	}
  	}
}

void imprimeMatriz(long int** matriz, int numLinhas){
  	for (int i = 0; i < numLinhas; i++){
		for(int j = 0; j < numLinhas; j++){
    		printf("%ld ", matriz[i][j]);
    	}
    	printf("\n");
  	}
}

void multiplicarMatrizes(long int** matriz_1, long int** matriz_2, long int** matriz_3, int numLinhas){
	
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

void liberaMemoria(long int** matriz, int linhas){
  for (int i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
}


void autoAlocMatriz(long int** alocarMatriz, int numlinhas){
	for (int i = 0; i < numlinhas; i++){
		alocarMatriz[i] = (long int*) malloc(numlinhas * sizeof(long int)); 
		for (int j = 0; j < numlinhas; j++){
			// Inicializa os vetores com 0;
			alocarMatriz[i][j] = 0;
		}
	}
}
