#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int is_destination_reachable(int sx, int sy, int dx, int dy)
{
    int x, y;
    if((sx==dx)&&(sy==dy))
        return 1;

    if((sx>dx)||(sy>dy))
        return 0;

    x= (is_destination_reachable(sx+sy,sy,dx,dy));
    y= (is_destination_reachable(sx,sx+sy,dx,dy));
    if((x==1)||(y==1))
        return 1;
    return 0;
}

int main()
{
    int sx,sy,dx,dy,t;
    printf("Daj: ");
    t=scanf("%d %d",&sx, &sy);
    if(t!=2)
    {
        printf("incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d %d",&dx, &dy);
    if(t!=2)
    {
        printf("incorrect input");
        return 1;
    }
    if(is_destination_reachable(sx,sy,dx,dy)==1)
    {
        printf("YES");
    }
    else
        printf("NO");

    return 0;
}


