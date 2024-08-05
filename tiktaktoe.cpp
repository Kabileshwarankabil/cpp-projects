/*
1.Playing board
2.player move
3.Computer move
4.winner
5.tie?
*/
#include<iostream>
#include<ctime>
using namespace std;
void gameBoard(char *space);
void playerMove(char *space,char player);
void computerMove(char *space,char computer);
bool checkWinner(char *space,char player,char computer);
bool checkTie(char *space);
int  main()
{
    char space[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running=true;
    gameBoard(space);
    while(running)
    {
        playerMove(space,player);
        gameBoard(space);
        if(checkWinner(space,player,computer))
        {
            running=false;
            break;
        }
        else if(checkTie(space))
        {
            running=false;
            break;
        }
        computerMove(space,computer);
        gameBoard(space);
		if(checkWinner(space,player,computer))
        {
            running=false;
            break;
        }
        else if(checkTie(space))
        {
            running=false;
            break;
        }
    }
    cout<<" Thanks for Playing";
    return 0;    
}
void gameBoard(char *space){
    cout<<'\n';
    cout<<" _________________ \n";
    cout<<"|     |     |     |\n";
    cout<<"|  "<<space[0]<<"  |  "<<space[1]<<"  |  "<<space[2]<<"  |\n";
    cout<<"|_____|_____|_____|\n";
    cout<<"|     |     |     |\n";
    cout<<"|  "<<space[3]<<"  |  "<<space[4]<<"  |  "<<space[5]<<"  |\n";
    cout<<"|_____|_____|_____|\n";
    cout<<"|     |     |     |\n";
    cout<<"|  "<<space[6]<<"  |  "<<space[7]<<"  |  "<<space[8]<<"  |\n";
    cout<<"|_____|_____|_____|\n";
    cout<<'\n';
}
void playerMove(char *space,char player){
    int number;
    do{
        cout<<"Enter a Spot in the Board (1-9): ";
        cin>>number;
        number--;
        if(space[number]==' ')
        {
            space[number]=player;
            break;
        }
    }while(!number >0 || !number <8);
}
void computerMove(char *space,char computer){
    int number;
    srand(time(0));
    while(true)
    {
        number=rand()%9;
        if(space[number]==' ')
        {
            space[number]=computer;
            break;
        }
    }
    
}
bool checkWinner(char *space,char player,char computer){
    //rows
    if(space[0]!=' ' && space[0]==space[1] && space[1]==space[2])
    {
        space[0]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else if(space[3]!=' ' && space[3]==space[4] && space[4]==space[5])
    {
        space[3]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else if(space[6]!=' ' && space[6]==space[7] && space[7]==space[8])
    {
        space[6]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    //Columns
    else if(space[0]!=' ' && space[0]==space[3] && space[3]==space[6])
    {
        space[0]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else if(space[1]!=' ' && space[1]==space[4] && space[4]==space[7])
    {
        space[1]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else if(space[2]!=' ' && space[2]==space[5] && space[5]==space[8])
    {
        space[2]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    //Diagonal
    else if(space[0]!=' ' && space[0]==space[4] && space[4]==space[8])
    {
        space[0]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else if(space[2]!=' ' && space[2]==space[4] && space[4]==space[6])
    {
        space[2]==player? cout<<"You Win \n": cout<<"You Lose\n";
    }
    else{
        return false;
    }
    return true;
}
bool checkTie(char *space){
    for(int i=0;i<9;i++)
    {
        if(space[i]==' ')
        {
            return false;
        }
    }
    cout<<"It's A Tie.\n";
    return true;
}
