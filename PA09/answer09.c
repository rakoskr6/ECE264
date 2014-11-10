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
	char *stars,*name,*address;
	BusinessNode *Root = NULL;
	char c;
	int index = 0;

	
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
		LineBuffer[index] = '\0'; // Terminates string
		
		if (strlen(LineBuffer) > 0)
		{
			// Gets individual strings
			stars = strtok(LineBuffer,"\t");
			name = strtok(NULL,"\t");
			address = strtok(NULL,"\t");

		
			//printf("%s\n%s\n%s\n\n\n",stars,name,address);
		
			if (Root == NULL) // First value should be root
			{
				Root = create_node(strdup(stars),strdup(name),strdup(address));
			}
			else // Otherwise insert
			{
				tree_insert(create_node(strdup(stars),strdup(name),strdup(address)),Root);		
			}
			index = 0; // Resets index
		}
	}
	fclose(fpt);
	return Root;
}


void destroy_tree(BusinessNode * root)
{
	// Goes to bottom left, then bottom right, and frees all nodes
	if ((root != NULL) && (root->left != NULL))
	{
		destroy_tree(root->left);
	}
	if ((root != NULL) && (root->right != NULL))
	{
		destroy_tree(root->right);
	}
	if (root != NULL)
	{
		free(root->name);
		free(root->stars);
		free(root->address);
		free(root);
	}
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
	if ((tree != NULL) && (tree->left != NULL))
	{
		printf("Left");
		print_tree2(tree->left,i);
	}
	if ((tree != NULL) && (tree->right != NULL))
	{
		printf("Right");
		print_tree2(tree->right,i);
	}
	
}
