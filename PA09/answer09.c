#include "answer09.h"
char * * explode(const char * str, const char * delims, int * arrLen);

BusinessNode * create_node(char * stars, char * name, char * address)
{
	// Allocates size for node
	BusinessNode *NewNode = malloc(sizeof(BusinessNode));
	// Doesn't need strdup, uses given pointers
	NewNode->stars = stars;
	NewNode->name = name;
	NewNode->address = address;
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;
	return  NewNode;
}


BusinessNode *tree_insert(BusinessNode * node, BusinessNode * root)
{

	if(strcmp(root->name,node->name) <= 0) //root before node, right side
	{
		if (root->right == NULL)
		{
			root->right = node;
		}
		else
		{
			tree_insert(node,root->right);
		}
	}
	else //root after node, left side
	{
		if (root->left == NULL)
		{
			root->left = node;
		}
		else
		{
			tree_insert(node,root->left);
		}
	}
	return root;
	
}


BusinessNode *load_tree_from_file(char * filename)
{
	FILE *fpt;
	char LineBuffer[150];
	char **SplitLineBuffer;
	BusinessNode *Root = NULL;
	char c;
	int index = 0, length =3;

	
	// Ensures file can open
	if ((fpt = fopen(filename,"r")) == NULL)
	{
		printf("Unable to open file\n");
		return NULL;
	}
	
	
	while (!feof(fpt))
	{
		while (((c = fgetc(fpt)) != '\n') && !feof(fpt)) // Gets one line of the file
		{
			LineBuffer[index++] = c;
		}

		SplitLineBuffer = explode(LineBuffer, "\t", &length); // Gets stars, name, and address
		
		printf("%s\n%s\n%s\n\n\n",SplitLineBuffer[0],SplitLineBuffer[1],SplitLineBuffer[2]);
		
		if (Root == NULL) // First value should be root
		{
			create_node(strdup(SplitLineBuffer[0]),strdup(SplitLineBuffer[1]),strdup(SplitLineBuffer[2]));
		}
		else // Otherwise insert
		{
			tree_insert(create_node(strdup(SplitLineBuffer[0]),strdup(SplitLineBuffer[1]),strdup(SplitLineBuffer[2])),Root);		
		}
		index = 0; // Resets index
	}
	fclose(fpt);
	return Root;
}


void destroy_tree(BusinessNode * root)
{
	// Goes to bottom left, then bottom right, and frees all nodes
	if (root->left != NULL)
	{
		destroy_tree(root->left);
	}
	if (root->right != NULL)
	{
		destroy_tree(root->right);
	}
	free(root->name);
	free(root->stars);
	free(root->address);
	free(root);
}


void print_node(BusinessNode * node)
{
	printf("Name: %s\nAddress: %s\n%s/5.0 stars\n\n",node->name,node->address,node->stars);
}

void print_tree2(BusinessNode * tree,int i) // i keeps track of how far down in tree
{
	// Prints nodes to left until null, then goes back up to right
	if (tree != NULL)
	{
		printf("%i\n",i++);
		print_node(tree);
	}
	if (tree->left != NULL)
	{
		printf("Left");
		print_tree2(tree->left,i);
	}
	if (tree->right != NULL)
	{
		printf("Right");
		print_tree2(tree->right,i);
	}
	
}


// Modified explode from PA03
char * * explode(const char * str, const char * delims, int * arrLen) // split str at delims for arrLen splits (+1)
{
	
	int StrLength = 0, StrIndex = 0, DelimsLength = 0, DelimsIndex = 0, MaxSize = 0, PrevDelim = 0;
	
	char **StrArr;
	int StrArrIndex = 0;
	
	int PrevDelimIndex = 0, CurrentSize = 0, StrNumber = 0;
	*arrLen = 0;
	
	
	StrLength = strlen(str); 
	DelimsLength = strlen(delims);

	// Computes number of rows (arrLen) and columns (MaxSize)
	for (StrIndex = 0; StrIndex <= StrLength; StrIndex++)
	{
		for (DelimsIndex = 0; DelimsIndex < DelimsLength; DelimsIndex++)
		{
			if (str[StrIndex] == delims[DelimsIndex])
			{
				*arrLen = *arrLen + 1;
				if (MaxSize < (StrIndex - PrevDelim))
				{	
					MaxSize = StrIndex - PrevDelim; // Perhaps -1
				}
				PrevDelim = StrIndex;
			}
		}
	}
	
	
	// Creates 2D array of appropriate length
	StrArr = malloc((*arrLen + 1) * sizeof(char*));  // Plus 1
	for (StrArrIndex = 0; StrArrIndex <= *arrLen; StrArrIndex++)
	{
		StrArr[StrArrIndex] = malloc(MaxSize * sizeof(char));
	}
	
	
		if (strcmp(delims,""))
	{
		strcpy(StrArr[0],str);
		return StrArr;
	}
	
	
	// Breaks up the str array and adds it to the 2D StrArr array
	PrevDelim = 0;
	for (StrIndex = 0; StrIndex <= StrLength; StrIndex++)
	{
		for (DelimsIndex = 0; DelimsIndex < DelimsLength; DelimsIndex++)
		{
			
			if ((str[StrIndex] == delims[DelimsIndex]) || (str[StrIndex] == '\0'))
			{
				// This is where the new string is actually created
				CurrentSize = StrIndex - PrevDelim;
				
				for (PrevDelimIndex = 0; PrevDelimIndex <= CurrentSize; PrevDelimIndex++)
				{
					if (PrevDelimIndex != CurrentSize)
					{
						StrArr[StrNumber][PrevDelimIndex] = str[PrevDelim + PrevDelimIndex];
					}
					if (PrevDelimIndex == CurrentSize)
					{
						StrArr[StrNumber][PrevDelimIndex] = '\0'; // Add end of string character after finsihed
					}
				}
				PrevDelim = StrIndex + 1; // +1 so the same value isn't repeated
				StrNumber++;
			}
		
		}
	}
		
	*arrLen = *arrLen + 1;
	
	return StrArr;
}

