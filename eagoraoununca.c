#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------------------------------------------

    // Considerações:
    
    // - Precisa desalocar as matrizes alocadas no método que divide a matriz principal.
    // - Talvez você queira fazer algumas alterações no meu código pra vc entender melhor. Fique a vontade!
    
//---------------------------------------------------------------------------------------------------------------

    void liberaMemoria(long int** matriz, int linhas);
    void leMatriz(long int** matriz, int numLinhas);
    void imprimeMatriz(long int** mat, int numLinhas);
    void autoAlocMatriz(long int** alocarMatriz, int numlinhas);
    void juntarMatriz(long int** matrizC, long int** matrizC1, long int** matrizC2, long int** matrizC3, long int** matrizC4, int n);
    void divideMatrizA(long int** mat, long int** matA1, long int** matA2, long int** matA3, long int** matA4, int n);
    void divideMatrizB(long int** mat, long int** matB1, long int** matB2, long int** matB3, long int** matB4, int n);
    void valgrindZero(long int** matrizA, long int** matrizB, long int** matrizC, int n);

    void somaMatrizes(long int **matrizX, long int **matrizY, long int **matrizW, int n, char tipo);
    void multiplicarMatrizes(long int** matrizX, long int** matrizY, long int** matrizW, int n);

    void calculoMatrizM1(long int **matrizM1, long int **matrizA1, long int **matrizA4, long int **matrizB1, long int **matrizB4, int n);
    void calculoMatrizM2(long int **matrizM2, long int **matrizA3, long int **matrizA4, long int **matrizB1, int n);
    void calculoMatrizM3(long int **matrizM3, long int **matrizA1, long int **matrizB2, long int **matrizB4, int n);
    void calculoMatrizM4(long int **matrizM4, long int **matrizA4, long int **matrizB1, long int **matrizB3, int n);
    void calculoMatrizM5(long int **matrizM5, long int **matrizA1, long int **matrizA2, long int **matrizB4, int n);
    void calculoMatrizM6(long int **matrizM6, long int **matrizA1, long int **matrizA3, long int **matrizB1, long int **matrizB2, int n);
    void calculoMatrizM7(long int **matrizM7, long int **matrizA2, long int **matrizA4, long int **matrizB3, long int **matrizB4, int n);

    void calculaMatrizC1(long int **matrizC1, long int **matrizM1, long int **matrizM4, long int **matrizM5, long int **matrizM7, int n);
    void calculaMatrizC2(long int **matrizC2, long int **matrizM3, long int **matrizM5, int n);
    void calculaMatrizC3(long int **matrizC3, long int **matrizM2, long int **matrizM4, int n);
    void calculaMatrizC4(long int **matrizC4, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM6, int n);


int DEBUG_MODE = 1;

int main(){
    
    // Lê a ordem das matrizes
    int n=0;
	scanf("%d", &n); 
    int metade = n/2;

    if (n%2 == 0){
        // Aloca matrizes bases a serem lidas
        long int **matrizA = (long int**) malloc(n * sizeof(long int*));
        autoAlocMatriz(matrizA, n);
        long int **matrizB = (long int**) malloc(n * sizeof(long int*));
        autoAlocMatriz(matrizB, n);
        long int **matrizC = (long int**) malloc(n * sizeof(long int*));
        autoAlocMatriz(matrizC, n);

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

        // Le matrizes A e B   
        leMatriz(matrizA, n);
        leMatriz(matrizB, n);

        if (DEBUG_MODE == 1){
            printf("--------MATRIZ A--------\n");
            imprimeMatriz(matrizA,n);
            printf("--------MATRIZ B--------\n");
            imprimeMatriz(matrizB, n);
        }

        

        divideMatrizA(matrizA, matA1, matA2, matA3, matA4, n);
        divideMatrizB(matrizB, matB1, matB2, matB3, matB4, n);


        // CALCULAR M
        calculoMatrizM1(matrizM1, matA1, matA4, matB1, matB4, metade);
        calculoMatrizM2(matrizM2, matA3, matA4, matB1, metade);
        calculoMatrizM3(matrizM3, matA1, matB2, matB4, metade);
        calculoMatrizM4(matrizM4, matA4, matB1, matB3, metade);
        calculoMatrizM5(matrizM5, matA1, matA2, matB4, metade);
        calculoMatrizM6(matrizM6, matA1, matA3, matB1, matB2, metade);
        calculoMatrizM7(matrizM7, matA2, matA4, matB3, matB4, metade);
        

        // CALCULAR C
        calculaMatrizC1(matrizC1, matrizM1, matrizM4, matrizM5, matrizM7, metade);
        calculaMatrizC2(matrizC2, matrizM3, matrizM5, metade);
        calculaMatrizC3(matrizC3, matrizM2, matrizM4, metade);
        calculaMatrizC4(matrizC4, matrizM1, matrizM2, matrizM3, matrizM6, metade);

        imprimeMatriz(matrizC1, metade);
        imprimeMatriz(matrizC2, metade);
        imprimeMatriz(matrizC3, metade);
        imprimeMatriz(matrizC4, metade);

        juntarMatriz(matrizC, matrizC1, matrizC2, matrizC3, matrizC4, n);

        valgrindZero(matrizA, matrizB, matrizC, n);

        liberaMemoria(matA1, metade);
        liberaMemoria(matA2, metade);
        liberaMemoria(matA3, metade);
        liberaMemoria(matA4, metade);

        liberaMemoria(matB1, metade);
        liberaMemoria(matB2, metade);
        liberaMemoria(matB3, metade);
        liberaMemoria(matB4, metade);

        liberaMemoria(matrizC1, metade);
        liberaMemoria(matrizC2, metade);
        liberaMemoria(matrizC3, metade);
        liberaMemoria(matrizC4, metade);

        liberaMemoria(matrizM1, metade);
        liberaMemoria(matrizM2, metade);
        liberaMemoria(matrizM3, metade);
        liberaMemoria(matrizM4, metade);
        liberaMemoria(matrizM5, metade);
        liberaMemoria(matrizM6, metade);
        liberaMemoria(matrizM7, metade);
        
    }else{

    }
    
    return 0;
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

    imprimeMatriz(matrizC, n);

}

void divideMatrizA(long int** mat, long int** matA1, long int** matA2, long int** matA3, long int** matA4, int n){
    int metade = n/2;

    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matA1[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matA2[i][j-metade] = mat[i][j];                
        }
    }

    for(int i= metade; i < n; i++){
        for(int j= 0; j < metade; j++){
            matA3[i-metade][j] = mat[i][j];
        }
    }

    for (int i = metade; i < n ; i++){
        for(int j = metade; j< n; j++){
            matA4[i-metade][j-metade] = mat[i][j];
        }
    }


    if (DEBUG_MODE == 1){
        printf("--------DIVISOES DE A--------\n");
        printf("---A1---\n");
        imprimeMatriz(matA1, metade);
        printf("---A2---\n");
        imprimeMatriz(matA2, metade);
        printf("---A3---\n");
        imprimeMatriz(matA3, metade);
        printf("---A4---\n");
        imprimeMatriz(matA4, metade);
    }
}

void divideMatrizB(long int** mat, long int** matB1, long int** matB2, long int** matB3, long int** matB4, int n){
    int metade = n/2;

    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matB1[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matB2[i][j-metade] = mat[i][j];                
        }
    }

    for(int i= metade; i < n; i++){
        for(int j= 0; j < metade; j++){
            matB3[i-metade][j] = mat[i][j];
        }
    }

    for (int i = metade; i < n ; i++){
        for(int j = metade; j< n; j++){
            matB4[i-metade][j-metade] = mat[i][j];
        }
    }


    if (DEBUG_MODE == 1){
        printf("--------DIVISOES DE B--------\n");
        printf("---B1---\n");
        imprimeMatriz(matB1, metade);
        printf("---B2---\n");
        imprimeMatriz(matB2, metade);
        printf("---B3---\n");
        imprimeMatriz(matB3, metade);
        printf("---B4---\n");
        imprimeMatriz(matB4, metade);
    }
}

void imprimeMatriz(long int** mat, int numLinhas){
    for (int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numLinhas; j++){
            printf("%ld ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
	else{
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

void calculoMatrizM1(long int **matrizM1, long int **matrizA1, long int **matrizA4, long int **matrizB1, long int **matrizB4, int n){
	// matrizM1 = (A1 + A4 )*(B1 + B4)

	// matrizR1 e o resultante da primeira adicao 
	// matrizR2 e o resultante da segunda adicao 
	// matrizM1 e o resultante da multiplicação 
  
    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA1, matrizA4, matrizR1, n, '0');
	somaMatrizes(matrizB1, matrizB4, matrizR2, n, '0');
	multiplicarMatrizes(matrizR1, matrizR2, matrizM1, n);

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculoMatrizM2(long int **matrizM2, long int **matrizA3, long int **matrizA4, long int **matrizB1, int n){
	// matrizM2 = (A21 + A22)*B11

	// matrizR1 e o resultante da adicao 
	// matrizM2 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizA3, matrizA4, matrizR1, n, '0');
	multiplicarMatrizes(matrizR1, matrizB1, matrizM2, n);

	liberaMemoria(matrizR1, n);
}

void calculoMatrizM3(long int **matrizM3, long int **matrizA1, long int **matrizB2, long int **matrizB4, int n){
	// matrizM3 = A11*(B12 − B22)

	// matrizR1 e o resultante da subtracao
	// matrizM3 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizB2, matrizB4, matrizR1, n, '1');
	multiplicarMatrizes(matrizA1, matrizR1, matrizM3, n);

	liberaMemoria(matrizR1, n);

}

void calculoMatrizM4(long int **matrizM4, long int **matrizA4, long int **matrizB1, long int **matrizB3, int n){
	// matrizM4 = A22*(B21 − B11)

	// matrizR1 e o resultante da subtracao
	// matrizM3 e o resultante da multiplicação 

    long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizB3, matrizB1, matrizR1, n, '1');
	multiplicarMatrizes(matrizA4, matrizR1, matrizM4, n);

	liberaMemoria(matrizR1, n);

}

void calculoMatrizM5(long int **matrizM5, long int **matrizA1, long int **matrizA2, long int **matrizB4, int n){
	// matrizM5 = (A11 + A12)*B22

	// matrizR1 e o resultante da adicao
	// matrizM5 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);

	somaMatrizes(matrizA1, matrizA2, matrizR1, n, '0');
	multiplicarMatrizes(matrizR1, matrizB4, matrizM5, n);

	liberaMemoria(matrizR1, n);

}

void calculoMatrizM6(long int **matrizM6, long int **matrizA1, long int **matrizA3, long int **matrizB1, long int **matrizB2, int n){
	// matrizM6 = (A21 − A11)*(B11 + B12)

	// matrizR1 e o resultante da subtracao
	// matrizR2 e o resultante da adicao
	// matrizM6 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA3, matrizA1, matrizR1, n, '1');    
	somaMatrizes(matrizB1, matrizB2, matrizR2, n, '0');
	multiplicarMatrizes(matrizR1, matrizR2, matrizM6, n);
	
    liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculoMatrizM7(long int **matrizM7, long int **matrizA2, long int **matrizA4, long int **matrizB3, long int **matrizB4, int n){
	// matrizM7 = (A12 − A22)*(B21 + B22)

	// matrizR1 e o resultante da subtracao
	// matrizR2 e o resultante da adicao
	// matrizM7 e o resultante da multiplicação 

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizA2, matrizA4, matrizR1, n, '1');
	somaMatrizes(matrizB3, matrizB4, matrizR2, n, '0');

	multiplicarMatrizes(matrizR1, matrizR2, matrizM7, n);

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);

}

void calculaMatrizC1(long int **matrizC1, long int **matrizM1, long int **matrizM4, long int **matrizM5, long int **matrizM7, int n){
	// C11 = M1 + M4 − M5 + M7

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizM1, matrizM4, matrizR1, n, '0');
    //imprimeMatriz(matrizR1, n);
	somaMatrizes(matrizR1, matrizM5, matrizR2, n, '1');
    //imprimeMatriz(matrizR2, n);
	somaMatrizes(matrizR2, matrizM7, matrizC1, n, '0');

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);
}

void calculaMatrizC2(long int **matrizC2, long int **matrizM3, long int **matrizM5, int n){
	// C12 = M3 + M5

	somaMatrizes(matrizM3, matrizM5, matrizC2, n, '0');
}

void calculaMatrizC3(long int **matrizC3, long int **matrizM2, long int **matrizM4, int n){
	// C21 = M2 + M4

	somaMatrizes(matrizM2, matrizM4, matrizC3, n, '0');
}

void calculaMatrizC4(long int **matrizC4, long int **matrizM1, long int **matrizM2, long int **matrizM3, long int **matrizM6, int n){
	// C22 = M1 − M2 + M3 + M6

	long int **matrizR1 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR1, n);
	long int **matrizR2 = (long int**)malloc(n * sizeof(long int*)); 
	autoAlocMatriz(matrizR2, n);

	somaMatrizes(matrizM1, matrizM2, matrizR1, n, '1');
	somaMatrizes(matrizM3, matrizM6, matrizR2, n, '0');
	somaMatrizes(matrizR1, matrizR2, matrizC4, n, '0');

	liberaMemoria(matrizR1, n);
	liberaMemoria(matrizR2, n);
}
