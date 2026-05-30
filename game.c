#include <stdio.h>
#include <string.h>

int main(){
    char palavrasecreta[20];
    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    sprintf(palavrasecreta, "MELANCIA"); //atribui uma string a um array
    //printf("%s", palavrasecreta); //%s para imprimir um array

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
    
    char chute;
    printf("\nEscolha uma letra: ");
    scanf(" %c", &chute); //utilizar o espaço antes do %c para o codigo não rodar duplicado ignorar o enter

    chutes[tentativas] = chute;
    tentativas++;
    
    } while (!acertou && !enforcou);
    
    
}