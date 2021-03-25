#include "Queue.h"


int main()
{
  Queue myQ = newQueue();
  printf("%d\n", isEmpty(myQ));
  Element *ele = (Element*) malloc (sizeof(Element));
  ele->patientID = 1;
  ele->arrivalTime = 2;
  ele->eCheckIn = 1;
  enqueue(myQ, *ele);
  printf("%d", isEmpty(myQ));

    return 0;
}
