#include <stdio.h>
#include <stdlib.h>
    
// PROTOTIPOS
void leMatriz(long int** matriz, int numLinhas);
void imprimeMatriz(long int** matriz, int numLinhas);
void multiplicarMatrizes(long int** matriz1, long int** matriz2, long int** matriz3, int numLinhas);
void liberaMemoria(long int** matriz, int linhas);
void autoAlocMatriz(long int** alocarMatriz, int numlinhas);


void geradoraDeMatrizes(int n);

int main(int argc, char *argv[]){

    int DEBUG_MODE = 1;

    if (argc > 1) DEBUG_MODE = 1;

    int n;

    scanf("%d", &n); // Lê a ordem das matrizes

    // Alocação das matrizes a seram usadas
    long int **matriz1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matriz1, n);

    long int **matriz2 = (long int**)malloc(n * sizeof(long int*));
	autoAlocMatriz(matriz2, n);

    long int **matriz3 = (long int**) malloc(n * sizeof(long int*));
	autoAlocMatriz(matriz3, n);

    // Le as matrizes 1 e 2
    leMatriz(matriz1, n);
    leMatriz(matriz2, n);

	geradoraDeMatrizes(n);

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
  	printf("\n");
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

void autoAlocMatriz(long int** alocarMatriz, int numLinhas){
	for (int i = 0; i < numLinhas; i++){
		alocarMatriz[i] = (long int*) malloc(numLinhas * sizeof(long int)); 
    for (int j = 0; j < numLinhas; j++){
    	// Inicializa os vetores com 0;
		alocarMatriz[i][j] = 0;
    }
  }
}

// void separaMatrizes(long int** matriz, int numLinhas, char nomeMatriz){
//     int metade = numLinhas/2;

//     long int** nomeMatriz = (long int**)malloc(numLinhas * sizeof(long int*));
//     autoAlocMatriz(nomeMatriz, numLinhas);

//     for (int i = 0; i < metade; i++){
//         for (int j = 0; j < metade; j++){
            
//         }
        
//     }
    
// }


void geradoraDeMatrizes(int n){

	// Alocação das matrizes a seram usadas
    long int **matrizM1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM1, n);

	long int **matrizM2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM2, n);

	long int **matrizM3 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM3, n);

	long int **matrizM4 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM4, n);

	long int **matrizM5 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM5, n);

	long int **matrizM6 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM6, n);

	long int **matrizM7 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizM7, n);

}

void somaMatrizes(long int **matrizA, long int **matrizB, long int **matrizR, int n, char tipo){
	
	// olhar isso depois
	long int matrizC

	// TIPO = 0 ; adicao
	// TIPO = 1 ; subtracao

	if (tipo == '0'){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
			}
		}
	}
	else{
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
			}
		}
	
	}

}


void calculoMatrizM1(){
	// matrizM1 = (A11 + A22 )*(B11 + B22)

	// matrizR1 e o resultante da primeira adicao 
	// matrizR2 e o resultante da segunda adicao 
	// matrizM1 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA11, matrizA22, matrizR1, n);
	somaMatrizes(matrizB11, matrizB22, matrizR2, n);
	multiplicarMatrizes(matrizR1, matrizR2, matrizM1, n, '0');

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculoMatrizM2(){
	// matrizM2 = (A21 + A22)*B11

	// matrizR1 e o resultante da adicao 
	// matrizM2 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizA21, matrizA22, matrizR1, n, '0');
	multiplicarMatrizes(matrizR1, matrizB11, matrizM2, n);

	liberaMemoria(matrizR1, n);
}

void calculoMatrizM3(){
	// matrizM3 = A11*(B12 − B22)

	// matrizR1 e o resultante da subtracao
	// matrizM3 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizB12, matrizB22, matrizR1, n, '1');
	multiplicarMatrizes(matrizA11, matrizR1, matrizM3, n);

	liberaMemoria(matrizR1, n);

}

void calculoMatrizM5(){
	// matrizM5 = (A11 + A12)*B22

	// matrizR1 e o resultante da adicao
	// matrizM5 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizA11, matrizA12, matrizR1, n, '0');
	multiplicarMatrizes(matrizR1, matrizB22, matrizM5, n);

	liberaMemoria(matrizR1, n);

}

void calculoMatrizM6(){
	// matrizM6 = (A21 − A11)*(B11 + B12)

	// matrizR1 e o resultante da subtracao
	// matrizR2 e o resultante da adicao
	// matrizM6 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA21, matrizA11, matrizR1, n, '1');
	somaMatrizes(matrizB11, matrizB12, matrizR2, n, '0');
	multiplicarMatrizes(matrizR1, matrizB22, matrizM6, n);

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculoMatrizM7(){
	// matrizM7 = (A12 − A22)*(B21 + B22)

	// matrizR1 e o resultante da subtracao
	// matrizR2 e o resultante da adicao
	// matrizM7 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA12, matrizA22, matrizR1, n, '1');
	somaMatrizes(matrizB21, matrizB22, matrizR2, n, '0');
	multiplicarMatrizes(matrizR1, matrizB22, matrizM7, n);

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculaMatrizC11(){
	// C11 = M1 + M4 − M5 + M7

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizM1, matrizM4, matrizR1, n, '0');
	somaMatrizes(matrizM5, matrizM7, matrizR2, n, '0');
	somaMatrizes(matrizR1, matrizR2, matrizC11, n, '1');

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);
}

void calculaMatrizC12(){
	// C12 = M3 + M5

	somaMatrizes(matrizM3, matrizM5, matrizC12, n, '0');
}

void calculaMatrizC21(){
	// C21 = M2 + M4

	somaMatrizes(matrizM2, matrizM4, matrizC21, n, '0');
}

void calculaMatrizC22(){
	// C22 = M1 − M2 + M3 + M6

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizM1, matrizM2, matrizR1, n, '1');
	somaMatrizes(matrizM3, matrizM6, matrizR2, n, '0');
	somaMatrizes(matrizR1, matrizR2, matrizC22, n, '0');

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);
}


