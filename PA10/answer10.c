/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/******************* Functions *******************/
struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path) 
{// Loads all businesss and reviews into YelpDataBST structure
	FILE *fp;
	char LineBuffer[170], c, *BusID, *Name, *Address,*City, *State;
	struct YelpDataBST *Root = NULL;
	int index = 0, LineStart = 0, BusIDL, NameL, AddressL, CityL, StateL, ZipL;

	// Ensures file can open
	if ((fp = fopen(businesses_path,"r")) == NULL)
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
		
		if (strlen(LineBuffer) > 0)
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
			
		/*	// Uncoments to print 
			char *BusP, *NameP, *AddP, *CityP, *StateP, *ZipP;
			printf("%s, %s, %s\n",BusP = OffsetToString(BusIDL,businesses_path), NameP = OffsetToString(NameL,businesses_path), AddP = OffsetToString(AddressL,businesses_path));
			printf("%s, %s, %s\n\n",CityP = OffsetToString(CityL,businesses_path), StateP = OffsetToString(StateL,businesses_path), ZipP = OffsetToString(ZipL,businesses_path));
			free(BusP);
			free(NameP);
			free(AddP);
			free(CityP);
			free(StateP);
			free(ZipP);
			*/
			
			// Adds offset data to YelpDataBST
			Root = Insert(Root,NameL,BusIDL, AddressL, CityL, StateL, ZipL); // consider passing review info to add reviews in insert function
		}
	}
	fclose(fp); // close Business file
}


struct YelpDataBST *Insert(struct YelpDataBST *root, int nameL, int BusIDL, int addressL, int cityL, int stateL, int zip_codeL)
{	// Adds or creates new location from given data
	char *BusName = OffsetToString(nameL,BusPath);
	struct YelpDataBST *BusExists = BusExist(BusName,root);
	free(BusName);

	if (BusExists == NULL) // Create first business location
	{
		root = Bus_insert(CreateYelpNode(nameL,BusIDL,addressL,cityL,stateL,zip_codeL),root);
	}
	else // Add new business to location
	{
		BusExists->Bus->num_locations++;
		BusExists->Bus->Loc = Loc_insert(CreateLocation(BusIDL, addressL,cityL,stateL,zip_codeL),BusExists->Bus->Loc);
	}
	return root;
	
}


struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root) // checks if the business name already exists
{	
	if (root == NULL)
	{
		return NULL; // Never found, return NULL
	}
	char *NameComp = OffsetToString(root->Bus->name,BusPath);
	int cmp = strcmp(NameComp,name);
	if (cmp == 0) // found, return 1
	{
		free(NameComp);
		return root;
	}
	else if (cmp < 0) // root before node, go right
	{
		free(NameComp);
		return BusExist(name,root->right);
	}
	
	free(NameComp);
	return BusExist(name,root->left);
}


struct YelpDataBST * CreateYelpNode(int nameL, int BusIDL, int addressL, int cityL, int stateL, int zip_codeL)
{	// Creates new Yelp Node (and Business and Location node), doesn't add reviews
	
	// Allocates size for nodes and adds data
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->Bus = malloc(sizeof(BusinessID));
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;
	
	// Business Info
	NewNode->Bus->name = nameL;
	NewNode->Bus->num_locations = 1;
	
	// Location Info 
	NewNode->Bus->Loc = CreateLocation(BusIDL,addressL, cityL, stateL, zip_codeL);
	
	return NewNode;
}


struct LocationID *CreateLocation(int BusIDL, int addressL, int cityL, int stateL, int zip_codeL)
{	// Creates new Location Node, doesn't add reviews
		
	// Allocates size for nodes and adds data
	LocationID *NewNode = malloc(sizeof(struct LocationID));

	// Makes next nodes null
	NewNode->LocLeft = NULL;
	NewNode->LocRight = NULL;
	NewNode->Rev = NULL;
	
	// Location Info
	NewNode->BusID = BusIDL;
	NewNode->address = addressL;
	NewNode->city = cityL;
	NewNode->state = stateL;
	NewNode->zip_code = zip_codeL;	
	NewNode->num_reviews = 0;

	return NewNode;
}


struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root)
{	// Insert business node sorting by business name (case insensitive)<-double check
	
	if (root == NULL)
	{
		return node;
	}
	
	char *NameComp = OffsetToString(node->Bus->name,BusPath);
	char *Name = OffsetToString(root->Bus->name,BusPath);
	
	if(strcasecmp(Name, NameComp) < 0)  // root before node, right side
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
	
	free(NameComp);
	free(Name);
			
	return root;
}


struct LocationID *Loc_insert(LocationID *node, LocationID *root)
{	// Insert location node sorting by state->city->address (case insensitive)
	char *State = OffsetToString(root->state,BusPath);
	char *StateComp = OffsetToString(node->state,BusPath);
	char *City = OffsetToString(root->city,BusPath);
	char *CityComp = OffsetToString(node->city,BusPath);
	char *Address = OffsetToString(root->address,BusPath);
	char *AddressComp = OffsetToString(node->address,BusPath);
	
	if(strcasecmp(State, StateComp) < 0) 
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
	else if(strcasecmp(State, StateComp) > 0) //root after node, left side
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
		if(strcasecmp(City, CityComp) < 0) 
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
		else if(strcasecmp(City, CityComp) > 0) //root after node, left side
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
			if(strcasecmp(Address, AddressComp) < 0) 
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
	
	free (State);
	free (StateComp);
	free (City);
	free (CityComp);
	free (Address);
	free(AddressComp);
	return root;
	
}


char *OffsetToString (int Offset, const char *FilePath)
{// Converts ofsets into actual string, must free outputed string 
	FILE *fp;
	char c, LineBuffer[170];
	int index = 0;
	
	// Opens file
	if ((fp = fopen(FilePath,"r")) == NULL)
	{
		printf("Unable to open file\n");
		return NULL;
	}
	
	// Sets offset to desired position
	fseek(fp,Offset,SEEK_SET);
	
	// Gets string at desired position
	while (((c = fgetc(fp)) != '\n') && !feof(fp) && (c != '\t')) // Gets one line of the file
	{
		LineBuffer[index++] = c;
	}
	LineBuffer[index] = '\0'; // Terminates string
	
	fclose(fp);
	
	return strdup(LineBuffer);
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


void destroy_business_bst(struct YelpDataBST* bst)
{ // Frees all memory from YelpDataBST
	
 	// Goes to bottom left, then bottom right, and frees all nodes
	if ((bst != NULL) && (bst->left != NULL))
	{
		destroy_business_bst(bst->left);
	}
	if ((bst != NULL) && (bst->right != NULL))
	{
		destroy_business_bst(bst->right);
	}
	if (bst != NULL)
	{
		DestroyBusinessID(bst->Bus);
		free(bst);
	}
}


void DestroyBusinessID (BusinessID *node)
{//Removes Location before freeing itself
	DestroyLocationID(node->Loc);
	free(node);
}


void DestroyLocationID(LocationID *node)
{ // Removes review before removing itself
	// Goes to bottom left, then bottom right, and frees all nodes
	if ((node != NULL) && (node->LocLeft != NULL))
	{
		DestroyLocationID(node->LocLeft);
	}
	if ((node != NULL) && (node->LocRight != NULL))
	{
		DestroyLocationID(node->LocRight);
	}
	if (node != NULL)
	{
		DestroyReviewID(node->Rev);
		free(node);
	}
	
}


void DestroyReviewID(ReviewID *node)
{ 	// Goes to bottom left, then bottom right, and frees all nodes
	if ((node != NULL) && (node->RevLeft != NULL))
	{
		DestroyReviewID(node->RevLeft);
	}
	if ((node != NULL) && (node->RevRight != NULL))
	{
		DestroyReviewID(node->RevRight);
	}
	if (node != NULL)
	{
		free(node);
	}
	
}


//void destroy_business_result(struct Business* b);
///* Deallocate all heap memory tied to an object returned
 //* by get_business_reviews(..). */


void print_Bus(struct YelpDataBST * node)
{// Prints business name
	char *Name = OffsetToString(node->Bus->name,BusPath);
	printf("----- Business Name: %s (%i locations) -----\n\n",Name,node->Bus->num_locations);
	free(Name);
}


void print_Loc(struct LocationID * node)
{// Prints location information
	char *BusID = OffsetToString(node->BusID,BusPath);
	char *State = OffsetToString(node->state,BusPath);
	char *City = OffsetToString(node->city,BusPath);
	char *Address = OffsetToString(node->address,BusPath);
	char *Zip = OffsetToString(node->zip_code,BusPath);
	
	
	printf("ID: %s, Address: %s, City: %s, State: %s, Zip: %s ",BusID, Address, City, State, Zip);
	printf("Number of reviews: %i\n\n",node->num_reviews);
	//printf("Stars: %i, Text: %s\n\n",node->Bus->locations->reviews->stars,node->Bus->locations->reviews->text);
	
	free(BusID);
	free(State);
	free(City);
	free(Address);
	free(Zip);
}


void print_LocTree(struct LocationID *node, int i)
{// Prints every location of business
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
{// Prints every business and location
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
