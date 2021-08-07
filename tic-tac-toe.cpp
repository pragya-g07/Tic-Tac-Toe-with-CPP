#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

char board[3][3]={'1','2','3','4','5','6','7','8','9'};


void drawBoard()

{

    system("cls");
    cout<<"\n\n\t\t******TIC-TAC-TOE******"<<endl;
    cout<<"\n\n\n\n";
    cout<<"\t\t\t "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"\t\t\t----------"<<endl;
     cout<<"\t\t\t "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
     cout<<"\t\t\t----------"<<endl;
      cout<<"\t\t\t "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

char current_marker;
int current_player;

bool placeMarker(int slot)
{
    int row=slot/3,col=slot%3-1;
    if(slot%3==0){row=row-1;col=2;};


    if(board[row][col]!='X' && board[row][col]!='O')
    {
        board [row][col]=current_marker;
        return true;
    }
    else return false;

}

int winner()
{
    for(int i=0;i<3;i++)
    {
        //row
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) return current_player;

        //column
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i]) return current_player;
    }

        //right giagonal
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2]) return current_player;

        //left diagonal
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player;

    return 0;

}

void swap_player_and_marker()
{
    if(current_marker=='X') current_marker='O';
    else current_marker='X';

    if(current_player==
       1) current_player=2;
    else current_player=1;
}

void game()
{
    char marker_p1;
    cout<<"\nPlayer 1, choose your MARKER : ";
    cin>>marker_p1;

    current_player=1;
    current_marker=marker_p1;
    drawBoard();

    int player_won;


    for(int i=0;i<9;i++)
    {

        int slot;
        cout<<"\nIt is Player "<<current_player<<"'s turn. Choose your slot : ";
        cin>>slot;

        if(slot<1 || slot>9)
        {
            cout<<"\nSlot is INVALID! Try another slot.\n"<<endl;
            i--;
            continue;
        }

        if(!placeMarker(slot))
        {
            cout<<"\nSlot is already occupied! Try another slot.\n"<<endl;
            i--;
            continue;
        }
        drawBoard();

        player_won=winner();
        if(player_won==1){cout<<"\nPlayer-1 won! Congratulations...!"<<endl; break;}
        if(player_won==2){cout<<"\nPlayer-2 won! Congratulations...!"<<endl; break;}

        swap_player_and_marker();

    }

     if(player_won==0){cout<<"\nTie Game!"<<endl;}
}

int main()
{
    cout<<"\n\n\t\t******TIC-TAC-TOE******"<<endl;
    game();


    return 0;
}
