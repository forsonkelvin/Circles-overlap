#include "circle.h"
#include <stdio.h>

bool valid_circle(struct circle c)
{
    return c.radius >  0;
}

struct circle read_circle(void)
{
    struct circle first;
    
   int count =  scanf("%lf %lf %lf",&first.x,&first.y,&first.radius);
   if (count < 3){
       first.x = 0.0;
       first.y =0.0;
       first.radius = -1.0;
   }   
    return first;
}

bool overlapped_circles(struct circle c1, struct circle c2)
{
    double distance1 =(c1.x - c2.x)*(c1.x - c2.x);
    double distance2 =(c1.y -c2.y)*(c1.y - c2.y);
    double total = distance1 + distance2;
    double totalRadii = (c1.radius + c2.radius)*(c1.radius + c2.radius);

    return total < totalRadii;
}

