#include "answer11.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void InsertNode(HuffNode *First, HuffNode *Second);

HuffNode * HuffNode_create(int value)
{
	HuffNode *node = malloc(sizeof(HuffNode));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return node;
}


void HuffNode_destroy(HuffNode * tree)
{// Goes to bottom left, then bottom right, and frees all nodes
	if ((tree != NULL) && (tree->left != NULL))
	{
		destroy_tree(tree->left);
	}
	if ((tree != NULL) && (root->tree != NULL))
	{
		destroy_tree(tree->right);
	}
	if (tree != NULL)
	{
		free(tree);
	}
}


Stack * Stack_create()
{
	Stack *node = malloc(sizeof(Stack));
	return node;
	
}


void Stack_destroy(Stack * stack)
{
	while (stack != NULL)
	{
		Stack *ptr = stack->next;
		HuffNode_destroy(stack->tree);
		free(stack);
		stack = ptr;
	}
}


int Stack_isEmpty(Stack * stack)
{
	if (stack == NULL)
	{
		return 1; // stack's empty, return true
	}
	else
	{
		return 0; // else it's not empty, return false
	}
}


HuffNode * Stack_popFront(Stack * stack)
{
	HuffNode *node = stack->tree;
	Stack *ptr = stack->next;
	free(stack);
	stack = ptr; // makes stack point to next node	
	return node;
}


void Stack_pushFront(Stack * stack, HuffNode * tree)
{
	Stack *node = Stack_create();
	node->tree = tree;
	node->next = stack; // new node points to previous first node
	stack = node; // stack now points to new node
}


void Stack_popPopCombinePush(Stack * stack)
{
	HuffNode *FirstNode = Stack_popFront(stack);
	HuffNode *SecondNode = Stack_popFront(stack);
	InsertNode(FirstNode, SecondNode); // Combine nodes
	Stack_pushFront(FirstNode); // push first node (now already combined)
	
	
}

void InsertNode(HuffNode *First, HuffNode *Second)
{
	if(SecondNode->value <= FirstNode->Value) // Less than or equal, go left 
	{
		if (FirstNode->left == NULL)
		{
			FirstNode->left = SecondNode;
		}
		else
		{
			InsertNode(First->left, Second);
		}
	}
	else //greater than, right side
	{
		if (FirstNode->right == NULL)
		{
			FirstNode->right = SecondNode;
		}
		else
		{
			InsertNode(First->right, Second);
		}
	}
}
