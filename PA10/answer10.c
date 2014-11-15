/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
struct YelpDataBST * CreateYelpNode(uint32_t BusID, char *name, uint32_t num_locations, char *address, char *city, char *state, char *zip_code, uint32_t num_reviews);
void print_nodeNew(struct YelpDataBST * node);
void print_nodeOld(struct YelpDataBST * node);


struct YelpDataBST{ // Root of tree (may want to consider changing)
	uint32_t BusID;
	struct Business *Bus;
	struct Location *Loc;
	struct Review *Rev;
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};


/******************* Functions *******************/
struct YelpDataBST * CreateYelpNode(uint32_t BusID, char *name, uint32_t num_locations, char *address, char *city, char *state, char *zip_code, uint32_t num_reviews)
{	// Creates new Yelp Node if this is a newly created business, must pass string pointers with strdup
	
	// Allocates size for nodes and adds data (no reviews added now)
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->Bus = malloc(sizeof(struct Business));
	NewNode->Loc = malloc(sizeof(struct Location));
	NewNode->BusID = BusID;
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;

	// Business Info
	NewNode->Bus->name = name;
	NewNode->Bus->num_locations = num_locations;
	NewNode->Bus->locations = NewNode->Loc; // Points to locations node in YelpDataBST
	
	// Location Info
	NewNode->Loc->address = address;
	NewNode->Loc->city = city;
	NewNode->Loc->state = state;
	NewNode->Loc->zip_code = zip_code;
	NewNode->Loc->num_reviews = num_reviews;
	NewNode->Loc->reviews = NewNode->Rev; // Points to review node in YelpDataBST

	return NewNode;
}

void print_nodeNew(struct YelpDataBST * node) // Prints node using only YelpDataBST
{
	printf("-----Print New - Business ID: %i-----\n",node->BusID);
	printf("Name: %s, Number of Locations: %i\n",node->Bus->name,node->Bus->num_locations);
	printf("Address: %s, City: %s, Number of reviews: %i ",node->Loc->address,node->Loc->city,node->Loc->num_reviews);
	printf("State: %s, Zip code: %s\n",node->Loc->state,node->Loc->zip_code);
	//printf("Stars: %i, Text: %s\n\n",node->Rev->stars,node->Rev->text);
}

void print_nodeOld(struct YelpDataBST * node) // Prints node going fully through binary tree
{
	printf("-----Print Old - Business ID: %i-----\n",node->BusID);
	printf("Name: %s, Number of Locations: %i\n",node->Bus->name,node->Bus->num_locations);
	printf("Address: %s, City: %s, Number of reviews: %i ",node->Bus->locations->address,node->Bus->locations->city,node->Bus->locations->num_reviews);
	printf("State: %s, Zip code: %s\n",node->Bus->locations->state,node->Bus->locations->zip_code);
	//printf("Stars: %i, Text: %s\n\n",node->Bus->locations->reviews->stars,node->Bus->locations->reviews->text);
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
