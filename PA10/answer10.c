/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/******************* Functions *******************/
struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path) 
{// Loads all businesss and reviews into YelpDataBST structure
	FILE *fp, *fp2;
	char LineBuffer[300], c, *BusID = "0", *Name, *Address,*City, *State;
	struct YelpDataBST *Root = NULL;
	int index = 0, LineStart = 0, BusIDL, NameL, AddressL, CityL, StateL, ZipL;

	int LocNumber = 0;
	
	//char *BusIDRev = "0", *Stars, *Funny, *Useful, *Cool, LineBuffer2[6000];
	//int BusIDRevL, StarsL, FunnyL, UsefulL, CoolL, TextL, index2 = 0, LineStart2 = 0;

	// Ensures file can open
	if (((fp = fopen(businesses_path,"r")) == NULL) || ((fp2 = fopen(reviews_path,"r")) == NULL))
	{
		printf("Unable to open file\n");
		return NULL;
	}
	
	// Reads file
	while (!feof(fp))
	{
		LineStart = ftell(fp); // gets location at start of reading line
		while (((c = fgetc(fp)) != '\n') && !feof(fp)) // Gets one line of the file
		{
			LineBuffer[index++] = c;
		}
		LineBuffer[index] = '\0'; // Terminates string
		index = 0; // Resets index
		
		if (strlen(LineBuffer) > 0) // ensures line read isn't blank
		{
			// Gets individual strings
			BusID = strtok(LineBuffer,"\t");
			Name = strtok(NULL,"\t");
			Address = strtok(NULL,"\t");
			City = strtok(NULL,"\t");
			State = strtok(NULL,"\t");
			//Zip = strtok(NULL,"\t");
			
			// Converts strings to offsets (line offset + string lengths + null character)
			BusIDL	 	= LineStart;
			NameL 		= BusIDL + strlen(BusID) + 1;
			AddressL 	= NameL + strlen(Name) + 1;
			CityL 		= AddressL + strlen(Address) + 1;
			StateL 		= CityL + strlen(City) + 1;
			ZipL		= StateL + strlen(State) + 1;
			
			Root = Insert(Root, BusIDL, strdup(Name), AddressL, CityL, StateL, ZipL, &LocNumber);
			
		}
	}
	
	return Root;
}


struct YelpDataBST *Insert(struct YelpDataBST *root, uint32_t BusIDL, char *name, uint32_t addressL, uint32_t cityL, uint32_t stateL, uint32_t zip_codeL, int *LocNumber)
{	// Adds or creates new location from given data
	struct YelpDataBST *BusExists = BusExist(name,root);
	int index = 0;
	if (BusExists == NULL) // Create first business location
	{
		struct YelpDataBST *NewBus = CreateYelpNode(name);
		NewBus->Locations[0] = CreateLocInfo(BusIDL, addressL, cityL, stateL, zip_codeL);
		root = Bus_insert(NewBus,root);
	}
	else // Add new business to location
	{
		free(name); // no longer need name since business already exists
		BusExists->num_locations++;
		while (BusExists->Locations[index] == NULL)
		{
			if (BusExists->Locations[++index] != NULL)
			{
				BusExists->Locations[index] = CreateLocInfo(BusIDL, addressL, cityL, stateL, zip_codeL);
			}
		}
		*LocNumber = index;
	}
	return root;
}


struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root) 
{	// checks if the business name already exists
	if (root == NULL)
	{
		return NULL; // Never found, return NULL
	}
	char *NameComp = root->name;
	int cmp = strcmp(NameComp,name);
	if (cmp == 0) // found, return 1
	{
		return root;
	}
	else if (cmp < 0) // root before node, go right
	{
		return BusExist(name,root->right);
	}
	
	return BusExist(name,root->left);
}


struct YelpDataBST *CreateYelpNode(char *name)
{	// Creates new Yelp Node (and Business and Location node), doesn't add reviews
	int index = 0;
	// Allocates size for nodes and adds data
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;
	
	// Business Info
	NewNode->name = name;
	NewNode->num_locations = 1;
	
	for (index = 0; index < 500; index++)
	{
		NewNode->Locations[index] = NULL;
	}
	return NewNode;
}

LocInfo *CreateLocInfo(uint32_t BusID, uint32_t address, uint32_t city, uint32_t state, uint32_t zip_code)
{
	int index = 0;
	LocInfo *NewNode = malloc(sizeof(LocInfo));
	NewNode->BusID = BusID;
	NewNode->address = address;
	NewNode->city = city;
	NewNode->state = state;
	NewNode->zip_code = zip_code;
	
	for (index = 0; index < 500; index++)
	{
		NewNode->Reviews[index] = NULL;
	}
	
	return NewNode;
}

ReviewInfo *CreateReviewInfo(uint32_t text, uint32_t stars)
{	// Creates new Review Node
	ReviewInfo *NewNode = malloc(sizeof(ReviewInfo));
	NewNode->text = text;
	NewNode->stars = stars;
	return NewNode;
}

struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root)
{	// Insert business node sorting by business name (case insensitive)<-double check
	if (root == NULL)
	{
		return node;
	}
	
	char *NameComp = node->name;
	char *Name = root->name;

	if(strcmp(Name, NameComp) < 0)  // root before node, right side
	{
		if (root->right == NULL)
		{
			root->right = node;
		}
		else
		{
			Bus_insert(node,root->right);
		}
	}
	else if(strcmp(Name, NameComp) > 0) //root after node, left side
	{
		if (root->left == NULL)
		{
			root->left = node;
		}
		else
		{
			Bus_insert(node,root->left);
		}
	}

	return root;
}


void destroy_business_bst(struct YelpDataBST* bst)
{ // Frees all memory from YelpDataBST
	if (bst == NULL)
	{
		return;
	}
 	// Goes to bottom left, then bottom right, and frees all nodes
	destroy_business_bst(bst->left);
	
	destroy_business_bst(bst->right);
	
	int index = 0;
	while(bst->Locations[index] != NULL)
	{
		DestroyReviews(bst->Locations[index]);
		free(bst->Locations[index]);
		index++;
	}	
	
	free(bst->name);
	free(bst);
}


void DestroyReviews(LocInfo *node)
{
	int index = 0;
	while(node->Reviews[index] != NULL)
	{
		free(node->Reviews[index]);
		index++;
	}
}


void print_tree(struct YelpDataBST *tree)
{// Prints every business and location
	int index = 0, index2 = 0;
	// Prints nodes to left until null, then goes back up to right
	if (tree != NULL)
	{
		printf("----- Business Name: %s (%i locations) -----\n",tree->name,tree->num_locations);
	
	while (tree->Locations[index] != NULL)
	{
		printf("BusID: %i, Address: %i, City: %i, State: %i, Zip: %i, Reviews: %i\n",tree->Locations[index]->BusID, tree->Locations[index]->address, tree->Locations[index]->city, tree->Locations[index]->state, tree->Locations[index]->zip_code, tree->Locations[index]->num_reviews);
		while (tree->Locations[index]->Reviews[index2] != NULL)
		{
			printf("Text: %i, Stars %i\n\n",tree->Locations[index]->Reviews[index2]->text,tree->Locations[index]->Reviews[index2]->stars);
			index2++;
		}
		index++;
	}
	
	}
	if ((tree != NULL) && (tree->left != NULL))
	{
		printf("Left\n");
		print_tree(tree->left);
	}
	if ((tree != NULL) && (tree->right != NULL))
	{
		printf("Right\n");
		print_tree(tree->right);
	}
}
