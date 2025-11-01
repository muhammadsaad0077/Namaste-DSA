#include<iostream>
using namespace std;

class Node{
    public:
        int arrivalTime;   
        int serviceTime;  
        int waitedTime;    
        Node* next;

        Node(int aT, int sT){
            arrivalTime = aT;
            serviceTime = sT;
            waitedTime = 0;
            next = NULL;
        }
};

class PatientQueue{
    public:
        Node* first;
        Node* last;

        PatientQueue(){
            first = last = NULL;
        }

        bool isEmpty(){
            return first == NULL;
        }

        void enqueue(int aT, int sT){
            Node* newPatient = new Node(aT, sT);
            if(last == NULL){
                first = last = newPatient;
            }
            else{
                last->next = newPatient;
                last = newPatient;
            }
        }

        Node* dequeue(){
            if(isEmpty()) return NULL;
            Node* temp = first;
            first = first->next;
            if (first == NULL) last = NULL;
            return temp;
        }

        void simulateClinic(){
            if(isEmpty()){
                cout<<"No patients in queue!"<<endl;
                return;
            }

            int currentTime = 0;            
            int totalWaitedTime = 0;        
            int totalPatients = 0;
            int peakSystemSize = 0;         
            int longestIdle = 0;            

            Node* temp = first;
            int queueCount = 0;

            // Calculate total patients for peak system size base
            while(temp){
                queueCount++;
                peakSystemSize = max(peakSystemSize, queueCount);
                temp = temp->next;
            }

            cout<<"\n--- Vaccination Simulation (FCFS) ---"<<endl;
            cout<<"Arrival(min)\tService(min)\tWaited(min)"<<endl;

            Node* patient;
            int previousFinishTime = 0;

            while((patient = dequeue()) != NULL){
                totalPatients++;

                // If nurse idle before next patient arrives
                if(patient->arrivalTime > currentTime){
                    int idleTime = patient->arrivalTime - currentTime;
                    if(idleTime > longestIdle)
                        longestIdle = idleTime;
                    currentTime = patient->arrivalTime;
                }

                // Calculate how long patient waited
                patient->waitedTime = currentTime - patient->arrivalTime;
                if(patient->waitedTime < 0)
                    patient->waitedTime = 0;

                totalWaitedTime += patient->waitedTime;

                cout<<patient->arrivalTime<<"\t\t"<<patient->serviceTime<<"\t\t"<<patient->waitedTime<<endl;

                // Advance clinic clock
                currentTime += patient->serviceTime;

                delete patient;
            }

            double avgWaited = (totalPatients > 0)
                            ? (double)totalWaitedTime / totalPatients
                            : 0;

            cout<<"\n--- Simulation Summary ---"<<endl;
            cout<<"Total Patients: "<<totalPatients<<endl;
            cout<<"Average Waiting Time: "<<avgWaited<<" minutes"<<endl;
            cout<<"Peak System Size: "<<peakSystemSize<<" patients"<<endl;
            cout<<"Longest Idle Stretch: "<<longestIdle<<" minutes"<<endl;
        }
};

int main() {
    PatientQueue p;

    cout<<"Saad Bin Sharif"<<endl;
    cout<<"24p-3077"<<endl;

    // Arrival times = minutes since opening (e.g., 0 = 9:00 AM)
    p.enqueue(0, 5);     // Patient 1 arrives at 0 min, needs 5 min service
    p.enqueue(3, 7);     
    p.enqueue(12, 4);    
    p.enqueue(20, 6);    

    p.simulateClinic();
}
