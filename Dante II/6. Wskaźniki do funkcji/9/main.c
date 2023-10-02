#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    struct board_t *board;
    int t,x,y,w,s;
    char z='0';
    printf("Daj: ");
    t=scanf("%d %d",&s, &w);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(s<=0||w<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    t=create_board(&board,s,w);
    if(t==1)
    {
        printf("Incorrect input data");
        return 2;
    }
    if(t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    t=scanf("%d %d",&x,&y);
    if(t!=2)
    {
        free_board(board);
        printf("Incorrect input");
        return 1;
    }
    if(x<0||y<0||x>=s||y>=w)
    {
        free_board(board);
        printf("Incorrect input data");
        return 2;
    }
    t=set_player(board,x,y);
    if(t==1)
    {
        free_board(board);
        printf("Incorrect input");
        return 1;
    }
    do
    {
        display_board(board);
        do
        {
            while( getchar() != '\n');
            printf("Daj: ");
            t=scanf("%c",&z);
            if((z!='q'&&z!='w'&&z!='s'&&z!='a'&&z!='d'&&z!='Q'&&z!='W'&&z!='S'&&z!='A'&&z!='d'))
            {
                printf("Incorrect choice\n");
            }
        }
        while (z!='q'&&z!='w'&&z!='s'&&z!='a'&&z!='d'&&z!='Q'&&z!='W'&&z!='S'&&z!='A'&&z!='d');
        if(z=='w')
        {
            move_player_up(board);
        }
        else if(z=='s')
        {
            move_player_down(board);
        }
        else if(z=='a')
        {
            move_player_left(board);
        }
        else if(z=='d')
        {
            move_player_right(board);
        }
    }
    while(z!='q'&&z!='Q');
    free_board(board);
    return 0;
}

