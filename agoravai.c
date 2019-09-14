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
    void divideMatriz(long int** mat, int n);

int main(){

    int n=0;

	scanf("%d", &n); // Lê a ordem das matrizes

    if (n%2 == 0){
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
        divideMatriz(mat, n);
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

void divideMatriz(long int** mat, int n){
    int metade = n/2;

    long int **matA1 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA1, metade);
    long int **matA2 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA2, metade);
    long int **matA3 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA3, metade);
    long int **matA4 = (long int**) malloc(metade * sizeof(long int*));
    autoAlocMatriz(matA4, metade);

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