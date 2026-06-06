#include <stdio.h>

void calcula(int* c){  /* para a função reconhecer que esta sendo passado o endereço da memoria
                           a ser utilizado*/
    printf("calcula %d %d\n", (*c), c);
    (*c)++;            //(*variavel) para acessar o valor do endereço da memoria
    printf("calcula %d %d\n", (*c), c);
}

void main(){
    int c = 10;

    printf("main %d %d\n", c, &c);//& pega o endereço da memoria reservada para a variavel
    calcula(&c);                  //usar essa ferramenta pode ser util para utilizar a mesma
    printf("main %d %d\n", c, &c);//variavel em escopos diferentes
}