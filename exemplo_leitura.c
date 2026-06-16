int n1, n2;

int sucesso = fscanf("%d %d", &n1, &n2); //fscanf retorna a quantidade de numeros lidos
if(sucesso == 2) {
    printf("Os dois números: %d e %d", n1, n2);
}
else {
    printf("Aconteceu um erro");
}


FILE* f;
char c;

f = fopen("arquivo.txt", "r");
while(!feof(f)) {       //feof(f) verifica se o ponteiro atual do arquivo está apontando para o fim
    c = fgetc(f);       //fgetc para ler um byte, um char, ou mesmo uma struct
    printf("Char %c\n", c);
}