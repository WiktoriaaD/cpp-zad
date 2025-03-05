#include <iostream>
using namespace std;

#define SIZE 3

void showBoard(char board[SIZE][SIZE]){
    int i;
    int j;
    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j<SIZE ; j++)
            {
                cout << board[i][j];
                cout << " | ";
            }
            cout << "\n" ;
        }
}

void clearBoard(char board[SIZE][SIZE]){
    int i;
    int j;
    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                board[i][j] = ' ';
            }
        
        }
}

bool isFinished(char board[SIZE][SIZE], char *winner){
    int i;
    int j;

    if (board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        *winner = board[0][0];
        return true;
    }
    if (board[0][3]!=' ' && board[0][3]==board[1][1] && board[1][1]==board[2][0])
    {
        *winner = board[1][1];
        return true;
    }

    for (i = 0;i < SIZE;i++){
        if (board[i][0] != ' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
            *winner = board[i][0];
            return true;
        }
        
    }
    for (j = 0;j < SIZE;j++){
        if (board[0][j] != ' ' && board[0][j]==board[1][j] && board[1][j]==board[2][j])
        {
            *winner = board[0][j];
            return true;
        }
    }
    
    for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                 if (board[i][j] == ' ')
                 {
                    return false;
                 }

            }
        
        }    

    *winner = 'R';
    return true;
}

bool setPoint(char board[SIZE][SIZE], unsigned int x, unsigned int y, char player){
    if (x<3 && y<3 && board[x][y]== ' ')
    {
        board[x][y] = player;
        return true;
    }
    else return false;
    
}

int main(){
    srand(time(NULL));
    char board[SIZE][SIZE];
    char winner = ' ';
    char player = 'X';
    clearBoard(board);
    showBoard(board);
    while(!isFinished(board,&winner)){
        int x;
        int y;
        if (player == 'O'){
            x = rand()%3;
            y = rand()%3;
        }
        else{
            cout << "Podaj wspolrzedne dla x: ";
            cin >> x;
            cout << "Podaj wspolrzedne dla y: ";
            cin >> y;
        }
        if (setPoint(board,x,y,player)){
            player = (player == 'X') ? 'O' : 'X';
        }
        else { 
            cout << "Nieprawidlowe pole." << endl;
        }
        showBoard(board);
        cout<< endl;
    }
    if(winner != ' '){
            if (winner == 'R'){
                cout << "Wynik: remis"<<endl;
            }
            else cout << "Wygral: " << winner <<endl;
        }    
    
    return 0;
}
