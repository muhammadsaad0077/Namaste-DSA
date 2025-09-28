#include<iostream>
#include<string>
using namespace std;

class Passenger{
    public:
        string name;
        Passenger* next;
        Passenger(string n){
            name = n;
            next = NULL;
        }
};

class Flight{
    public:
        string flightNumber;
        Passenger* head;
        Flight* next;
        Flight(string fn){
            flightNumber = fn;
            head = NULL;
            next = NULL;
        }
};

class ReservationSystem{
    private:
        Flight* flightHead;
    public:
        ReservationSystem(){
            flightHead = NULL;
        }

        Flight* findFlight(string fn){
            Flight* temp = flightHead;
            while(temp){
                if(temp->flightNumber == fn) return temp;
                temp = temp->next;
            }
            return NULL;
        }

        void addFlight(string fn){
            if(findFlight(fn)){
                cout<<"Flight already exists"<<endl;
                return;
            }
            Flight* newFlight = new Flight(fn);
            if(!flightHead || fn < flightHead->flightNumber){
                newFlight->next = flightHead;
                flightHead = newFlight;
            }
            else{
                Flight* current = flightHead;
                while(current->next && current->next->flightNumber < fn){
                    current = current->next;
                }
                newFlight->next = current->next;
                current->next = newFlight;
            }
            cout<<"Flight "<<fn<<" added"<<endl;
        }

        void reserveTicket(string fn,string name){
            Flight* flight = findFlight(fn);
            if(!flight){
                cout<<"Flight not found"<<endl;
                return;
            }
            Passenger* newP = new Passenger(name);
            if(!flight->head || name < flight->head->name){
                newP->next = flight->head;
                flight->head = newP;
            }
            else{
                Passenger* current = flight->head;
                while(current->next && current->next->name < name){
                    current = current->next;
                }
                newP->next = current->next;
                current->next = newP;
            }
            cout<<"Ticket reserved for "<<name<<" on flight "<<fn<<endl;
        }

        void cancelReservation(string fn,string name){
            Flight* flight = findFlight(fn);
            if(!flight){
                cout<<"Flight not found"<<endl;
                return;
            }
            Passenger* current = flight->head;
            Passenger* prev = NULL;
            while(current){
                if(current->name == name){
                    if(prev) prev->next = current->next;
                    else flight->head = current->next;
                    delete current;
                    cout<<"Reservation cancelled for "<<name<<endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout<<"No reservation found for "<<name<<endl;
        }

        void checkReservation(string fn,string name){
            Flight* flight = findFlight(fn);
            if(!flight){
                cout<<"Flight not found"<<endl;
                return;
            }
            Passenger* current = flight->head;
            while(current){
                if(current->name == name){
                    cout<<name<<" has a reservation on flight "<<fn<<endl;
                    return;
                }
                current = current->next;
            }
            cout<<name<<" has no reservation on flight "<<fn<<endl;
        }

        void displayPassengers(string fn){
            Flight* flight = findFlight(fn);
            if(!flight){
                cout<<"Flight not found"<<endl;
                return;
            }
            cout<<"Passengers on flight "<<fn<<": ";
            Passenger* current = flight->head;
            while(current){
                cout<<current->name<<" ";
                current = current->next;
            }
            cout<<endl;
        }

        void displayFlights(){
            cout<<"Flights: ";
            Flight* temp = flightHead;
            while(temp){
                cout<<temp->flightNumber<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    ReservationSystem system;
    system.addFlight("PK101");
    system.addFlight("PK202");
    system.addFlight("PK303");

    int choice;
    string fn,name;
    do{
        cout<<"\n1. Reserve Ticket"<<endl;
        cout<<"2. Cancel Reservation"<<endl;
        cout<<"3. Check Reservation"<<endl;
        cout<<"4. Display Passengers"<<endl;
        cout<<"5. Display Flights"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter flight number: ";
                cin>>fn;
                cout<<"Enter passenger name: ";
                cin>>name;
                system.reserveTicket(fn,name);
                break;
            case 2:
                cout<<"Enter flight number: ";
                cin>>fn;
                cout<<"Enter passenger name: ";
                cin>>name;
                system.cancelReservation(fn,name);
                break;
            case 3:
                cout<<"Enter flight number: ";
                cin>>fn;
                cout<<"Enter passenger name: ";
                cin>>name;
                system.checkReservation(fn,name);
                break;
            case 4:
                cout<<"Enter flight number: ";
                cin>>fn;
                system.displayPassengers(fn);
                break;
            case 5:
                system.displayFlights();
                break;
            case 0:
                cout<<"Exiting"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=0);
}
