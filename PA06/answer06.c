#include "answer06.h"
#include <stdio.h>
//#include <stdlib.h>

void print_path(int numstep, char direction)
{
    printf("%c %d", direction, numstep);
    printf("\n");
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
    return(-1);
}
void recursion(char** maze, int w, int h, int x, int y, char direction)
{
    int dir = 1;
    int tdir = 1;
    
    if(direction == 'S'){
        //int dir = 1;
        //int tdir = 1;
        while(x<h && maze[x][y] != WALL)
        {
            if(y+1 < w){
                if(maze[x][y+1] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'E';
                    //dir = 0;
                    recursion(maze, w, h, x, y+1, 'E');
                    dir = 0;
                }
            }
            if(y-1 > -1){
                if(maze[x][y-1] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'W';
                    //dir = 0;
                    recursion(maze, w, h, x, y-1, 'W');
                    dir = 0;
                }
            }
            x++;
            dir++;
            tdir++;
        }
        if(dir - 1 != 0){
            print_path(dir - 1, direction);
        }
        print_path(tdir - 1, 'N');
    }
    if(direction == 'N'){
        //int dir = 1;
        //int tdir = 1;
        while(x>(-1) && maze[x][y] != WALL)
        {
            if(y+1 < w){
                if(maze[x][y+1] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'E';
                    //dir = 0;
                    recursion(maze, w, h, x, y+1, 'E');
                    dir = 0;
                }
            }
            if(y-1 > -1){
                if(maze[x][y-1] == SPACE)
                {
                    if(dir != 0){
                        //printf("foo");
                        print_path(dir, direction);
                    }
                    
                    //direction = 'W';
                    //dir = 0;
                    recursion(maze, w, h, x, y-1, 'W');
                    dir = 0;
                }
            }
            x--;
            dir++;
            tdir++;
        }
        //printf("foo");
        if(dir - 1 != 0){
            print_path(dir - 1, direction);
        }
        print_path(tdir - 1, 'S');
    }
    
    if(direction == 'W'){
        //int dir = 1;
        //int tdir = 1;
        while(y>(-1) && maze[x][y] != WALL)
        {
            if(x+1 < h){
                if(maze[x+1][y] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'E';
                    //dir = 0;
                    recursion(maze, w, h, x+1, y, 'S');
                    dir = 0;
                }
            }
            if(x-1 > -1){
                if(maze[x-1][y] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'W';
                    //dir = 0;
                    recursion(maze, w, h, x-1, y, 'N');
                    dir = 0;
                }
            }
            y--;
            dir++;
            tdir++;
        }
        if(dir - 1 != 0){
            print_path(dir - 1, direction);
        }
        print_path(tdir - 1, 'E');
    }
    
    if(direction == 'E'){
        //int dir = 1;
        //int tdir = 1;
        while(y<w && maze[x][y] != WALL)
        {
            if(x+1 < h){
                if(maze[x+1][y] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'E';
                    //dir = 0;
                    recursion(maze, w, h, x + 1, y, 'S');
                    dir = 0;
                }
            }
            if(x-1 > -1){
                if(maze[x-1][y] == SPACE)
                {
                    if(dir != 0){
                        print_path(dir, direction);
                    }
                    
                    //direction = 'W';
                    //dir = 0;
                    recursion(maze, w, h, x-1, y, 'N');
                    dir = 0;
                }
            }
            y++;
            dir++;
            tdir++;
        }
        if(dir - 1 != 0){
            print_path(dir - 1, direction);
        }
        print_path(tdir - 1, 'W');
    }
    
}
void print_directions(char** maze, int w, int h)
{
    int x = 1;
    int y = getstart (maze, w, h);
    //y = (w+1)/2;
    //int dir = 1;
    //int sumdir = 1;
    
    recursion(maze, w, h, x, y,'S');
}
