#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    
    // - Grupo composto pelos alunos Renan Lopes - (97370) e Thiago Ferreira - (98893)

    // Considerações para a correção:
    
    // - Neste arquivo está contido o código para o cálculo de multiplicação de matrizes pelo método de multiplicação rápida.

    // - Para casos mais básicos (até matrizes de ordem n = 6) foi usado o método tradicional de multiplicação de matrizes 
    // - Para matrizes de oredem maior do que n = 6 o método rápido de multiplicação é aplicado
    
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


    // - Aqui estão descritas os protótipos das funções básicas:

    // - Função que desaloca a memória usada para guardar uma matriz
    void liberaMemoria(long int** matriz, int linhas);

    // - Função que lê os elementos de uma determinada matriz
    void leMatriz(long int** matriz, int numLinhas);

    // - Função que imprime os elementos de uma determinada matriz
    void imprimeMatriz(long int** mat, int numLinhas);

    // - Função que, uma vez especificado um vetor de ponteiros de ponteiros, aloca um vetor de ponteiros de inteiro para cada posição do
    //   primeiro vetor.
    void autoAlocMatriz(long int** alocarMatriz, int numlinhas);

    //- Função que reagrupa as 4 matrizes finais que compõem a matriz resultante da multiplicação (C)
    void juntarMatriz(long int** matrizC, long int** matrizC1, long int** matrizC2, long int** matrizC3, long int** matrizC4, int n);

    // - Função  que divide a matriz A em 4 matrizes de ordem n/2
    void divideMatrizA(long int** matrizA, long int** matA1, long int** matA2, long int** matA3, long int** matA4, int n);

    // - Função que divide a matriz B em 4 matrizes de ordem n/2
    void divideMatrizB(long int** matrizB, long int** matB1, long int** matB2, long int** matB3, long int** matB4, int n);

    // - Função que desaloca a memória das matrizes principais, A, B e C.
    void valgrindZero(long int** matrizA, long int** matrizB, long int** matrizC, int n);

    // - Função que realiza a operação de somar duas matrizes
    void somaMatrizes(long int **matrizX, long int **matrizY, long int **matrizW, int n, char tipo);

    // - Função que realiza a operação de multiplicar matrizes de ordem menor que n = 6
    void multiplicarMatrizes(long int** matrizX, long int** matrizY, long int** matrizW, int n);

    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    // - A seguir estão os protótipos das funções que calculam as matrizes intermediárias do método rápido de multiplicação de matrizes
    // - Funções que calculam de M1 até M7
    void calculoMatrizM1(long int **matrizR1, long int **matrizR2, long int **matrizM1, long int **matrizA1, long int **matrizA4, long int **matrizB1, long int **matrizB4, int n);
    void calculoMatrizM2(long int **matrizR1, long int **matrizM2, long int **matrizA3, long int **matrizA4, long int **matrizB1, int n);
    void calculoMatrizM3(long int **matrizR1, long int **matrizM3, long int **matrizA1, long int **matrizB2, long int **matrizB4, int n);
    void calculoMatrizM4(long int **matrizR1, long int **matrizM4, long int **matrizA4, long int **matrizB1, long int **matrizB3, int n);
    void calculoMatrizM5(long int **matrizR1, long int **matrizM5, long int **matrizA1, long int **matrizA2, long int **matrizB4, int n);
    void calculoMatrizM6(long int **matrizR1, long int **matrizR2, long int **matrizM6, long int **matrizA1, long int **matrizA3, long int **matrizB1, long int **matrizB2, int n);
    void calculoMatrizM7(long int **matrizR1, long int **matrizR2, long int **matrizM7, long int **matrizA2, long int **matrizA4, long int **matrizB3, long int **matrizB4, int n);
    
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    // - Funções que calculam C1, C2, C3 e C4.
    void calculaMatrizC1(long int **matrizR1, long int **matrizR2, long int **matrizC1, long int **matrizM1, long int **matrizM4, long int **matrizM5, long int **matrizM7, int n);
    void calculaMatrizC2(long int **matrizC2, long int **matrizM3, long int **matrizM5, int n);
    void calculaMatrizC3(long int **matrizC3, long int **matrizM2, long int **matrizM4, int n);
    void calculaMatrizC4(long int **matrizR1, long int **matrizR2, long int **matrizC4, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM6, int n);
    // - Função que realiza a chamada de todas as funções anteriores das 4 matrizes.
    void calcularMatrizC(long int **matrizR1, long int **matrizR2, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM4, long int **matrizM5, long int **matrizM6, long int **matrizM7, long int **matrizC1,  long int **matrizC2,  long int **matrizC3,  long int **matrizC4, int n);
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    // - Funcão principal. Ela quem dita a ordem de todas as chamadas das funções e integra o resultado
    void calcular(long int ** matrizA, long int ** matrizB, long int ** matrizC, int n);


int main(){
    
    // - Lê a ordem das matrizes
    int n=0;
	scanf("%d", &n); 
    int metade = n/2;

    
    // - Aloca matrizes bases a serem lidas (A e B)
    long int **matrizA = (long int**) malloc(n * sizeof(long int*));
    autoAlocMatriz(matrizA, n);
    long int **matrizB = (long int**) malloc(n * sizeof(long int*));
    autoAlocMatriz(matrizB, n);
    long int **matrizC = (long int**) malloc(n * sizeof(long int*));
    autoAlocMatriz(matrizC, n);

    // - Le matrizes A e B   
    leMatriz(matrizA, n);
    leMatriz(matrizB, n);

    // - Chama a função que orquestra toda a operação    
    calcular(matrizA, matrizB, matrizC, n);

    // - Imprime a matriz resultante das operações (Matriz C)
    imprimeMatriz(matrizC, n);

    // - Desaloca o espaço das matrizes na memória
    valgrindZero(matrizA, matrizB, matrizC, n);
        
    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// - Abaixo estão todas as funções cujo funcionamento foi descrito no início deste arquivo

void autoAlocMatriz(long int** alocarMatriz, int numlinhas){
    for (int i = 0; i < numlinhas; i++){
        alocarMatriz[i] = (long int*) malloc(numlinhas * sizeof(long int)); 
        for (int j = 0; j < numlinhas; j++){
        // Inicializa os vetores com 0;
            alocarMatriz[i][j] = 0;
        }
    }
}

void juntarMatriz(long int** matrizC, long int** matrizC1, long int** matrizC2, long int** matrizC3, long int** matrizC4, int n){
    int metade = n/2;

    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matrizC[i][j] = matrizC1[i][j];
            matrizC[i][j+metade] = matrizC2[i][j];
            matrizC[i+metade][j] = matrizC3[i][j];
            matrizC[i+metade][j+metade] = matrizC4[i][j];

        }
    }
}

void divideMatrizA(long int** matrizA, long int** matA1, long int** matA2, long int** matA3, long int** matA4, int n){
    int metade = n/2;

    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matA1[i][j] = matrizA[i][j];
        }
    }

    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matA2[i][j-metade] = matrizA[i][j];                
        }
    }

    for(int i= metade; i < n; i++){
        for(int j= 0; j < metade; j++){
            matA3[i-metade][j] = matrizA[i][j];
        }
    }

    for (int i = metade; i < n ; i++){
        for(int j = metade; j< n; j++){
            matA4[i-metade][j-metade] = matrizA[i][j];
        }
    }
}

void divideMatrizB(long int** matrizB, long int** matB1, long int** matB2, long int** matB3, long int** matB4, int n){
    int metade = n/2;

    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matB1[i][j] = matrizB[i][j];
        }
    }

    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matB2[i][j-metade] = matrizB[i][j];                
        }
    }

    for(int i= metade; i < n; i++){
        for(int j= 0; j < metade; j++){
            matB3[i-metade][j] = matrizB[i][j];
        }
    }

    for (int i = metade; i < n ; i++){
        for(int j = metade; j< n; j++){
            matB4[i-metade][j-metade] = matrizB[i][j];
        }
    }
}

void imprimeMatriz(long int** mat, int numLinhas){
    for (int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numLinhas; j++){
            printf("%ld ", mat[i][j]);
        }
        printf("\n");
    }
}

void leMatriz(long int** matriz, int numLinhas){
    for (int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numLinhas; j++){
            scanf("%ld", &matriz[i][j]);
        }
    }
}

void liberaMemoria(long int** matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}


void valgrindZero(long int** matrizA, long int** matrizB, long int** matrizC, int n){
    liberaMemoria(matrizA, n);
    liberaMemoria(matrizB, n);
    liberaMemoria(matrizC, n);

}

void somaMatrizes(long int **matrizX, long int **matrizY, long int **matrizW, int n, char tipo){

	// TIPO = 0 ; adicao
	// TIPO = 1 ; subtracao

	if (tipo == '0'){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matrizW[i][j] = matrizX[i][j] + matrizY[i][j];
			}
		}
	}
	if (tipo == '1'){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				matrizW[i][j] = matrizX[i][j] - matrizY[i][j];
			}
		}
	}
}

void multiplicarMatrizes(long int** matrizX, long int** matrizY, long int** matrizW, int n){
	
	int multiplicador = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				multiplicador = multiplicador + matrizX[i][k] * matrizY[k][j];
			}
			matrizW[i][j] = multiplicador;
			multiplicador = 0;
		}
	}
}

void calculoMatrizM1(long int **matrizR1, long int **matrizR2, long int **matrizM1, long int **matrizA1, long int **matrizA4, long int **matrizB1, long int **matrizB4, int n){
    somaMatrizes(matrizA1, matrizA4, matrizR1, n/2, '0');
    somaMatrizes(matrizB1, matrizB4, matrizR2, n/2, '0');
    calcular(matrizR1, matrizR2, matrizM1, n/2);
}

void calculoMatrizM2(long int **matrizR1, long int **matrizM2, long int **matrizA3, long int **matrizA4, long int **matrizB1, int n){

	somaMatrizes(matrizA3, matrizA4, matrizR1, n/2, '0');
    calcular(matrizR1, matrizB1, matrizM2, n/2);
}

void calculoMatrizM3(long int **matrizR1, long int **matrizM3, long int **matrizA1, long int **matrizB2, long int **matrizB4, int n){
	
	somaMatrizes(matrizB2, matrizB4, matrizR1, n/2, '1');
    calcular(matrizA1, matrizR1, matrizM3, n/2);

}

void calculoMatrizM4(long int **matrizR1, long int **matrizM4, long int **matrizA4, long int **matrizB1, long int **matrizB3, int n){
	
	somaMatrizes(matrizB3, matrizB1, matrizR1, n/2, '1');
    calcular(matrizA4, matrizR1, matrizM4, n/2);
}

void calculoMatrizM5(long int **matrizR1, long int **matrizM5, long int **matrizA1, long int **matrizA2, long int **matrizB4, int n){

	somaMatrizes(matrizA1, matrizA2, matrizR1, n/2, '0');
    calcular(matrizR1, matrizB4, matrizM5, n/2);

}

void calculoMatrizM6(long int **matrizR1, long int **matrizR2, long int **matrizM6, long int **matrizA1, long int **matrizA3, long int **matrizB1, long int **matrizB2, int n){
	
	somaMatrizes(matrizA3, matrizA1, matrizR1, n/2, '1');    
	somaMatrizes(matrizB1, matrizB2, matrizR2, n/2, '0');
    calcular(matrizR1, matrizR2, matrizM6, n/2);
}

void calculoMatrizM7(long int **matrizR1, long int **matrizR2, long int **matrizM7, long int **matrizA2, long int **matrizA4, long int **matrizB3, long int **matrizB4, int n){
	
	somaMatrizes(matrizA2, matrizA4, matrizR1, n/2, '1');
	somaMatrizes(matrizB3, matrizB4, matrizR2, n/2, '0');
    calcular(matrizR1, matrizR2, matrizM7, n/2);

}

void calculaMatrizC1(long int **matrizR1, long int **matrizR2, long int **matrizC1, long int **matrizM1, long int **matrizM4, long int **matrizM5, long int **matrizM7, int n){
	// C11 = M1 + M4 − M5 + M7

	somaMatrizes(matrizM1, matrizM4, matrizR1, n/2, '0');
	somaMatrizes(matrizR1, matrizM5, matrizR2, n/2, '1');
	somaMatrizes(matrizR2, matrizM7, matrizC1, n/2, '0');

}

void calculaMatrizC2(long int **matrizC2, long int **matrizM3, long int **matrizM5, int n){
	// C12 = M3 + M5
	somaMatrizes(matrizM3, matrizM5, matrizC2, n/2, '0');
}

void calculaMatrizC3(long int **matrizC3, long int **matrizM2, long int **matrizM4, int n){
	// C21 = M2 + M4
	somaMatrizes(matrizM2, matrizM4, matrizC3, n/2, '0');
}

void calculaMatrizC4(long int **matrizR1, long int **matrizR2, long int **matrizC4, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM6, int n){
	// C22 = M1 − M2 + M3 + M6

	somaMatrizes(matrizM1, matrizM2, matrizR1, n/2, '1');
	somaMatrizes(matrizM3, matrizM6, matrizR2, n/2, '0');
	somaMatrizes(matrizR1, matrizR2, matrizC4, n/2, '0');
}

void calcularMatrizC(long int **matrizR1, long int **matrizR2, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM4, long int **matrizM5, long int **matrizM6, long int **matrizM7, long int **matrizC1,  long int **matrizC2,  long int **matrizC3,  long int **matrizC4, int n){

    int metade = n/2;

    calculaMatrizC1(matrizR1, matrizR2, matrizC1, matrizM1, matrizM4, matrizM5, matrizM7, metade);
    calculaMatrizC2(matrizC2, matrizM3, matrizM5, metade);
    calculaMatrizC3(matrizC3, matrizM2, matrizM4, metade);
    calculaMatrizC4(matrizR1, matrizR2, matrizC4, matrizM1, matrizM2, matrizM3, matrizM6, metade);

}


void calcular(long int ** matrizA, long int ** matrizB, long int ** matrizC, int n){

    int metade = n/2;   

    // SE A MATRIZ RESULTANTE DAS OPERAÇÕES FOR DE ORDEM IMPAR, ADICIONA UMA 
    // COLUNA E LINHA A MAIS.
    if (n%2 != 0){
        // ALOCA A, B E C AUX COM ORDEM N+1
        long int **matrizAN = (long int**)malloc((n+1) * sizeof(long int*)); 
        autoAlocMatriz(matrizAN, (n+1));
        long int **matrizBN = (long int**)malloc((n+1) * sizeof(long int*)); 
        autoAlocMatriz(matrizBN, (n+1));
        long int **matrizCN = (long int**)malloc((n+1) * sizeof(long int*)); 
        autoAlocMatriz(matrizCN, (n+1));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrizAN[i][j] = matrizA[i][j];
                matrizBN[i][j] = matrizB[i][j];
            }
        }

        calcular(matrizAN, matrizBN, matrizCN, n+1);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrizA[i][j] = matrizAN[i][j];
                matrizB[i][j] = matrizBN[i][j];
                matrizC[i][j] = matrizCN[i][j];
            }
        }

        // LIBERAR AS MATRIZES AUX
        liberaMemoria(matrizAN, n+1);
        liberaMemoria(matrizBN, n+1);
        liberaMemoria(matrizCN, n+1);

    }
    else{

        if (n <= 6){
            multiplicarMatrizes(matrizA, matrizB, matrizC, n);
            return;
        }
        else{

            // ------- ALOCAR MATRIZES --------

            // MATRIZES DE A
            long int **matA1 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matA1, metade);
            long int **matA2 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matA2, metade);
            long int **matA3 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matA3, metade);
            long int **matA4 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matA4, metade);
            // MATRIZES DE B
            long int **matB1 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matB1, metade);
            long int **matB2 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matB2, metade);
            long int **matB3 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matB3, metade);
            long int **matB4 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matB4, metade);
            // MATRIZES M
            long int **matrizM1 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM1, metade);
            long int **matrizM2 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM2, metade);
            long int **matrizM3 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM3, metade);
            long int **matrizM4 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM4, metade);
            long int **matrizM5 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM5, metade);
            long int **matrizM6 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM6, metade);
            long int **matrizM7 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizM7, metade);  
            // MATRIZES C
            long int **matrizC1 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizC1, metade);
            long int **matrizC2 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizC2, metade);
            long int **matrizC3 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizC3, metade);
            long int **matrizC4 = (long int**) malloc(metade * sizeof(long int*));
            autoAlocMatriz(matrizC4, metade);

            // DIVIDIR AS MATRIZES EM 4 PARTES
            divideMatrizA(matrizA, matA1, matA2, matA3, matA4, n);
            divideMatrizB(matrizB, matB1, matB2, matB3, matB4, n);
            


            
            long int **matrizR1 = (long int**)malloc(metade * sizeof(long int*)); 
            autoAlocMatriz(matrizR1, metade);
            long int **matrizR2 = (long int**)malloc(metade * sizeof(long int*)); 
            autoAlocMatriz(matrizR2, metade);
            
            calculoMatrizM1(matrizR1, matrizR2, matrizM1, matA1, matA4, matB1, matB4, n);
            calculoMatrizM2(matrizR1, matrizM2, matA3, matA4, matB1, n);
            calculoMatrizM3(matrizR1, matrizM3, matA1, matB2, matB4, n);
            calculoMatrizM4(matrizR1, matrizM4, matA4, matB1, matB3, n);
            calculoMatrizM5(matrizR1, matrizM5, matA1, matA2, matB4, n);
            calculoMatrizM6(matrizR1, matrizR2, matrizM6, matA1, matA3, matB1, matB2, n);
            calculoMatrizM7(matrizR1, matrizR2, matrizM7, matA2, matA4, matB3, matB4, n);

            //calcularMatrizM(matrizR1, matrizR2, matrizM1, matrizM2, matrizM3, matrizM4, matrizM5, matrizM6, matrizM7, matA1, matA2, matA3, matA4, matB1, matB2, matB3, matB4, n);

            calculaMatrizC1(matrizR1, matrizR2, matrizC1, matrizM1, matrizM4, matrizM5, matrizM7, n);
            calculaMatrizC2(matrizC2, matrizM3, matrizM5, n);
            calculaMatrizC3(matrizC3, matrizM2, matrizM4, n);
            calculaMatrizC4(matrizR1, matrizR2, matrizC4, matrizM1, matrizM2, matrizM3, matrizM6, n);
            
            juntarMatriz(matrizC, matrizC1, matrizC2, matrizC3, matrizC4, n);


            // ------- DESALOCAR MATRIZES --------

            // Liberar memoria matrizes de A
            liberaMemoria(matA1, metade);
            liberaMemoria(matA2, metade);
            liberaMemoria(matA3, metade);
            liberaMemoria(matA4, metade);
            // Liberar memoria matrizes de B
            liberaMemoria(matB1, metade);
            liberaMemoria(matB2, metade);
            liberaMemoria(matB3, metade);
            liberaMemoria(matB4, metade);
            // Liberar memoria matrizes de M
            liberaMemoria(matrizM1, metade);
            liberaMemoria(matrizM2, metade);
            liberaMemoria(matrizM3, metade);
            liberaMemoria(matrizM4, metade);
            liberaMemoria(matrizM5, metade);
            liberaMemoria(matrizM6, metade);
            liberaMemoria(matrizM7, metade);

            liberaMemoria(matrizC1, metade);
            liberaMemoria(matrizC2, metade);
            liberaMemoria(matrizC3, metade);
            liberaMemoria(matrizC4, metade);

            liberaMemoria(matrizR1, metade);
            liberaMemoria(matrizR2, metade);
        }
    }
}


