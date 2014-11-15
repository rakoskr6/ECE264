/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>

struct YelpDataBST * CreateBusNode(char *name, uint32_t num_locations);
struct LocationID * CreateLocationNode(uint32_t BusinessID, char *address, char *city, uint32_t num_reviews, char *state, char *zip_code);
struct Review * CreateReviewNode(uint8_t stars, char *text);

struct YelpDataBST{ // Root of tree (may want to consider changing)
	struct BusinessID *BusinessInfoID;
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};
struct BusinessID{
	struct Business BusinessInfo; // Declares actual business
	struct LocationID* LocID; // Declares user created locationID
	
	char* name; // Will have to be stored in BusinessInfo
	uint32_t num_locations; // Will have to be stored in BusinessInfo
	
	
};
struct LocationID{ //Stores location and Business ID
	struct Location loc; // Declares actual location
	uint32_t BusID; // Actual BusinessID
	
	char* address; // to be copied to Location
	char* city; // to be copied to Location
	char* state; // to be copied to Location
	char* zip_code; // to be copied to Location
	struct Review* reviews; // to be copied to Location
	uint32_t num_reviews; // to be copied to Location
};

/******************* Functions *******************/
struct YelpDataBST * CreateBusNode(char *name, uint32_t num_locations)
{	// Creates new node with malloced memory, must pass string pointers with strdup
	
	// Allocates size for node and nodes contained inside them
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->BusinessInfoID = malloc(sizeof(struct BusinessID));
	NewNode->BusinessInfoID->BusinessInfo = malloc(sizeof(struct Business));
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;

	// BusinessID Info
	NewNode->BusinessInfoID->name = name;
	NewNode->BusinessInfoID->num_locations = num_locations;
	
	// Copies to BusinessInfo (not ever used, but required due to declaration in .h file)
	NewNode->BusinessInfoID->BusinessInfo->name = NewNode->BusinessInfoID->name ;
	NewNode->BusinessInfoID->BusinessInfo->num_locations = NewNode->BusinessInfoID->num_locations;
	return NewNode;
}

struct LocationID * CreateLocationNode(uint32_t BusID, char *address, char *city, uint32_t num_reviews, char *state, char *zip_code)
{	// Creates new node with malloced memory, must pass string pointers with strdup
	
	// Allocates size for node and nodes contained inside them
	struct LocationID *NewNode = malloc(sizeof(struct LocationID));
	NewNode->loc = malloc(sizeof(struct Location));
	

	// Business Info
	NewNode->BusinessID = BusinessID;
.
	
	// Location info
	NewNode->loc->address = address;
	NewNode->loc->city = city;
	NewNode->loc->num_reviews = num_reviews;
	NewNode->loc->state = state;
	NewNode->loc->zip_code = zip_code;

	return NewNode;
}
struct Review * CreateReviewNode(uint8_t stars, char *text)
{
	// Allocates size for node and nodes contained inside them
	struct Review *NewNode = malloc(sizeof(struct Review));
	
	// Review info
	NewNode->stars = stars;
	NewNode->text = text;

	return NewNode;
}


void print_node(struct YelpDataBST * node)
{
	printf("-----Business ID: %i-----\n",node->BusinessID);
	printf("Name: %s, Number of Locations: %i\n",node->BusinessInfo->name,node->BusinessInfo->num_locations);
	printf("Address: %s, City: %s, Number of reviews: %i ",node->BusinessInfo->locations->address,node->BusinessInfo->locations->city,node->BusinessInfo->locations->num_reviews);
	printf("State: %s, Zip code: %s\n",node->BusinessInfo->locations->state,node->BusinessInfo->locations->zip_code);
	printf("Stars: %i, Text: %s\n\n",node->BusinessInfo->locations->reviews->stars,node->BusinessInfo->locations->reviews->text);
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
