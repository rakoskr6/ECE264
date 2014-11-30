/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/******************* Functions *******************/
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
		return BusExist(name,root->right);
	}
	
	free(NameComp);
	return BusExist(name,root->left);
}

struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root) // inserts business node into YelpDataBST if business is new
{
	// Insert business node sorting by business name (case insensitive)<-double check
	
	
	if (root == NULL)
	{
		return node;
	}
	
	char *NameComp = OffsetToString(node->Bus->name,BusPath);
	char *Name = OffsetToString(root->Bus->name,BusPath);
	
	if(strcasecmp(Name, NameComp) < 0) 
	{
		if (root->right == NULL)
		{
			free(NameComp);
			free(Name);
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
			free(NameComp);
			free(Name);
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
			free (State);
			free (StateComp);
			free (City);
			free (CityComp);
			free (Address);
			free(AddressComp);
			
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
			free (State);
			free (StateComp);
			free (City);
			free (CityComp);
			free (Address);
			free(AddressComp);
			
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
				free (State);
				free (StateComp);
				free (City);
				free (CityComp);
				free (Address);
				free(AddressComp);
			
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
				free (State);
				free (StateComp);
				free (City);
				free (CityComp);
				free (Address);
				free(AddressComp);
			
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
					free (State);
					free (StateComp);
					free (City);
					free (CityComp);
					free (Address);
					free(AddressComp);
					
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
					free (State);
					free (StateComp);
					free (City);
					free (CityComp);
					free (Address);
					free(AddressComp);
					
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

struct YelpDataBST *Insert(struct YelpDataBST *root, int nameL, int BusIDL, int addressL, int cityL, int stateL, int zip_codeL)
{	
	struct YelpDataBST *LocExists = BusExist(OffsetToString(nameL,BusPath),root);
	if (LocExists == NULL)
	{
		root = Bus_insert(CreateYelpNode(nameL,BusIDL,addressL,cityL,stateL,zip_codeL),root);
	}
	else
	{
		LocExists->Bus->num_locations++;
		LocExists->Bus->Loc = Loc_insert(CreateLocation(BusIDL, addressL,cityL,stateL,zip_codeL),LocExists->Bus->Loc);
	}
	return root;
	
}

struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path) // loads information
{
	FILE *fp;
	char LineBuffer[170];
	char *BusID, *Name, *Address,*City, *State;
	struct YelpDataBST *Root = NULL;
	char c;
	int index = 0;
	
	int LineStart = 0;
	int BusIDL, NameL, AddressL, CityL, StateL, ZipL;
	
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
		LineStart = ftell(fp); // gets location at start of reading line
		while (((c = fgetc(fp)) != '\n') && !feof(fp)) // Gets one line of the file
		{
			LineBuffer[index++] = c;
		}
		LineBuffer[index] = '\0'; // Terminates string
		
		if (strlen(LineBuffer) > 0)
		{
			// Gets individual strings
			BusID = strtok(LineBuffer,"\t");
			Name = strtok(NULL,"\t");
			Address = strtok(NULL,"\t");
			City = strtok(NULL,"\t");
			State = strtok(NULL,"\t");
			//Zip = strtok(NULL,"\t");
			
			// Obtains file location by taking begining of line offset + string lengths + null character
			BusIDL	 	= LineStart;
			NameL 		= BusIDL + strlen(BusID) + 1;
			AddressL 	= NameL + strlen(Name) + 1;
			CityL 		= AddressL + strlen(Address) + 1;
			StateL 		= CityL + strlen(City) + 1;
			ZipL		= StateL + strlen(State) + 1;
			
			//printf("%s, %s, %s\n",OffsetToString(BusIDL,businesses_path), OffsetToString(NameL,businesses_path), OffsetToString(AddressL,businesses_path));
			//printf("%s, %s, %s\n\n",OffsetToString(CityL,businesses_path), OffsetToString(StateL,businesses_path), OffsetToString(ZipL,businesses_path));
			
			Root = Insert(Root,NameL,BusIDL, AddressL, CityL, StateL, ZipL);		
			
			index = 0; // Resets index
		}
	}
	fclose(fp);
	return Root;
}

char *OffsetToString (int Offset, const char *FilePath)
{
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
{
/* Deallocate all memory allocated by the object returned
 * by create_business_bst(..) and close the files. */
 
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
{
	DestroyLocationID(node->Loc);
	free(node);
}

void DestroyLocationID(LocationID *node)
{ 	// Goes to bottom left, then bottom right, and frees all nodes
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
{
	char *Name = OffsetToString(node->Bus->name,BusPath);
	printf("----- Business Name: %s (%i locations) -----\n\n",Name,node->Bus->num_locations);
	free(Name);
}

void print_Loc(struct LocationID * node)
{
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
