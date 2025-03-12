#include <iostream>
#include <cstdlib>
using namespace std;

void showBoard(char **board,int SIZE){
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

void clearBoard(char **board,int SIZE){
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

bool isFinished(char **board, char *winner,int SIZE){
    int i;
    int j;
    int X=0;
    int O=0;
    for (i=0;i<SIZE;i++)
    {
        bool row=true;
        char znakteraz = board[0][0];
        if (znakteraz == ' '){
            row = false;
        }

        for (j = 1; j < SIZE; j++) {
            if (board[i][j] != znakteraz) {
                row = false; 
                break;
                }
        }

        if(row=true){
            *winner=znakteraz;
            return true;
            }
        
        
    }
}

bool setPoint(char **board, unsigned int x, unsigned int y, char player,int SIZE){
    if (x<SIZE && y<SIZE && board[x][y]== ' ')
    {
        board[x][y] = player;
        return true;
    }
    else return false;
    
}

int main(int argc,char* argv[]){
    srand(time(NULL));
    char winner = ' ';
    char player = 'X';
    int SIZE = atoi(argv[1]);
    if (SIZE<3)
        SIZE=3;
    char **board = new char*[SIZE];
    for (int i = 0;i < SIZE;i++)
    {
        board[i] = new char[SIZE];
    }
    clearBoard(board,SIZE);
    showBoard(board,SIZE);
    
    while(!isFinished(board,&winner,SIZE)){
        int x;
        int y;
        if (player == 'O'){
            x = rand()%SIZE;
            y = rand()%SIZE;
        }
        else{
            cout << "Podaj wspolrzedne dla x: ";
            cin >> x;
            cout << "Podaj wspolrzedne dla y: ";
            cin >> y;
        }
        if (setPoint(board,x,y,player,SIZE)){
            player = (player == 'X') ? 'O' : 'X';
        }
        else { 
            cout << "Nieprawidlowe pole." << endl;
        }
        showBoard(board,SIZE);
        cout<< endl;
    }
    if(winner != ' '){
            if (winner == 'R'){
                cout << "Wynik: remis"<<endl;
            }
            else cout << "Wygral: " << winner <<endl;
        }    
    for (int i =0;i < SIZE ;i++)
    {
        delete [] board[i];
    }
    
    delete [] board;
    
    return 0;
}
