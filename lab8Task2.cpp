#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void checkNum(int num, int randomNumber){
    if(num == randomNumber){
        cout<<"You Guessed Correctly, Won"<<endl;
        return;
    }

    if(num < randomNumber){
        cout<<"Guess was low, Try larger Number "<<endl;
        cout<<"Enter Num: ";
        cin>>num;
        checkNum(num, randomNumber);
    }
    else{
        cout<<"Guess was high, Try smaller Number "<<endl;
        cout<<"Enter Num: ";
        cin>>num;
        checkNum(num, randomNumber);
    }
}

int main(){
    srand(time(0));
    int randomNumber = rand() % 100;

    int choice = 1, num = 0, opt= 0;
    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24P-3077"<<endl;
    
    while(choice){

        cout<<"1: Play the Game"<<endl;
        cout<<"2: Quit Game"<<endl;

        cin>>opt;

        switch(opt){
            case 1:
                cout<<"Enter Number to Guess ";
                cin>>num;

                checkNum(num, randomNumber);
                break;

            case 2:
                choice = 0;
                break;

            default:
                cout<<"Incorrect Entry"<<endl;
        }

    }

    
}