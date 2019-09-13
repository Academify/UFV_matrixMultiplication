#include <stdio.h>
#include <stdlib.h>

    void divideMatriz(long int** mat, int n);
    void autoAlocMatriz(long int** alocarMatriz, int numlinhas);
    void divideMatriz2(long int** mat, long int** matA, int indice, int metade, int n);
    void imprimeMatriz(long int** matriz, int numLinhas);
    void liberaMemoria(long int** matriz, int linhas);
    void leMatriz(long int** matriz, int numLinhas);
    
int main(int argc, char *argv[]){

    int n=0;

	scanf("%d", &n); // Lê a ordem das matrizes
    
    if(n%2 == 0){
        long int **mat = (long int**) malloc(n * sizeof(long int*));
        for (int i = 0; i < n; i++){
            mat[i] = (long int*) malloc(n * sizeof(long int));
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = 0;
            }
        }

        leMatriz(mat, n);
        printf("Acabou de ler a matriz;;");

        divideMatriz(mat, n);
        liberaMemoria(mat, n);
    }

    return 0;
}

void divideMatriz(long int** mat, int n){
    int metade = n/2;

    //printf("Metade: %d", metade);

    long int **matA1 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA1, metade);
    matA1[1][1] = mat[1][1];
    imprimeMatriz(matA1, metade);
    /* for (int i = 0; i < metade; i++){
        for (int j = 0; j < metade; j++){
            matA1[i][j] = mat[i][j];
        }
    }

    long int **matA2 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA2, metade);
    for (int i = 0; i < metade; i++){
        for (int j = metade; j < n; j++){
            matA2[i][j] = mat[i][j];
        } 
    }

    long int **matA3 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA3, metade);
    for (int i = metade; i < n; i++){
        for (int j = 0; j < metade; j++){
            matA3[i][j] = mat[i][j];
        } 
    }

    long int **matA4 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA4, metade);
    for (int i = metade; i < n; i++){
        for (int j = metade; j < n; j++){
            matA4[i][j] = mat[i][j];
        } 
    }

    // imprimeMatriz(matA1, metade);
    // imprimeMatriz(matA2, metade);
    // imprimeMatriz(matA3, metade);
    // imprimeMatriz(matA4, metade);

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
    liberaMemoria(matA4, metade); */
    
}

void leMatriz(long int** matriz, int numLinhas){
	for (int i = 0; i < numLinhas; i++){
    	for(int j = 0; j < numLinhas; j++){
      		scanf("%ld", &matriz[i][j]);
    	}
  	}
    printf("Acabou o segundo for");
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