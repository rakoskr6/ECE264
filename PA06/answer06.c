#include "answer06.h"
#include <stdio.h>
#define None 0
#define South 1
#define North 2
#define West 3
#define East 4
#define Forward  0
#define Backward 1
void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int *Dir, int *Total, int *Mode);
int CanMove (char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction);
void IsNew(char **maze,int WIndex,int HIndex,int *Total);

void print_directions(char** maze, int w, int h) 

{
	int WIndex, HIndex; // Indicies used in while loops
	int WStart; // width of where to start the maze 
	int Total = 0; // Number of squares needed to cover
	int Direction = South;
	int Mode = Forward;
	
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
	
	// Redfine Indicies to be equal to start location
	WIndex = WStart;
	HIndex = 0;

	IsNew(maze,0,WStart,&Total); // Ensures entrance is counted
	Move(maze, WIndex, HIndex, w, h, &Direction, &Total, &Mode); 	
}


void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int *Dir, int *Total, int *Mode)
{
	//printf("W = %i, H = %i, Dir: %i, Total: %i\n",WIndex, HIndex, *Dir, *Total);
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, South) && (*Dir != North) && *Total)
	{
		// Go south 
		*Mode = Forward;
		(HIndex)++;
		printf("S %i, %i\n",WIndex,HIndex);
		IsNew(maze,HIndex,WIndex,Total); // Desides if new part in maze and adjusts Total
		*Dir = South;
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total, Mode);
		if (*Mode == Backward)
		{
			printf("N %i, %i\n",WIndex,HIndex);
		}
	}
	

	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, East) && (*Dir != West) && *Total)
	{
		// Go east 
		*Mode = Forward;
		(WIndex)++;
		printf("E %i, %i\n",WIndex,HIndex);
		IsNew(maze,HIndex,WIndex,Total); // Desides if new part in maze and adjusts Total
		*Dir = East;
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total, Mode);
		if (*Mode == Backward)
		{
			printf("W %i, %i\n",WIndex,HIndex);
		}
	}

	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, West) && (*Dir != East) && *Total)
	{
		// Go west 
		*Mode = Forward;
		(WIndex)--;
		printf("W %i, %i\n",WIndex,HIndex);
		IsNew(maze,HIndex,WIndex,Total); // Desides if new part in maze and adjusts Total
		*Dir = West;
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total, Mode);
		if (*Mode == Backward)
		{
			printf("E %i, %i\n",WIndex,HIndex);
		}
	}
	
	if (CanMove(maze, WIndex, HIndex, MaxW, MaxH, North) && (*Dir != South) && *Total)
	{
		// Go north 
		*Mode = Forward;
		(HIndex)--;
		printf("N %i, %i\n",WIndex,HIndex);
		IsNew(maze,HIndex,WIndex,Total); // Desides if new part in maze and adjusts Total
		*Dir = West;
		Move(maze, WIndex, HIndex, MaxW, MaxH, Dir, Total, Mode);
		if (*Mode == Backward)
		{
			printf("S %i, %i\n",WIndex,HIndex);
		}
	}
	// Resets direction to allow to move backwards
	*Mode = Backward;
	
}


int CanMove (char **maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction) // Decides if direction is possible
{
	switch (Direction)
	{
		case North :
			HIndex--;
			break ;
		case South :
			HIndex++;
			break ;
		case West :
			WIndex--;
			break ;
		case East :
			WIndex++;
			break ;
	}
	
	if ((WIndex >= 0) && (WIndex <= MaxW) && (HIndex >= 0) && (HIndex <= MaxH) && (maze[HIndex][WIndex] != 'X'))
	{ 
		return 1; // No wall and within range
	}
	return 0; //Can't move
}

void IsNew(char **maze,int HIndex,int WIndex,int *Total)
{
	if (maze[HIndex][WIndex] == ' ')
	{
		(*Total)--;
		maze[HIndex][WIndex] = '*';
	}
}


