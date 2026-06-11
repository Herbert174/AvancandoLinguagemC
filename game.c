#include <stdio.h>
#include <string.h>

void abertura(){
    printf("******************\n");
    printf("* Jogo da forca  *\n");
    printf("******************\n");
}

void chuta(char chutes[26], int* tentativas){/* para a função reconhecer que esta sendo passado o 
                                             endereço da memoria a ser utilizado*/
    char chute;
    printf("\nEscolha uma letra: ");
    scanf(" %c", &chute); //utilizar o espaço antes do %c para o codigo não rodar duplicado, ignorar o enter

    chutes[(*tentativas)] = chute; //(*variavel) para acessar o valor do endereço da memoria
    (*tentativas)++;
}

int jachutou(char letra, char chutes[26], int tentativas){
    int achou = 0;  
    for (int j = 0; j < tentativas; j++)
        {
        if(chutes[j] == letra)
            {
            achou = 1;
            break;
            }
        }
    return achou;
}

void desenhaforca(char palavrasecreta[20], char chutes[26], int tentativas){
    for (int i = 0; i < strlen(palavrasecreta); i++)
        {
        int achou = jachutou(palavrasecreta[i], chutes, tentativas);
        if(achou)
            {
            printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
                }
        }
}

void escolhepalavrasecreta(char palavrasecreta[20]){
    sprintf(palavrasecreta, "MELANCIA"); //atribui uma string a um array
    //printf("%s", palavrasecreta); //%s para imprimir um array
}

int main(){
    char palavrasecreta[20];
    int acertou = 0;
    int enforcou = 0;
    char chutes[26]; //Um array por essencia já é um ponteiro por isso não precisa do & para
                     //parar ele por uma função
    int tentativas = 0;

    escolhepalavrasecreta(palavrasecreta);
    abertura();

    do{
    desenhaforca(palavrasecreta, chutes, tentativas);
    printf("\n");
    
    chuta(chutes, &tentativas); //& pega o endereço da memoria reservada para a variavel
    //tentativas++;             //usar essa ferramenta pode ser util para utilizar a mesma
                                //variavel em escopos diferentes
    } while (!acertou && !enforcou);
    
    
}