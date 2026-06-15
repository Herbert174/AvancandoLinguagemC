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

void desenhaforca(char palavrasecreta[20], char chutes[26], int chutesdados){
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

void escolhepalavrasecreta(char palavrasecreta[20]){
    //sprintf(palavrasecreta, "MELANCIA"); //atribui uma string a um array
    //printf("%s", palavrasecreta); //%s para imprimir um array
    FILE* f;
    f = fopen("palavras.txt", "r");

    int qntdpalavras;
    fscanf(f, "%d", &qntdpalavras);

    srand(time(0));
    int randomico = rand() % qntdpalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int ganhou(char palavrasecreta[20], char chutes[26], int chutesdados){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i], chutes, chutesdados)){
            return 0;
        }
    }
    return 1;
}

int enforcou(char palavrasecreta[20], char chutes[26], int chutesdados){
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
    return erros >= 5;
}

int main(){
    char palavrasecreta[20];
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
    
    
}