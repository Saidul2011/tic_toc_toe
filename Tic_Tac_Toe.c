#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char matrix[3][3];
void initi_matrix(void);
void display_matrix(void);
char check(void);
void player1_moves(void);
void player2_moves(void);


int main(){
    printf("THE TIC-TAC-TOE GAME :\n\n");
    char done=' ';
    initi_matrix();
    do
    {   
        display_matrix();
        player1_moves();

        done=check();
        if (done!=' ')
        {
           break;
        }
        
        display_matrix();
        player2_moves();
        done=check();
        if (done!=' ')
        {
           break;
        }

    } while (done==' ');
    

    display_matrix();
    if(done=='O') printf("Player_1 Win !\n");
    if(done=='X') printf("Player_2 win !\n");
    if(done=='D') printf("Match Draw.");
    
}


void initi_matrix(void){

     for (size_t i = 0; i < 3; i++)
     {
        for (size_t j = 0; j < 3; j++)
        {
            matrix[i][j]=' ';
        }
        
     }
     
}

void display_matrix(void){
    system("cls");
    for (size_t i = 0; i < 3; i++)
    {
        
           printf("%c |%c |%c", matrix[i][0],matrix[i][1],matrix[i][2]);
           if(i!=2) printf("\n--|--|--\n");
    }
    printf("\n");
}

void player1_moves(){
    int x;
    printf("Player_1 enter box number you want choose: ");
    scanf("%d",&x);
    int t=x-1;
    int i=t/3;
    int j=t%3;

    if(matrix[i][j]==' '){
        matrix[i][j]='O';
    }
    else {
    printf("Invalide!\n");

    player1_moves();
    }
}

void player2_moves(){
    int x;
    printf("Player_2 enter box number you want choose: ");
    scanf("%d",&x);
    int t=x-1;
    int i=t/3;
    int j=t%3;

    if(matrix[i][j]==' '){
        matrix[i][j]='X';
    }
    else {
    printf("Invalide!\n");

    player2_moves();
    }
}

char check(){
    for (size_t i = 0; i < 3; i++)

    {
        if( matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2] && matrix[i][2]=='O')
         return 'O';
        if( matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2] && matrix[i][2]=='X')
         return 'X';
        if( matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i] && matrix[2][i]=='O')
         return 'O';
        if( matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i] && matrix[2][i]=='X')
         return 'X';
        
    }
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[2][2]=='O')
        return'O';
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[2][2]=='X')
        return'X';

        if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[2][0]=='O')
        return 'O';
        if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[2][0]=='X')
        return 'X';
    int draw=0;
    for (size_t a = 0; a < 3; a++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(matrix[a][j]==' ') draw++;
        }
    
    }
    if(draw==0) return'D';

    
    return ' ';
}