#include "answer06.h"
#include <stdio.h>
#define None 0
#define South 1
#define North 2
#define West 3
#define East 4
#define Forward  1
#define Backward 0
void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir, int *Total, int *Mode, int *LastW, int *LastH, int *LastDir);
int CanMove (char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction, int *Total);
void IsNew(char **maze,int WIndex,int HIndex,int *Total);
void print_maze2(char** maze, int w, int h);
void BackPrint(int LastDir, int WIndex, int HIndex);


void print_directions(char** maze, int w, int h) 
{
	int WIndex, HIndex; // Indicies used in while loops
	int WStart; // Where to start the maze width
	int Total = 0; // Number of squares needed to cover
	int Direction = South; // Direction to go
	int Mode = Forward; // Either forward or backwards mode
	int LastW, LastH; // Location of index in previous stack
	int LastDir = None; // Direction went in previous call stack
	
	//printf("\e[1;1H\e[2J"); // Uncomment to clear screen before execution
	
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
	LastW = WIndex;
	LastH = HIndex;
	
	IsNew(maze,0,WStart,&Total); // Ensures entrance is counted
	print_maze2(maze, w, h);
	Move(maze, WIndex, HIndex, w, h, Direction, &Total, &Mode, &LastW, &LastH, &LastDir); 	
}


void Move(char ** maze, int WIndex, int HIndex, int MaxW, int MaxH, int Dir, int *Total, int *Mode, int *LastW, int *LastH, int *LastDir)
{
	if (*Total && CanMove(maze, WIndex, HIndex, MaxW, MaxH, South, Total) && (Dir != North))
	{
		// Go south 
		*Mode = Forward;
		//printf("S %i, %i\n",WIndex,HIndex);
		printf("S 1\n");
		print_maze2(maze, MaxW, MaxH);
		// Declares the previously used indicies
		*LastW = WIndex;
		*LastH = HIndex;
		Move(maze, WIndex, HIndex + 1, MaxW, MaxH, South, Total, Mode, LastW, LastH, LastDir);
		if ((*Mode == Backward) && *Total)
		{
			BackPrint(*LastDir, WIndex, HIndex);
		}
		
	}
	

	if (*Total && CanMove(maze, WIndex, HIndex, MaxW, MaxH, East, Total) && (Dir != West))
	{
		// Go east 
		*Mode = Forward;
		//printf("E %i, %i\n",WIndex,HIndex);
		printf("E 1\n");
		print_maze2(maze, MaxW, MaxH);
		// Declares the previously used indicies
		*LastW = WIndex;
		*LastH = HIndex;
		Move(maze, WIndex + 1, HIndex, MaxW, MaxH, East, Total, Mode, LastW, LastH, LastDir);
		if ((*Mode == Backward) && *Total)
		{
			BackPrint(*LastDir, WIndex, HIndex);
		}

	}

	if (*Total && CanMove(maze, WIndex, HIndex, MaxW, MaxH, West, Total) && (Dir != East))
	{
		// Go west 
		*Mode = Forward;
		//printf("W %i, %i\n",WIndex,HIndex);
		printf("W 1\n");
		print_maze2(maze, MaxW, MaxH);
		// Declares the previously used indicies
		*LastW = WIndex;
		*LastH = HIndex;
		Move(maze, WIndex - 1, HIndex, MaxW, MaxH, West, Total, Mode, LastW, LastH, LastDir);
		if ((*Mode == Backward) && *Total)
		{
			BackPrint(*LastDir, WIndex, HIndex);
		}
	}
	
	if (*Total && CanMove(maze, WIndex, HIndex, MaxW, MaxH, North, Total) && (Dir != South))
	{
		// Go north 
		
		*Mode = Forward;
		//printf("N %i, %i\n",WIndex,HIndex);
		printf("N 1\n");
		print_maze2(maze, MaxW, MaxH);
		// Declares the previously used indicies
		*LastW = WIndex;
		*LastH = HIndex;
		Move(maze, WIndex, HIndex - 1, MaxW, MaxH, North, Total, Mode, LastW, LastH, LastDir);
		if ((*Mode == Backward) && *Total)
		{
			BackPrint(*LastDir, WIndex, HIndex);
		}
	}
	
	// Resets direction to allow to move backwards
	*Mode = Backward;
	
	// Changes LastDir for use with Backwards mode
	*LastDir = Dir;


	
}


int CanMove (char **maze, int WIndex, int HIndex, int MaxW, int MaxH, int Direction, int *Total) // Decides if direction is possible
{
	switch (Direction)
	{
		case North:
			HIndex--;
			break;
		case South:
			HIndex++;
			break;
		case West:
			WIndex--;
			break;
		case East:
			WIndex++;
			break;
	}
	
	if ((WIndex >= 0) && (WIndex <= MaxW) && (HIndex >= 0) && (HIndex <= MaxH) && (maze[HIndex][WIndex] != 'X'))
	{ 
		IsNew(maze,HIndex,WIndex,Total); // Desides if new part in maze and adjusts Total
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

void print_maze2(char** maze, int w, int h) 
{
	return; //Delete this to print maze each step of the way
	int y=0;
	for(y=0; y <= h; y++) {
		printf("%s\n", maze[y]);
	}
	printf("\n");
}

void BackPrint(int LastDir, int WIndex, int HIndex)
{
	switch (LastDir)
	{
		case North:
		//printf("S %i, %i\n",WIndex,HIndex);
		printf("S 1\n");
			break;
		case South:
		//printf("N %i, %i\n",WIndex,HIndex);
		printf("N 1\n");
			break;
		case West:
		//printf("E %i, %i\n",WIndex,HIndex);
		printf("E 1\n");
			break;
		case East:
		//printf("W %i, %i\n",WIndex,HIndex);
		printf("W 1\n");
			break;
	}
}