#include<iostream>
using namespace std;
int score(char answers[],char userAnswers[]);
int main(){
    string questions[3]={"1.What is a Class ? ",
                        "2.What is an Object ? ",
                        "3.What is Inheritence in OOPs ? "};
    string choice[][3]={{"A.Blueprints/plan for an object",
                         "B.One of the 4 pillars in OOP ",
                         "C.Instance of an object "},
                        {"A.One of the 4 pillars in OOP",
                         "B.An Instance of a Class ",
                         "C.Blueprints/plan for a Class"},
                        {"A.Another name for Parent Class ",
                         "B.One of the 4 pillars in OOP ",
                         "C.Used to data hiding "}};
    char answers[3]={'A','B','B'};
    char userAnswers[3];
    char userAnswer;
    //Display the questioins and their choice to users
    int rows=sizeof(choice)/sizeof(choice[0]);
    int columns=sizeof(choice[0])/sizeof(choice[0][0]);
    int noOfQues=sizeof(questions)/sizeof(questions[0]);
    for(int i=0;i<noOfQues;i++){
        cout<<questions[i]<<endl;
        for(int k=0;k<columns;k++){
            cout<<"\t - "<<choice[i][k]<<endl;
        }
        cout<<"\n"<<endl;
        cin>>userAnswer;
        userAnswers[i]=userAnswer;
    }
    cout<<"Your Score is "<<score(answers,userAnswers);
}
int score(char answers[],char userAnswers[]){
    int i=0;
    int score=0;
    while(i<3){
        if(answers[i]==userAnswers[i]){
            score++;
        }
        i++;
    }
    return score;
}
