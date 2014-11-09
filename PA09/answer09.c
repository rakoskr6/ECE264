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
	if(strcmp(root->name,node->name) > 0)//root before node, right side
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
	return node;
	
}

void print_node(BusinessNode * node)
{
	printf("Name: %s\nAddress: %s\n%s/5.0 stars\n\n",node->name,node->address,node->stars);
}

void print_tree2(BusinessNode * tree,int i)
{
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
