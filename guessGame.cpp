#include<iostream>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int randNumber=(rand()%10)+1;
    int guessNumber;
    int noAttempts=0;
    cout<<"Guess Game :(1-10): ";
    do{
        cin>>guessNumber;
        if(guessNumber!=randNumber){
            noAttempts++;
            if(guessNumber>randNumber){
                cout<<"Lesser Than "<<guessNumber<<" : ";
            }
            else{
                cout<<"Greater Than "<<guessNumber<<" : ";
            }
        }
        else{
            cout<<"\nYour Guess is Right!";
            break;
        }
    }while(noAttempts!=10);
    if(noAttempts==10){
        cout<<"\nYou Lose!"<<endl;
    }
    else{
        cout<<"\nYou Won!"<<endl;
    }
    cout<<"\nYour Score :"<<10-noAttempts<<"/10";
}