typedef struct{
    int linhas, colunas;
    char **mat;
} Matriz;

char** aloca_matriz (int linhas, int colunas);
void preenche_matriz (int linhas, int colunas, char **mat);
void mostra_matriz (int linhas, int colunas, char **mat);
void desaloca_matriz (int linhas, char** mat);