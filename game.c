#include <stdio.h>
#include <string.h>

void abertura(){
    printf("******************\n");
    printf("* Jogo da forca  *\n");
    printf("******************\n");
}

int chuta(char chutes[26], int tentativas){
    char chute;
    printf("\nEscolha uma letra: ");
    scanf(" %c", &chute); //utilizar o espaço antes do %c para o codigo não rodar duplicado, ignorar o enter

    chutes[tentativas] = chute;
    tentativas++;
    return tentativas;
}

int main(){
    char palavrasecreta[20];
    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    sprintf(palavrasecreta, "MELANCIA"); //atribui uma string a um array
    //printf("%s", palavrasecreta); //%s para imprimir um array

    abertura();

    do
    {
    for (int i = 0; i < strlen(palavrasecreta); i++)
        {
        int achou = 0;  
        for (int j = 0; j < tentativas; j++)
            {
            if(chutes[j] == palavrasecreta[i])
                {
                achou = 1;
                break;
                }
            }
        if(achou)
            {
            printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
                }
        //printf("%c", palavrasecreta[i]);       
        
        }
    printf("\n");
    
    tentativas = chuta(chutes, tentativas);
    //tentativas++;
    
    } while (!acertou && !enforcou);
    
    
}