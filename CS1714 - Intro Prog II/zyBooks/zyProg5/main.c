#include <stdio.h>
#include "point.h"

int main()
{
    struct Point p1,p2,temp;
    scanf("%lf",&p1.x);
    scanf("%lf",&p1.y);
    scanf("%lf",&p1.z);
    
    scanf("%lf",&p2.x);
    scanf("%lf",&p2.y);
    scanf("%lf",&p2.z);
    
    midpoint(p1,p2,&temp);
    printf("midpoint: %0.2f, %0.2f, %0.2f",temp.x,temp.y,temp.z);
    
    double dist;
    distance(p1,p2,&dist);
    printf("\ndistance: %0.2f",dist);
    
    return 0;
    
    
    
}