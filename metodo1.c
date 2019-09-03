#include <stdio.h>
#include <stdlib.h>
    
int main(){
  int mat1x, mat1y, mat2x, mat2y;

  // Descrição:

  // mat1x - Número de linhas da primeira matriz
  // mat1y - Número de colunas da primeira matriz
  // mat2x - Número de linhas da segunda matriz
  // mat2y - Número de colunas da segunda matriz


  printf("Informe a ordem da primeira matriz (ex: 2 x 2): \n");
  scanf("%d%d", &mat1x, &mat1y);

  printf("Informe a ordem da segunda matriz (ex: 2 x 2): \n");
  scanf("%d%d", &mat2x, &mat2y);

  
  if (validaOperacao(mat1y, mat2x)){
    // Aloca a matriz 1 (ixj)
    // Aloca a matriz 2 (mxn)
    // Aloca a matriz 3 (ixn)

    int **matriz1 = (int**)malloc(mat1x * sizeof(int*)); // Alocou um vetor de ponteiros onde em cada índice será alocado um vetor

    for (int i = 0; i < mat1x; i++){
      matriz1[i] = (int*) malloc(mat1y * sizeof(int)); // Alocou os vetores de inteiro
      for (int j = 0; j < mat1y; j++){
        matriz1[i][j] = 0; // Inicializa os vetores com 0;
      }
    }

    int **matriz2 = (int**)malloc(mat2x * sizeof(int*));

    for (int i = 0; i < mat2x; i++){
      matriz2[i] = (int*) malloc(mat2y * sizeof(int));
      for (int j = 0; j < mat2y; j++){
        matriz2[i][j] = 0;
      }
      
    }

    int **matriz3 = (int**) malloc(mat1x * sizeof(int*));

    for (int i = 0; i < mat1x; i++){
      matriz3[i] = (int*) malloc(mat2y * sizeof(int));
      for (int j = 0; j < mat2y; j++){
        matriz3[i][j] = 0;
      }
    }
    
    multiplicarMatrizes(matriz1, matriz2, matriz3);

  }else{
    printf("A operação não pode ser realizada pois o número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz");
  }
  


  return 0;
}

int validaOperacao(int j, int m){
  if (j == m){
    return 1;
  }else{
    return 0;
  }
}

void multiplicarMatrizes(int** matriz1, int** matriz2, int** matriz3){
  //Fazer a função de multiplicar aqui
}