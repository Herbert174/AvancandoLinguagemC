#define TAMANHO_PALAVRA 20

void abertura();
void chuta(char chutes[26], int* chutesdados);
int jachutou(char letra, char chutes[26], int chutesdados);
void desenhaforca(char palavrasecreta[20], char chutes[26], int chutesdados);
void escolhepalavrasecreta(char palavrasecreta[20]);
int ganhou(char palavrasecreta[20], char chutes[26], int chutesdados);
int enforcou(char palavrasecreta[20], char chutes[26], int chutesdados);
void adicionapalavra();
int chuteserros(char palavrasecreta[TAMANHO_PALAVRA], char chutes[26], int chutesdados);