#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "tested_declarations.h"
#include "rdebug.h"

int create_board(struct board_t **board, int width,int height)
{
    if(board==NULL||width<=0||height<=0)
        return 1;
    int i,k;
    *board=(struct board_t *)calloc(1,sizeof(struct board_t));
    if(*board==NULL)
    {
        return 2;
    }
    (*board)->board=(char**)calloc(height,sizeof(char*));
    if((*board)->board==NULL)
    {
        free(*board);
        return 2;
    }
    (*board)->is_init=0;
    (*board)->width=width;
    (*board)->height=height;
    (*board)->move_player_up=move_player_up;
    (*board)->move_player_down=move_player_down;
    (*board)->move_player_left=move_player_left;
    (*board)->move_player_right=move_player_right;
    for(i=0; i<height; i++)
    {
        *((*board)->board+i)=(char*)calloc(width+1,sizeof(char));
        if(*((*board)->board+i)==NULL)
        {
            free_board(*board);
            return 2;
        }
    }
    for(i=0; i<height; i++)
    {
        for(k=0; k<width; k++)
        {
            *(*((*board)->board+i)+k)='.';
        }
        *(*((*board)->board+i)+k)='\0';
    }
    return 0;
}
void display_board(const struct board_t *board)
{
    if(!(board==NULL||board->width<=0||board->height<=0))
    {
        int i,k;
        for(i=0; i<board->height; i++)
            if(*(board->board+i)==NULL)
                return;
        for(i=0; i<board->height; i++)
        {
            for(k=0; k<board->width; k++)
            {
                printf("%c",*(*(board->board+i)+k));
            }
            printf("\n");
        }
    }
}
void free_board(struct board_t *board)
{
    if(!(board==NULL||board->board==NULL||board->width<=0||board->height<=0))
    {
        int i;
        for(i=0; i<board->height; i++)
        {
            if(*(board->board+i)!=NULL)
            {
                free(*(board->board+i));
            }

        }
        if(board->board!=NULL)
                free(board->board);
            if(board!=NULL)
                free(board);
    }
}
int set_player(struct board_t *board, int x, int y)
{
    if(board==NULL||board->board==NULL||board->width<=0||board->height<=0||board->is_init==1||x<0||y<0||x>=board->width||y>=board->height)
        return 1;
    int i;
    for(i=0; i<board->height; i++)
        if(*(board->board+i)==NULL)
            return 1;
    board->is_init=1;
    board->player.x=x;
    board->player.y=y;
    *(*(board->board+y)+x)='@';
    return 0;
}
struct board_t* move_player_up(struct board_t* board)
{
    if(board==NULL||board->board==NULL||board->player.x<0||board->player.y<0||board->player.x>=board->width||board->player.y>=board->height||board->is_init!=1||board->width<=0||board->height<=0)
        return NULL;
    int i;
    for(i=0; i<board->height; i++)
        if(*(board->board+i)==NULL)
            return NULL;
    *(*(board->board+board->player.y)+board->player.x)='.';
    board->player.y=(board->player.y-1);
    if(board->player.y==-1)
    {
        board->player.y=board->height-1;
    }
    *(*(board->board+board->player.y)+board->player.x)='@';
    return board;
}
struct board_t* move_player_down(struct board_t* board)
{
    if(board==NULL||board->board==NULL||board->player.x<0||board->player.y<0||board->player.x>=board->width||board->player.y>=board->height||board->is_init!=1||board->width<=0||board->height<=0)
        return NULL;
    int i;
    for(i=0; i<board->height; i++)
        if(*(board->board+i)==NULL)
            return NULL;
    *(*(board->board+board->player.y)+board->player.x)='.';
    board->player.y=(board->player.y+1);
    if(board->player.y==board->height)
    {
        board->player.y=0;
    }
    *(*(board->board+board->player.y)+board->player.x)='@';
    return board;
}
struct board_t* move_player_left(struct board_t* board)
{
    if(board==NULL||board->board==NULL||board->player.x<0||board->player.y<0||board->player.x>=board->width||board->player.y>=board->height||board->is_init!=1||board->width<=0||board->height<=0)
        return NULL;
    int i;
    for(i=0; i<board->height; i++)
        if(*(board->board+i)==NULL)
            return NULL;
    *(*(board->board+board->player.y)+board->player.x)='.';
    board->player.x=(board->player.x-1);
    if(board->player.x==-1)
    {
        board->player.x=board->width-1;
    }
    *(*(board->board+board->player.y)+board->player.x)='@';
    return board;
}
struct board_t* move_player_right(struct board_t* board)
{
    if(board==NULL||board->board==NULL||board->player.x<0||board->player.y<0||board->player.x>=board->width||board->player.y>=board->height||board->is_init!=1||board->width<=0||board->height<=0)
        return NULL;
    int i;
    for(i=0; i<board->height; i++)
        if(*(board->board+i)==NULL)
            return NULL;
    *(*(board->board+board->player.y)+board->player.x)='.';
    board->player.x=(board->player.x+1);
    if(board->player.x==board->width)
    {
        board->player.x=0;
    }
    *(*(board->board+board->player.y)+board->player.x)='@';
    return board;
}

