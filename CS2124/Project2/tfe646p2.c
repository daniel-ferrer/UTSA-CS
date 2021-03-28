#include "Queue.h"

const int maxCheckInTables = 5;
const int maxVaccTables = 10;

int main()
{
  FILE* fptr = fopen("p2Input.txt", "r");

  if(fptr == NULL) {
    perror("Error opening file");
    return -1;
  }
    int arrivalTime,patientId;
    int checkInTableSize=5, vaccineTableSize=10, patientOnCheckInTable=0, PatientOnVaccineTable=0;
    char buf[3];
    Queue checkInQueue= newQueue();
    Queue vaccineShotQueue = newQueue();
    while (fscanf(fptr,"%d %d %s",&arrivalTime,&patientId,buf) == 3){
        int checkIn=0;
        if(buf[0]=='y')
            checkIn=1;
        Patient patient= {arrivalTime,patientId,checkIn};
        enqueue(checkInQueue,patient);
    }
    Patient patientArray[5];
    int arrivalTimeOnCheckInTable[5]={-1,-1,-1,-1,-1};
    Patient vaccineShotArray[10];
    int arrivalTimeOnVaccineTable[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    //I am assuming that file is sorted based on arrival time

    //This queue is for those peoples who already got vaccinated but waiting for 30 minutes.
    Queue vaccinatedQueue= newQueue();
    //Their vaccination end time is stored in this array.
    int vaccinatedPersonEndTime[10000],endTimeIndex=0;
    for(int i=1;;i++){

        //Check for patients on vaccine table
        for(int k=0;k<10;k++){
            if((arrivalTimeOnVaccineTable[k]!=-1))
            {
                if(i-arrivalTimeOnVaccineTable[k]>=10){
                    enqueue(vaccinatedQueue,vaccineShotArray[k]);
                    vaccinatedPersonEndTime[endTimeIndex++]=i;
                    arrivalTimeOnVaccineTable[k]=-1;
                    PatientOnVaccineTable--;
                }
            }
        }

        //check for patient on the vaccineShot Queue
        while(vaccineTableSize>PatientOnVaccineTable){
            Element* element;
            int exist=frontElement(vaccineShotQueue,element),k=0;
            if(exist==1){
                for(int z=0;z<10;z++){
                    if(arrivalTimeOnVaccineTable[z]==-1 ){
                        vaccineShotArray[z]=*element;
                        arrivalTimeOnVaccineTable[z]=i;
                        arrivalTimeOnCheckInTable[k]=-1;
                        PatientOnVaccineTable++;
                        break;
                    }
               }
            }else{
                break;
           }
        }

        //Adding patients from checkinTable to VaccineShotQueue
        for(int k=0;k<5;k++){
            if((arrivalTimeOnCheckInTable[k]!=-1))
            {
                if((patientArray[k].eCheckIn==1 && i-arrivalTimeOnCheckInTable[k]>=4) || (patientArray[k].eCheckIn==0 && i-arrivalTimeOnCheckInTable[k]>=10)) {
                    arrivalTimeOnCheckInTable[k]=-1;
                    patientOnCheckInTable--;
                    enqueue(vaccineShotQueue,patientArray[k]);
                }
            }
        }

        //Adding patients from checki Quueue to checkin Table
        while(checkInTableSize>patientOnCheckInTable){
            Element* element;
            int exist=frontElement(checkInQueue,element);
            if(exist==1){
               if(element->arrivalTime <=i)
               {
                   for(int k=0;k<5;k++){
                       if(arrivalTimeOnCheckInTable[k]==-1){
                           patientArray[k]=*element;
                           arrivalTimeOnCheckInTable[k]=i;
                           patientOnCheckInTable++;
                           dequeue(checkInQueue,element);
                       }
                   }
               }
            }else{
                break;
           }
        }
    }
    return 0;
}
