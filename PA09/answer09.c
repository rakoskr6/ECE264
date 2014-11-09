#include "answer09.h"

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
	// Also free name, stars, and address
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
