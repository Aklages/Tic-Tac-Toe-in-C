#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void init(char table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = ' ';
        }
    }
}

void table(char table[3][3])
{
    int cont = 1;
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%d-[%c]\t",cont, table[i][j]);
            cont++;
        }
    }
    printf("\n\n");
}

int play(char table[3][3], int move, int plays)
{
    int x, y, z;
    char s;
    if(plays % 2 == 0){
        s = 'X';
    }
    else{
        s = 'O';
    }
    move -= 1;
    x = move / 3;
    y = move % 3;

    if(table[x][y] == ' ')
    {
        table[x][y] = s;
        return ++plays;
    }
    else{
        system("cls");
        printf("Jogada inválida\n");
        printf("Presione 0 e de enter para continuar: ");
        scanf("%d", &z);
        return plays;
    }
}

int win(char tab[3][3], int plays)
{
    char s;

    if(plays % 2 == 0){
        s = 'X';
    }
    else{
        s = 'O';
    }
    if ((tab[0][0] == s && tab[0][1] == s && tab[0][2] == s) || (tab[1][0] == s && tab[1][1] == s && tab[1][2] == s) || (tab[2][0] == s && tab[2][1] == s && tab[2][2] == s)){
        return 1;
    }
    else if ((tab[0][0] == s && tab[1][0] == s && tab[2][0] == s) || (tab[0][1] == s && tab[1][1] == s && tab[2][1] == s) || (tab[0][2] == s && tab[1][2] == s && tab[2][2] == s)){
        return 1;
    }
    else if ((tab[0][0] == s && tab[1][1] == s && tab[2][2] == s) || (tab[0][2] == s && tab[1][1] == s && tab[2][0] == s)){
        return 1;
    }
    return 0;
}

int check(char tab[3][3], int plays)
{
    int op;
    if(win(tab, plays)){
        if(plays % 2 == 0){
            system("cls");
            table(tab);
            printf("Jogador 1 ganhou! Parabens!\n");
            printf("Digite 0 para encerrar: ");
            scanf("%d", &op);
            return 0;
        }
        else{
            system("cls");
            table(tab);
            printf("Jogador 2 ganhou! Parabens!\n");
            printf("Digite 0 para encerrar: ");
            scanf("%d", &op);
            return 0;
        }
    }
    else if(plays == 9){
        system("cls");
        printf("Resultado final:\n");
        table(tab);
        printf("Deu velha :(\n\n");
        printf("Digite 0 para encerrar: ");
        scanf("%d", &op);
        return 0;
    }
    return 1;
}

int main()
{
    int game = 1, move = 0, plays = 0, mode;
    char tab[3][3];

    system("cls");
    init(tab);
    printf("Bem vindo ao jogo do velha!\n");
    printf("Escolha o modo de jogo:\n");
    printf("1- Modo 2 players\n");
    printf("2- Enfrentar a IA maligna do dede\n");
    printf("Opcao: ");
    scanf("%d", &mode);
    system("cls");

    while (game)
    {
        if(mode == 1){
            printf("Jogada numero %d\n", plays + 1);        
            printf("Vez do jogador %d\n", plays % 2 + 1);
            table(tab);
            printf("Escolha sua jogada, digite a casa que deseja marcar usando 1 a 9: ");
            scanf("%d", &move);
            plays = play(tab, move, plays);
            game = check(tab, plays);
            system("cls");
        }
        else{
            printf("ainda em produção...\n");
            game = 0;
        }
    }
    return 0;
}
