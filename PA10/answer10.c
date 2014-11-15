#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
struct Business *tree_insert(struct Business * node, struct Business * root);
struct YelpDataBST * create_node(char *name, uint32_t num_locations, char *address, char *city, uint32_t num_reviews, char *state, char *zip_code, uint32_t stars, char *text);

struct YelpDataBST{ // Root of tree (may want to consider changing)
	
	struct Business *BusinessInfo;
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};


//struct YelpDataBST* create_business_bst(const char* businesses_path, const char* reviews_path) // loads information
//{
///* This function reads the two files and creates an index that can be used
 //* to search the data and quickly retrieve the reviews.  You must *not* store
 //* all of the review text in memory.  Your structure should store the file
 //* offsets where the review text can be found.
 //*/
 
 //// Load all businesses as usual (make sure allowed to load whole file into binary tree)
 
 //// Go line by line adding reviews. Star values stored and review text is a pointer
//}

//Business *tree_insert(Business * node, Business * root) // inserts business node into YelpDataBST
//{
	//if (root == NULL)
	//{
		//return node;
	//}
	//if(strcmp(root->name,node->name) < 0) 
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

struct YelpDataBST * create_node(char *name, uint32_t num_locations, char *address, char *city, uint32_t num_reviews, char *state, char *zip_code, uint32_t stars, char *text) 
{	// Creates new node with malloced memory, must pass string pointers with strdup
	
	// Allocates size for node and nodes contained inside them
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->BusinessInfo = malloc(sizeof(struct Business));
	NewNode->BusinessInfo->locations= malloc(sizeof(struct Location)); // will need to figure out how to handle multiple locations
	NewNode->BusinessInfo->locations->reviews = malloc(sizeof(struct Review)); // will need to figure out how to handle multiple reviews
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;

	// Business Info
	NewNode->BusinessInfo->name = name;
	NewNode->BusinessInfo->num_locations = num_locations;
	
	// Location info
	NewNode->BusinessInfo->locations->address = address;
	NewNode->BusinessInfo->locations->city = city;
	NewNode->BusinessInfo->locations->num_reviews = num_reviews;
	NewNode->BusinessInfo->locations->state = state;
	NewNode->BusinessInfo->locations->zip_code = zip_code;
	
	// Review info
	NewNode->BusinessInfo->locations->reviews->stars = stars;
	NewNode->BusinessInfo->locations->reviews->text = text;

	return  NewNode;
}

void print_node(struct YelpDataBST * node)
{
	printf("Name: %s, Number of Locations: %i\n",node->BusinessInfo->name,node->BusinessInfo->num_locations);
	printf("Address: %s, City: %s, Number of reviews: %i ",node->BusinessInfo->locations->address,node->BusinessInfo->locations->city,node->BusinessInfo->locations->num_reviews);
	printf("State: %s, Zip code: %s\n",node->BusinessInfo->locations->state,node->BusinessInfo->locations->zip_code);
	printf("Stars: %i, Text: %s\n",node->BusinessInfo->locations->reviews->stars,node->BusinessInfo->locations->reviews->text);
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
