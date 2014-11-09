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
	if(strcmp(root->name,node->name) > //root before node, right side
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
	
}
