#include "Queue.h"

const int maxCheckInTables = 5;
const int maxVaccTables = 10;


int main()
{
  FILE* fptr = fopen("p2Input.txt", "r");

  if(fptr == NULL) {
    perror("Error opening file")
    return -1;
  }

  Queue checkInQ = newQueue();
  Queue vaccineQ = newQueue();

  int startTime, patientID, i;
  int cnt = 0, currCheckInCap = 0, currVaccTableCap = 0;
  int checkInTableTimes[5] = {0};
  int vaccTableTimes[10] = {0};
  char eSignIn[3];

  printf("%d", vaccTableTimes[3]);

  while(fscanf(fptr, "%d %d %c", &startTime, &patientID, eSignIn) == 3) {
    int isESignIn = 0;

    if(eSignIn[0] == 'y') {
      isESignIn = 1;
    }

    Patient myPatient = {startTime, patientID, isESignIn};
    if(currCheckInCap < 5) {
      enqueue(checkInQ, myPatient);
      currCheckInCap++;
    }
    else {
      if(frontElement(checkInQ))
    }
    cnt++;
  }







    return 0;
}
