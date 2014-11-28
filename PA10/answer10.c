/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/******************* Functions *******************/
struct YelpDataBST * CreateYelpNode(char *name, uint32_t BusID, char *address, char *city, char *state, char *zip_code)
{	// Creates new Yelp Node, doesn't add reviews, must pass string pointers with strdup
	
	// Allocates size for nodes and adds data
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->Bus = malloc(sizeof(BusinessID));
	NewNode->Bus->Loc = malloc(sizeof(LocationID)); 

	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->Bus->Loc->LocLeft = NULL;
	NewNode->Bus->Loc->LocRight = NULL;
	NewNode->Bus->Loc->Rev = NULL;
	
	// Business Info
	NewNode->Bus->name = name;
	NewNode->Bus->num_locations = 1;
	
	// Location Info (change to store pointers instead)
	NewNode->Bus->Loc->BusID = BusID;
	NewNode->Bus->Loc->address = address;
	NewNode->Bus->Loc->city = city;
	NewNode->Bus->Loc->state = state;
	NewNode->Bus->Loc->zip_code = zip_code;
	NewNode->Bus->Loc->num_reviews = 0;
	

	return NewNode;
}


struct LocationID *CreateLocation(uint32_t BusID, char *address, char *city, char *state, char *zip_code)
{	// Creates new Location Node, doesn't add reviews, must pass string pointers with strdup
		
	// Allocates size for nodes and adds data
	LocationID *NewNode = malloc(sizeof(struct LocationID));

	// Makes next nodes null
	NewNode->LocLeft = NULL;
	NewNode->LocRight = NULL;
	NewNode->Rev = NULL;
	
	// Location Info (change to store pointers (as shown in above function))
	NewNode->BusID = BusID;
	NewNode->address = address;
	NewNode->city = city;
	NewNode->state = state;
	NewNode->zip_code = zip_code;	
	NewNode->num_reviews = 0;

	return NewNode;
}


struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root) // checks if the business name already exists
{
	if (root == NULL)
	{
		return NULL; // Never found, return NULL
	}
	int cmp = strcmp(root->Bus->name,name);
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

struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root) // inserts business node into YelpDataBST if business is new
{
	// Insert business node sorting by business name (case insensitive)
	
	
	if (root == NULL)
	{
		return node;
	}
	if(strcmp(root->Bus->name,node->Bus->name) < 0) 
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
	else if(strcmp(root->Bus->name,node->Bus->name) > 0) //root after node, left side
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


struct LocationID *Loc_insert(LocationID *node, LocationID *root) // inserts location node into YelpDataBST if business exists
{
	// Insert location node sorting by state->city->address (case insensitive)
	
	if(strcasecmp(root->state,node->state) < 0) 
	{
		if (root->LocRight == NULL)
		{
			root->LocRight = node;
		}
		else
		{
			Loc_insert(node,root->LocRight);
		}
	}
	else if(strcasecmp(root->state,node->state) > 0) //root after node, left side
	{
		if (root->LocLeft == NULL)
		{
			root->LocLeft = node;
		}
		else
		{
			Loc_insert(node,root->LocLeft);
		}
	}
	else // nodes equal, now check city
	{
		if(strcasecmp(root->city,node->city) < 0) 
		{
			if (root->LocRight == NULL)
			{
				root->LocRight = node;
			}
			else
			{
				Loc_insert(node,root->LocRight);
			}
		}
		else if(strcasecmp(root->city,node->city) > 0) //root after node, left side
		{
			if (root->LocLeft == NULL)
			{
				root->LocLeft = node;
			}
			else
			{
				Loc_insert(node,root->LocLeft);
			}
		}
		else // nodes still equal, now check address
		{
			if(strcasecmp(root->address,node->address) < 0) 
			{
				if (root->LocRight == NULL)
				{
					root->LocRight = node;
				}
				else
				{
					Loc_insert(node,root->LocRight);
				}
			}
			else //root after node, left side
			{
				if (root->LocLeft == NULL)
				{
					root->LocLeft = node;
				}
				else
				{
					Loc_insert(node,root->LocLeft);
				}
			}
		}
	}
	
	return root;
	
}

struct YelpDataBST *Insert(struct YelpDataBST *root, char *name, uint32_t BusID, char *address, char *city, char *state, char *zip_code)
{	
	struct YelpDataBST *LocExists = BusExist(name,root);
	if (LocExists == NULL)
	{
		root = Bus_insert(CreateYelpNode(name,BusID,address,city,state,zip_code),root);
	}
	else
	{
		LocExists->Bus->num_locations++;
		LocExists->Bus->Loc = Loc_insert(CreateLocation(BusID, address,city,state,zip_code),LocExists->Bus->Loc);
	}
	return root;
	
}

struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path) // loads information
{
	FILE *fp;
	char LineBuffer[170];
	char *BusIDTemp, *Name, *Address,*City, *State, *Zip;
	uint32_t BusID;
	struct YelpDataBST *Root = NULL;
	char c;
	int index = 0;
	
	int i = 0;

	// Ensures file can open
	if ((fp = fopen(businesses_path,"r")) == NULL)
	{
		printf("Unable to open file\n");
		return NULL;
	}
	
	while (!feof(fp))
	{
		i++;
		while (((c = fgetc(fp)) != '\n') && !feof(fp)) // Gets one line of the file
		{
			LineBuffer[index++] = c;
		}
		LineBuffer[index] = '\0'; // Terminates string
		
		if (strlen(LineBuffer) > 0)
		{
			// Gets individual strings
			BusIDTemp = strtok(LineBuffer,"\t");
			Name = strtok(NULL,"\t");
			Address = strtok(NULL,"\t");
			City = strtok(NULL,"\t");
			State = strtok(NULL,"\t");
			Zip = strtok(NULL,"\t");
			
			BusID = atoi(BusIDTemp);
			Root = Insert(Root,strdup(Name),BusID, strdup(Address), strdup(City), strdup(State), strdup(Zip));		

			index = 0; // Resets index
		}
	}
	fclose(fp);
	return Root;
}




//struct Business* get_business_reviews(struct YelpDataBST* bst,
                                      //char* name, char* state, char* zip_code);
///* get_reviews(..) should return a pointer to a Business struct object
 //* on the heap.  That object will include links to the individual locations.
 //* For example, if "McDonald's" is the business, then there would be thousands
 //* of locations.  Each Location struct object in turn contains links to
 //* reviews of that location.
 //*
 //* bst - the object returned by create_business_bst(..)
 //* name - name of the business to search for (e.g., "McDonald's"); search is
 //*     case insensitive.
 //* state - two-letter (uppercase) state code to filter locations by, or NULL
 //*     to include all states.
 //* zip_code - five digit ZIP code to filter locations by, or NULL to include
 //*     all ZIP codes.
 //*
 //* Locations must be sorted by state >> city >> address.
 //*
 //* Reviews must be sorted by star rating (descending) >> text of review.
 //*
 //* Matching of names, cities, and states must be case-insensitive.  You
 //* may use functions from strings.h for that, if you wish.
 //*/


//void destroy_business_bst(struct YelpDataBST* bst);
///* Deallocate all memory allocated by the object returned
 //* by create_business_bst(..) and close the files. */

//void destroy_business_result(struct Business* b);
///* Deallocate all heap memory tied to an object returned
 //* by get_business_reviews(..). */



void print_Bus(struct YelpDataBST * node)
{
	printf("----- Business Name: %s (%i locations) -----\n\n",node->Bus->name,node->Bus->num_locations);
}

void print_Loc(struct LocationID * node)
{
	printf("ID: %i, Address: %s, City: %s, State: %s, Zip: %s ",node->BusID, node->address,node->city,node->state,node->zip_code);
	printf("Number of reviews: %i\n\n",node->num_reviews);
	//printf("Stars: %i, Text: %s\n\n",node->Bus->locations->reviews->stars,node->Bus->locations->reviews->text);
}

void print_LocTree(struct LocationID *node, int i)
{
	if (node != NULL)
		{
			print_Loc(node);
		
		}
		if ((node != NULL) && (node->LocLeft != NULL))
		{
			printf("Left %i\n",i++);
			print_LocTree(node->LocLeft, i);
		}
		if ((node != NULL) && (node->LocRight != NULL))
		{
			printf("Right %i\n",i++);
			print_LocTree(node->LocRight, i);
		}
}
void print_tree(struct YelpDataBST *tree, int i)
{
	// Prints nodes to left until null, then goes back up to right
	if (tree != NULL)
	{
		print_Bus(tree);
		print_LocTree(tree->Bus->Loc,i);
		
	}
	if ((tree != NULL) && (tree->left != NULL))
	{
		printf("Left %i\n",i);
		print_tree(tree->left, i);
	}
	if ((tree != NULL) && (tree->right != NULL))
	{
		printf("Right %i\n",i);
		print_tree(tree->right, i);
	}
}
