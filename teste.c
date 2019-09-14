#include <stdio.h>
#include <stdlib.h>

int DEBUG_MODE = 2;

void divideMatriz(long int** mat, int n);
void autoAlocarMatriz(long int** alocarMatriz, int numlinhas);
void divideMatriz2(long int** mat, long int** matA, int indice, int metade, int n);
void imprimeMatriz(long int** matriz, int numLinhas);
void liberaMemoria(long int** matriz, int linhas);
void leMatriz(long int** matriz, int numLinhas);

void copiarMatriz(long int** matrizA, long int** matrizA11, long int** matrizA12, long int** matrizA21, int n);


int main(int argc, char *argv[]){

    // Lê a ordem das matrizes
    int n = 0;
	scanf("%d", &n);
    int METADE = n/2;
    // Aloca matrizes a serem lidas
    long int **matrizA = (long int**) malloc(n * sizeof(long int*));
    autoAlocarMatriz(matrizA, n);

    long int **matrizB = (long int**) malloc(n * sizeof(long int*));
    autoAlocarMatriz(matrizB, n);

    // Le matrizes A e B
    leMatriz(matrizA, n);
    leMatriz(matrizB, n);



    imprimeMatriz(matrizA, n);
    imprimeMatriz(matrizB, n);

    long int **matrizA11 = (long int**) malloc(METADE * sizeof(long int*));
    autoAlocarMatriz(matrizA11, METADE);

    long int **matrizA12 = (long int**) malloc(METADE * sizeof(long int*));
    autoAlocarMatriz(matrizA12, METADE);

    long int **matrizA21 = (long int**) malloc(METADE * sizeof(long int*));
    autoAlocarMatriz(matrizA21, METADE);


    copiarMatriz(matrizA, matrizA11, matrizA12, matrizA21, n);

    imprimeMatriz(matrizA11, METADE);
    imprimeMatriz(matrizA12, METADE);
    imprimeMatriz(matrizA21, METADE);


    // Libera da Memoria as matrizes A e B
    liberaMemoria(matrizA, n);
    liberaMemoria(matrizB, n);

    liberaMemoria(matrizA11, n);
    liberaMemoria(matrizA12, n);
    liberaMemoria(matrizA21, n);

    return 0;
}




void copiarMatriz(long int** matrizA, long int** matrizA11, long int** matrizA12, long int** matrizA21, int n){
    int metade = n/2;
    int auxMetade = metade;
    int auxMetade2 = metade;
    // ENCONTRAR A11
    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matrizA11[i][j] = matrizA[i][j];
        }
    }

    // ENCONTRAR A21
    auxMetade = metade - 1;
    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matrizA21[i][j] = matrizA[auxMetade][auxMetade2 - 1];
            auxMetade2++;
        }
        auxMetade++;
    }


    // ENCONTRAR A21
    auxMetade = metade;
    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matrizA21[i][j] = matrizA[auxMetade][j];
        }
        auxMetade++;
    }
     

}

/*
void divideMatriz(long int** mat, int n){
    int metade = n/2;

    // Cria matriz
    long int **matA1 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocarMatriz(matA1, metade);

    // Passa os valores para a nova matriz
    for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matA1[i][j] = mat[i][j];
        }
    }


    
    long int **matA2 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocarMatriz(matA2, metade);
    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matA2[i][j] = mat[i][j];
        } 
    }

    long int **matA3 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocarMatriz(matA3, metade);
    for (int i = metade; i < n; i++){
        for (int j = 0; j < metade; j++){
            matA3[i][j] = mat[i][j];
        } 
    }

    long int **matA4 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocarMatriz(matA4, metade);
    for (int i = metade; i < n; i++){
        for (int j = metade; j < n; j++){
            matA4[i][j] = mat[i][j];
        } 
    }

    imprimeMatriz(matA1, metade);
    imprimeMatriz(matA2, metade);
    imprimeMatriz(matA3, metade);
    imprimeMatriz(matA4, metade);

    // divideMatriz2(mat, matA1, 1, metade, n);
    // divideMatriz2(mat, matA2, 2, metade, n);
    // divideMatriz2(mat, matA3, 3, metade, n);
    // divideMatriz2(mat, matA1, 4, metade, n);

    imprimeMatriz(matA1, metade);
    imprimeMatriz(matA2, metade);
    imprimeMatriz(matA3, metade);
    imprimeMatriz(matA4, metade);

    liberaMemoria(matA1, metade);
    liberaMemoria(matA2, metade);
    liberaMemoria(matA3, metade);
    liberaMemoria(matA4, metade); 
    
}

*/

void leMatriz(long int** matriz, int numLinhas){
    for (int i = 0; i < numLinhas; i++){
    	for(int j = 0; j < numLinhas; j++){
      		scanf("%ld", &matriz[i][j]);

            if (DEBUG_MODE == 1){
                printf(" i = %d , j = %d , valor = %ld  \n",i , j, matriz[i][j]);
            }
    	}
  	}
}

void autoAlocarMatriz(long int** alocarMatriz, int numlinhas){
	for (int i = 0; i < numlinhas; i++){
		alocarMatriz[i] = (long int*) malloc(numlinhas * sizeof(long int)); 
		for (int j = 0; j < numlinhas; j++){
			// Inicializa os vetores com 0;
			alocarMatriz[i][j] = 0;
		}
	}
}

void divideMatriz2(long int** mat, long int** matA, int indice, int metade, int n){
    if (indice == 1){
        for (int i = 0; i < metade; i++){
            for (int j = 0; j < metade; j++){
                matA[i][j] = mat[i][j];
            } 
        }
    }else if(indice == 2){
        for (int i = 0; i < metade; i++){
            for (int j = metade; j < n; j++){
                matA[i][j] = mat[i][j];
            } 
        }
    }else if(indice == 3){
        for (int i = metade; i < n; i++){
            for (int j = 0; j < metade; j++){
                matA[i][j] = mat[i][j];
            } 
        }
    }else{
        for (int i = metade; i < n; i++){
            for (int j = metade; j < n; j++){
                matA[i][j] = mat[i][j];
            } 
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

void liberaMemoria(long int** matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}
