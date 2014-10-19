#include "answer06.h"
#include <stdio.h>
#define None 0
#define South 1
#define North 2
#define West 3
#define East 4
void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir, int *Total);
int CanMove (char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction);
void IsNew(char **maze,int WIndex,int HIndex,int *Total);

void print_directions(char** maze, int w, int h) 

{
	int WIndex, HIndex; // Indicies used in while loops
	int WStart; // width of where to start the maze 
	int Total = 0; // Number of squares needed to cover
	
	printf("\e[1;1H\e[2J"); // Clears screen
	
	for (WIndex = 0; WIndex < w; WIndex++) // Finds entrance
	{
		if (maze[0][WIndex] == ' ')
		{
			WStart = WIndex;
			WIndex = w;
		}
	}
	
	// Figures out how many spaces must be moved through
	for (WIndex = 0; WIndex < w; WIndex++)
	{
		for (HIndex = 0; HIndex < h; HIndex++)
		{
			if (maze[HIndex][WIndex] == ' ')
			{
				Total++;
			}
		} 
	}
	
	// subtract 1 since C starts index at 0
	w--; 
	h--;
	
	
	Move(maze, WStart, 0, w, h, South, &Total); 	
}


void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir, int *Total)
{
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South) && (Dir != North) && *Total)
	{
		// Go south 
		WIndex++;
		printf("S\n");
		IsNew(maze,WIndex,HIndex,Total); // Desides if new part in maze and adjusts Total
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total);
	}
	
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South) && (Dir != North) && *Total)
	{
		// Go east 
		HIndex++;
		printf("E\n");
		IsNew(maze,WIndex,HIndex,Total); // Desides if new part in maze and adjusts Total
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total);
	}
	
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South) && (Dir != North) && *Total)
	{
		// Go west 
		HIndex--;
		printf("W\n");
		IsNew(maze,WIndex,HIndex,Total); // Desides if new part in maze and adjusts Total
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total);
	}
	
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South) && (Dir != North) && *Total)
	{
		// Go north 
		WIndex--;
		printf("N\n");
		IsNew(maze,WIndex,HIndex,Total); // Desides if new part in maze and adjusts Total
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total);
	}
	Dir = None; // Resets direction to allow to move backwards
	
}


int CanMove (char **maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction) // Decides if direction is possible
{
	switch (Direction)
	{
		case North :
			WIndex--;
			break ;
		case South :
			WIndex++;
			break ;
		case West :
			HIndex--;
			break ;
		case East :
			HIndex++;
			break ;
	}
	
	if ((maze[WIndex][HIndex] != 'X') && (WIndex >= 0) && (WIndex <= MaxW) && (HIndex >= 0) && (HIndex <= MaxH))
	{ 
		return 1; // No wall and within range
	}
	return 0; //Can't move
}

void IsNew(char **maze,int WIndex,int HIndex,int *Total)
{
	if (maze[WIndex][HIndex] == ' ')
	{
		(*Total)++;
		maze[WIndex][HIndex] = '*';
	}
}


