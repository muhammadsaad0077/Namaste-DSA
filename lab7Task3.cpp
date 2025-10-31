#include<iostream>
using namespace std;

class Time{
public:
    int hour, minute, second;
    
    Time(){
        hour = minute = second = 0;
    }

    Time(int h, int m, int s){
        hour = h;
        minute = m;
        second = s;
    }

    void show(){
        cout<<"Opening Time: "<<hour<<":"<<minute<<":"<<second<<endl;
    }
};


class Node{
    public:
    
    int arrivalTime;
    int serviceTime;
    Node* next;

    Node(int aT, int sT){
        arrivalTime = aT;
        serviceTime = sT;
        next = NULL;
    }
};

class PatientQueue{
    public:
        Node* first, *last;
        Time openingTime;

        PatientQueue(){
            first = last = NULL;
            openingTime = Time(9, 0, 0);
        }

        void addPatient(int h,int m,int s, int sT){
            int openSec = openingTime.hour * 3600 + openingTime.minute*60 + openingTime.second;
            int arrSec = h*3600 + m*60 + s;
            int totalSec = openSec - arrSec;
            int minSinceOpen =totalSec / 60;
            Node* newPatient = new Node(minSinceOpen, sT);

            if(!first){
                first = last = newPatient;
            }
            else{
                last->next = newPatient;
                last = newPatient;
            }
        }

        void removePatient(){
            if(!first){
                cout<<"No Patient to remove"<<endl;
                return;
            }
            else{
                Node* temp = first;
                first = first->next;

                if(!first){
                    first = last = NULL;
                }

                delete temp;
            }
        }

        void display(){
            Node* temp = first;
            int i = 0

            while(temp){
                i++
                cout<<"Patient "<<i<<" Arrival Time: "<<temp->arrivalTime<<endl;
                cout<<"Patient "<<i<<" Service Time: "<<temp->serviceTime<<endl;
                temp = temp->next;
            }
        }
};

int main(){

    PatientQueue p;
    p.addPatient(10, 0, 0, 5);
    p.display();


}