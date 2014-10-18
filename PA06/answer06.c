#include "answer06.h"
#include <stdio.h>

void print_path(int deltax, int deltay, int numstep)
{
    char dir;
    if( deltax == 1)
    {
        dir = 'S';
    }
    if( deltax == -1)
    {
        dir = 'N';
    }
    if( deltay == 1)
    {
        dir = 'E';
    }
    if( deltay == -1)
    {
        dir = 'W';
    }
    printf("%c %d", dir, numstep);
}
int getstart(char **maze, int w , int h)
{
    int ind = 0;
    for (ind=0;ind<w;ind++)
    {
        if(maze[0][ind] == SPACE)
        {
            return(ind);
        }
    }
    return(0);
}
void recursion(char ** maze, int w, int h, int x, int y, int deltax, int deltay)
{
    int numstep;
    while(maze[x][y] != WALL)
    {
        numstep ++;
        x += deltax;
        y += deltay;
        maze[x][y] = '.';
        
        //Checking for deadend and direction
        int east = (maze[x][y+1] == SPACE);
        int west = (maze[x][y-1] == SPACE);
        int north = (maze[x-1][y] == SPACE);
        int south = (maze[x+1][y] == SPACE);
        
        if(east | west | south | north)
        {
            print_path(deltax, deltay, numstep);
            print_path(-deltax, -deltay, numstep);
        }
        
        //Checking for a junction
        if(east + west + south + north >= 1)
        {
            //print forward;
            if(east)
            {
                recursion(maze,w,h,x,y,0,1);
            }
            if(west)
            {
                recursion(maze,w,h,x,y,0,-1);
            }
            if(north)
            {
                recursion(maze,w,h,x,y,-1,0);
            }
            if(south)
            {
                recursion(maze,w,h,x,y,1,0);
            }
        }
    }
    print_path(-deltax, -deltay, numstep);
    
}
void print_directions(char** maze, int w, int h)
{
    int x = 0;
    int y = getstart (maze, w, h);
    
    recursion(maze, w, h, x, y, 1, 0);
}
