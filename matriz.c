#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

char** aloca_matriz (int linhas, int colunas){
    char **mat;
    int i;

    mat = (char**) malloc(linhas * sizeof(char*));
    if(mat == NULL){
        printf("Erro na alocação dinâmica");
        exit(1);
    }

    for(i = 0; i < linhas; i++){
        mat[i] = (char*) malloc(colunas * sizeof(char));
        if(mat[i] == NULL){
            printf("Erro na alocação dinâmica");
            exit(1);
        }
    }

    return mat;
}

void preenche_matriz (int linhas, int colunas, char **mat){
    int i, j, k, tamFrase;
    char frase[linhas*colunas];
    k = 0;

    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    tamFrase = strlen(frase);
    
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            while(k < tamFrase && frase[k] == ' '){
                k++;
            }
            if(k < tamFrase){
                mat[i][j] = frase[k];
                k++;
            }
            else {
                mat[i][j] = '-';
            }
        }
    }
}

void mostra_matriz (int linhas, int colunas, char **mat){
    int i, j;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

void desaloca_matriz (int linhas, char** mat){
    int i;

    for(i = 0; i < linhas; i++){
        free(mat[i]);
    }
    free(mat);
}
