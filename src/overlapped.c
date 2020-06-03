// overlapped - Reads a target circle, then any number of candidate
// circles. Prints "overlapped\n" for each candidate circle that
// intersects the target and "not overlapped\n" for each candidate
// circle that does not. Exits after reading an invalid circle.

#include "circle.h"
#include <stdio.h>
#include <stdlib.h>


#define OVERLAPPED_MSG      "overlapped\n"
#define NOT_OVERLAPPED_MSG  "not overlapped\n"

int main()
{
    struct circle oval = read_circle();
    if (!valid_circle(oval)) exit(1);

    for( ; ;){
        struct circle oval2 = read_circle();
        if (!valid_circle(oval2))exit(0);
        if (overlapped_circles(oval,oval2)){
            printf("overlapped\n");
                }
        else {
            printf("not overlapped\n");
        }
        
    }
    
    
}
