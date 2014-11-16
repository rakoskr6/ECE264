/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
struct YelpDataBST * CreateYelpNode(char *name, uint32_t BusID, char *address, char *city, char *state, char *zip_code);
void print_node(struct YelpDataBST * node);
void print_tree(struct YelpDataBST *tree);

typedef struct ReviewID {
	char* text;
	uint8_t stars;
	struct ReviewID *RevLeft;
	struct ReviewID *RevRight;
}ReviewID;

typedef struct LocationID {
	uint32_t BusID;
	char* address;
	char* city;
	char* state;
	char* zip_code;
	uint32_t num_reviews;
	ReviewID *Rev;
	struct LocationID *LocLeft;
	struct LocationID *LocRight;
	
}LocationID;

typedef struct BusinessID {
	char* name;
	uint32_t num_locations;
	LocationID *Loc; 
}BusinessID;

struct YelpDataBST{ 
	struct BusinessID *Bus;
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};

LocationID *CreateLocation(uint32_t BusID, char *address, char *city, char *state, char *zip_code);


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
	
	// Location Info
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
	
	// Location Info
	NewNode->BusID = BusID;
	NewNode->address = address;
	NewNode->city = city;
	NewNode->state = state;
	NewNode->zip_code = zip_code;	
	NewNode->num_reviews = 0;

	return NewNode;
}

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

void print_LocTree(struct LocationID *node)
{
	if (node != NULL)
		{
			print_Loc(node);
		
		}
		if ((node != NULL) && (node->LocLeft != NULL))
		{
			printf("Left");
			print_LocTree(node->LocLeft);
		}
		if ((node != NULL) && (node->LocRight != NULL))
		{
			printf("Right");
			print_LocTree(node->LocRight);
		}
}
void print_tree(struct YelpDataBST *tree)
{
	// Prints nodes to left until null, then goes back up to right
	if (tree != NULL)
	{
		print_Bus(tree);
		print_LocTree(tree->Bus->Loc);
		
	}
	if ((tree != NULL) && (tree->left != NULL))
	{
		printf("Left");
		print_tree(tree->left);
	}
	if ((tree != NULL) && (tree->right != NULL))
	{
		printf("Right");
		print_tree(tree->right);
	}
}

//struct YelpDataBST* create_business_bst(const char* businesses_path, const char* reviews_path) // loads information
//{
///* This function reads the two files and creates an index that can be used
 //* to search the data and quickly retrieve the reviews.  You must *not* store
 //* all of the review text in memory.  Your structure should store the file
 //* offsets where the review text can be found.
 //*/
 
  //Load all businesses as usual (make sure allowed to load whole file into binary tree)
 
  //Go line by line adding reviews. Star values stored and review text is a pointer
//}

//Business *tree_insert(struct YelpDataBST *node, struct YelpDataBST *root) // inserts business node into YelpDataBST
//{
	//// Insert business node sorting by business name->state->city->address->stars->review->text
	//// All except business name are case insensitive 
	//if (root == NULL)
	//{
		//return node;
	//}
	//if(strcmp(root->BusinessInfo->name,node->BusinessInfo->name) < 0) 
	//{
		//if (root->right == NULL)
		//{
			//root->right = node;
		//}
		//else
		//{
			//tree_insert(node,root->right);
		//}
	//}
	//else //root after node, left side
	//{
		//if (root->left == NULL)
		//{
			//root->left = node;
		//}
		//else
		//{
			//tree_insert(node,root->left);
		//}
	//}
	//return root;
	
//}


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
