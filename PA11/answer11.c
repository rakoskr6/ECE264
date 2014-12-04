#include "answer11.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//void InsertNode(HuffNode *First, HuffNode *Second);

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
		HuffNode_destroy(tree->left);
	}
	if ((tree != NULL) && (tree->right != NULL))
	{
		HuffNode_destroy(tree->right);
	}
	if (tree != NULL)
	{
		free(tree);
	}
}


Stack * Stack_create()
{
	Stack *node = malloc(sizeof(Stack));
	node->head = NULL;
	return node;
	
}


void Stack_destroy(Stack * stack)
{
	while (stack->head != NULL)
	{
		StackNode *ptr = stack->head->next;
		HuffNode_destroy(stack->head->tree);
		free(stack->head);
		stack->head = ptr;
	}
	free(stack);
}


int Stack_isEmpty(Stack * stack)
{
	if ((stack == NULL) || (stack->head == NULL))
	{
		return 1; // stack's empty, return true
	}
	else
	{
		return 0; // else it's not empty, return false
	}
}


int Stack_isEmpty1(Stack * stack)
{
	if ((stack->head->next == NULL))
	{
		return 1; // stack's empty, return true
	}
	else
	{
		return 0; // else it's not empty, return false
	}
}ANSWER11_H

HuffNode * Stack_popFront(Stack * stack)
{
	HuffNode *node = stack->head->tree;
	StackNode *ptr = stack->head->next;
	free(stack->head);
	stack->head = ptr; // makes stack point to next node	
	return node;
}


void Stack_pushFront(Stack * stack, HuffNode * tree)
{
	StackNode *node = malloc(sizeof(StackNode));
	node->tree = tree;
	node->next = stack->head; // new node points to previous first node
	stack->head = node; // stack now points to new node
}


void Stack_popPopCombinePush(Stack * stack)
{
	HuffNode *FirstNode = Stack_popFront(stack);
	HuffNode *SecondNode = Stack_popFront(stack);
	HuffNode *Top = HuffNode_create(0);
	Top->left = SecondNode;
	Top->right = FirstNode;

	Stack_pushFront(stack, Top);
	
	
}

/*
void InsertNode(HuffNode *FirstNode, HuffNode *SecondNode)
{
	if(SecondNode->value <= FirstNode->value) // Less than or equal, go left 
	{
		if (FirstNode->left == NULL)
		{
			FirstNode->left = SecondNode;
		}
		else
		{
			InsertNode(FirstNode->left, SecondNode);
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
			InsertNode(FirstNode->right, SecondNode);
		}
	}
}
*/

HuffNode * HuffTree_readTextHeader(FILE * fp)
{
	char Text[1000], c;
	int index = 0, Max = 0;
	HuffNode *node;
	Stack *stack = Stack_create();
	
	while(feof(fp) == 0)
	{
		Text[index++] = fgetc(fp);
	}
	Max = index - 1;
	
	for (index = 0; index <= Max; index++)
	{
		//if ((Stack_isEmpty(stack) != 1) || (index == 0))
		//{
			c = Text[index];
			
			if (c == '1') // then push
			{
				index++;
				node = HuffNode_create(Text[index]);
				Stack_pushFront(stack, node);
			}
			else if (c == '0') // then pop-pop-combine-push
			{
				if (Stack_isEmpty1(stack) == 1) // stack is empty
				{
					node = Stack_popFront(stack);
					Stack_destroy(stack);
					fseek(fp,index,SEEK_SET);
					return node;
				}
				else
				{
					Stack_popPopCombinePush(stack);
				}
			}
		//}
	}
	
	
	return NULL;
}
HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
	HuffNode *rand;
	return rand;
}
