#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "game.h" //Chamando header file (arquivo onde as funções são declaradas)


void abertura(){
    printf("******************\n");
    printf("* Jogo da forca  *\n");
    printf("******************\n");
}

void chuta(char chutes[26], int* chutesdados){/* para a função reconhecer que esta sendo passado o 
                                             endereço da memoria a ser utilizado*/
    char chute;
    printf("\nEscolha uma letra: ");
    scanf(" %c", &chute); //utilizar o espaço antes do %c para o codigo não rodar duplicado, ignorar o enter

    chutes[(*chutesdados)] = chute; //(*variavel) para acessar o valor do endereço da memoria
    (*chutesdados)++;
}

int jachutou(char letra, char chutes[26], int chutesdados){
    int achou = 0;  
    for (int j = 0; j < chutesdados; j++)
        {
        if(chutes[j] == letra)
            {
            achou = 1;
            break;
            }
        }
    return achou;
}

void desenhaforca(char palavrasecreta[TAMANHO_PALAVRA], char chutes[26], int chutesdados){
    int erros = chuteserros(palavrasecreta, chutes, chutesdados);
    printf("  _______      \n");
    printf(" |/      |     \n"); //Usar aspas simples para atribuir caracter com if ternario
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '), 
    (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (erros >= 3 ? '\\' : ' '), 
    (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++)
        {
        int achou = jachutou(palavrasecreta[i], chutes, chutesdados);
        if(achou)
            {
            printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
                }
        }
}

void adicionapalavra(){
    char resposta;
    printf("Voce deseja adicionar uma nova palavra? (S/N)\n");
    scanf(" %c", &resposta);

    if(resposta == 'S'){
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+"); //r+ para ter permissão de leitura e escrita

        if(f == 0){
            printf("Desculpe banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qntd;
        fscanf(f, "%d", &qntd); //lê a primeira linha do arquivo e guarda na variavel
        qntd++;

        fseek(f, 0, SEEK_SET); //Posiciona o ponteiro para a posição 0 novamente
        fprintf(f, "%d", qntd); //Substitui o antigo numero pelo atual

        fseek(f, 0, SEEK_END); //Posiciona o ponteiro para o final do arquivo
        fprintf(f, "\n%s", novapalavra); //manda quebra de linha e 
                                         //escreve a string presente no novapalavra
        fclose(f);
    }                                    

}

void escolhepalavrasecreta(char palavrasecreta[TAMANHO_PALAVRA]){
    //sprintf(palavrasecreta, "MELANCIA"); //atribui uma string a um array
    //printf("%s", palavrasecreta); //%s para imprimir um array
    FILE* f;
    f = fopen("palavras.txt", "r"); //abre o arquivo com permissão de leitura

    if(f == 0){ //retorno 0 do fopen significa erro para abrir o arquivo
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1); //exit maior que 0 para o programa
    }

    int qntdpalavras;
    fscanf(f, "%d", &qntdpalavras);

    srand(time(0));
    int randomico = rand() % qntdpalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int ganhou(char palavrasecreta[TAMANHO_PALAVRA], char chutes[26], int chutesdados){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i], chutes, chutesdados)){
            return 0;
        }
    }
    return 1;
}

int chuteserros(char palavrasecreta[TAMANHO_PALAVRA], char chutes[26], int chutesdados){
    int erros = 0;
        for(int i = 0; i < chutesdados; i++){
            int existe = 0;
            for(int j = 0; j < strlen(palavrasecreta); j++){
                if(chutes[i] == palavrasecreta[j]){
                    existe = 1;
                    break;
                }
            }
            if(!existe) 
                erros++;
        }
    return erros;
}

int enforcou(char palavrasecreta[TAMANHO_PALAVRA], char chutes[26], int chutesdados){
    return chuteserros(palavrasecreta, chutes, chutesdados) >= 5;
}

int main(){
    char palavrasecreta[TAMANHO_PALAVRA];
    char chutes[26]; //Um array por essencia já é um ponteiro por isso não precisa do & para
                     //parar ele por uma função
    int chutesdados = 0;

    escolhepalavrasecreta(palavrasecreta);
    abertura();

    do{
    desenhaforca(palavrasecreta, chutes, chutesdados);
    printf("\n");
    
    chuta(chutes, &chutesdados); //& pega o endereço da memoria reservada para a variavel
    //tentativas++;             //usar essa ferramenta pode ser util para utilizar a mesma
                                //variavel em escopos diferentes
    } while (!ganhou(palavrasecreta, chutes, chutesdados) && !enforcou(palavrasecreta, chutes, chutesdados));
    
    if(ganhou(palavrasecreta, chutes, chutesdados)){
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }else{
        printf("Voce perdeu\n");
        printf("A palavra era %s", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    //adicionapalavra();
}