#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

void pesquisa_horizontal(int linhas, int colunas, char **mat, char *busca) {
    int i, j, k;

    for(i=0;i<linhas;i++){
        for(j=0;j<=colunas - strlen(busca);j++){
            k = 0;
            while(k < strlen(busca) && mat[i][j+k] == busca[k]){
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia horizontal direta [%d][%d] ate [%d]][%d] com a busca: %s\n", i,j,i,k-1,busca);
            }
        }
    }

}

void pesquisa_vertical(int linhas, int colunas, char **mat, char *busca){
    int i,j,k;

    for(j=0;j<colunas;j++){
        for(i=0;i<=linhas - strlen(busca);i++){
            k=0;
            while(k<strlen(busca) && mat[i+k][j] == busca[k]){
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia vertical direta [%d][%d] ate [%d][%d] com a busca: %s\n", i,j,i,k-1,busca);
            }
        }
    }
}

void pesquisa_diagonal(int linhas, int colunas, char **mat, char *busca){
    int i,j,k;

    for(i=0;i<=linhas-strlen(busca);i++){
        for(j=0;j<=colunas-strlen(busca);j++){
            k=0;
            while(k<strlen(busca) && mat[i+k][j+k] == busca[k]){
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia diagonal direta [%d][%d] ate [%d][%d] com a busca: %s\n", i,j,i+k-1,j+k-1,busca); 
            }
        }
    }
}

void pesquisa_horizontal_reversa(int linhas, int colunas, char **mat, char *busca){
    int i,j,k;

    for(i=0;i<linhas;i++){
        for(j=colunas-1;j>=strlen(busca)-1;j--){
            k = 0;
            while(k < strlen(busca) && mat[i][j-k] == busca[k]) {
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia horizontal reversa [%d][%d] ate [%d][%d] com a busca: %s\n", i,j,i,j-k+1,busca);
            }
        }
    }
}

void pesquisa_vertical_reversa(int linhas, int colunas, char **mat, char *busca){
    int i,j,k;

    for(j=0;j<colunas;j++){
        for(i=linhas-1;i>=strlen(busca) - 1;i--){
            k = 0;
            while(k<strlen(busca) && mat[i-k][j] == busca[k]){
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia na vertical reversa [%d][%d] ate [%d][%d] com a busca: %s\n", i,j,i-k+1,j,busca);
            }
        }
    }
}

void pesquisa_diagonal_reversa(int linhas, int colunas, char **mat, char *busca){
    int i,j,k;

    for(i=linhas-1;i>=strlen(busca)-1;i--){
        for(j=colunas-1;j>=strlen(busca)-1;j--){
            k=0;
            while(k<strlen(busca) && mat[i-k][j-k] == busca[k]){
                k++;
            }
            if(k == strlen(busca)){
                printf("Ocorrencia na diagonal reversa [%d][%d] ate [%d][%d] com a busca: %s\n", i,j,i-k+1,j-k+1, busca);
            }
        }
    }
}

void direcoes(int linhas, int colunas, char **mat, char *busca){
    pesquisa_horizontal(linhas,colunas,mat,busca);
    pesquisa_horizontal_reversa(linhas,colunas,mat,busca);
    pesquisa_vertical(linhas,colunas,mat,busca);
    pesquisa_vertical_reversa(linhas,colunas,mat,busca);
    pesquisa_diagonal(linhas,colunas,mat,busca);
    pesquisa_diagonal_reversa(linhas,colunas,mat,busca);
}

void um_caractere(int linhas, int colunas, char **mat, char *busca){
    int i,j;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            if(mat[i][j] == busca[0]){
                printf("Ocorrencia na posicao [%d][%d] com a busca: %s\n", i,j,busca);
            }
        }
    }
}

void ocorrencias(int linhas, int colunas, char **mat){
    char busca[linhas*colunas];
    int i,j, k;
    char tecla;
    
    do{
        printf("Digite a Busca: ");
        scanf(" %[^\n]", busca);

        if(strlen(busca)==1){
            um_caractere(linhas,colunas,mat,busca);
        }
        else if(strlen(busca)>1){
            direcoes(linhas,colunas,mat,busca);
        }

        printf("Você quer continuar (s/n)? ");
        scanf(" %c", &tecla);

    } while(tecla == 's');
}   


void jogo(){
    Matriz matriz;

    printf("Tamanho das linhas: ");
    scanf("%d", &matriz.linhas);
    printf("Tamanho das colunas: ");
    scanf("%d", &matriz.colunas);

    matriz.mat = aloca_matriz(matriz.linhas, matriz.colunas);
    preenche_matriz(matriz.linhas, matriz.colunas, matriz.mat);
    mostra_matriz(matriz.linhas, matriz.colunas, matriz.mat);

    ocorrencias(matriz.linhas, matriz.colunas, matriz.mat);

    desaloca_matriz(matriz.linhas, matriz.mat);
}

int main(){

    jogo();

    return 0;
}