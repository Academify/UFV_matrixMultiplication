#include <stdio.h>
#include <stdlib.h>

    void divideMatriz(int** mat, int n);
    void autoAlocMatriz(long int** alocarMatriz, int numlinhas);
    void divideMatriz2(int** mat, int** matA, int indice, int metade, int n);
    void imprimeMatriz(long int** matriz, int numLinhas);
    void liberaMemoria(long int** matriz, int linhas);
    
int main(){

    int n;
    printf("Tô aq1");
    scanf("%d", &n);
    printf("Tô aq");

    printf("%d",n);

    int **mat = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        mat[i] = (long int*) malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat[i][j] = 0;
        }
        
    }

    divideMatriz(mat, n);
    liberaMemoria(mat, n);
    

    return 0;
}

void divideMatriz(int** mat, int n){
    int metade = n/2;

    int **matA1 = (int**) malloc(metade * sizeof(int*));
    autoAlocMatriz(matA1, metade);

    int **matA2 = (int**) malloc(metade * sizeof(int*));
    autoAlocMatriz(matA2, metade);

    int **matA3 = (int**) malloc(metade * sizeof(int*));
    autoAlocMatriz(matA3, metade);

    int **matA4 = (int**) malloc(metade * sizeof(int*));
    autoAlocMatriz(matA4, metade);

    divideMatriz2(mat, matA1, 1, metade, n);
    divideMatriz2(mat, matA2, 2, metade, n);
    divideMatriz2(mat, matA3, 3, metade, n);
    divideMatriz2(mat, matA1, 4, metade, n);

    imprimeMatriz(matA1, metade);
    imprimeMatriz(matA2, metade);
    imprimeMatriz(matA3, metade);
    imprimeMatriz(matA4, metade);

    liberaMemoria(matA1, metade);
    liberaMemoria(matA2, metade);
    liberaMemoria(matA3, metade);
    liberaMemoria(matA4, metade);
    
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

void divideMatriz2(int** mat, int** matA, int indice, int metade, int n){
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
    		printf("%d ", matriz[i][j]);
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