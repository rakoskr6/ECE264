#include "answer06.h"
#include <stdio.h>
#define South 1
#define North 2
#define West 3
#define East 4
void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir);
int CanMove (char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction);

void print_directions(char** maze, int w, int h) 

{
	int WIndex;//, HIndex; // Indicies used in while loops
	int WStart; // width of where to start the maze 
	
	printf("\e[1;1H\e[2J"); // Clears screen
	
	for (WIndex = 0; WIndex < w; WIndex++)
	{
		if (maze[0][WIndex] == ' ')
		{
			WStart = WIndex;
			WIndex = w;
		}
	}
	
	Move(maze; WStart, 0, w - 1, h - 1); // subtract 1 since C starts index at 0

	
}


void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir)
{
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South))
	{
		// Go south 
	}
	
}


int CanMove (char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction) // Decides if direction is possible
{
	switch (Direction)
	{
		case NORTH :
			WIndex--;
			break ;
		case SOUTH :
			WIndex++;
			break ;
		case WEST :
			HIndex--;
			break ;
		case EAST :
			HIndex++;
			break ;
	}
	
	if ((maze[WIndex][HIndex] == ’ ’) && (WIndex >= 0) && (WIndex <= MaxW) && (HIndex >= 0) && (HIndex <= MaxH))
	{ 
		return 1; // No wall and within range
	}
	return 0; //Can't move
}




