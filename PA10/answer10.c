/******************* Declarations *******************/
#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/******************* Functions *******************/
// note: change all BusPath, and RevPath global declarations to use function inputs
struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path) 
{// Loads all businesss and reviews into YelpDataBST structure
	FILE *fp, *fp2;
	char LineBuffer[300], c, *BusID = "0", *Name, *Address,*City, *State;
	struct YelpDataBST *Root = NULL;
	int index = 0, LineStart = 0, BusIDL, NameL, AddressL, CityL, StateL, ZipL;

	char *BusIDRev = "0", *Stars, *Funny, *Useful, *Cool, LineBuffer2[6000];
	int BusIDRevL, StarsL, FunnyL, UsefulL, CoolL, TextL, index2 = 0, LineStart2 = 0;

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
			
			// Uncoments to print 
			char *BusP, *AddP, *CityP, *StateP, *ZipP;
			printf("%s, %s, %s\n",BusP = OffsetToString(BusIDL,businesses_path), Name, AddP = OffsetToString(AddressL,businesses_path));
			printf("%s, %s, %s\n\n",CityP = OffsetToString(CityL,businesses_path), StateP = OffsetToString(StateL,businesses_path), ZipP = OffsetToString(ZipL,businesses_path));
			free(BusP);
			free(AddP);
			free(CityP);
			free(StateP);
			free(ZipP);
			
			int TempCompare = strcmp(Name,"Lovejoys Kansas City Bar-B-Q");
			if (TempCompare == 0)
			{
				printf("Here\n");
			}
	
			// Adds offset data to YelpDataBST
			Root = Insert(Root,strdup(Name),BusIDL, AddressL, CityL, StateL, ZipL);
			
			
			
			// Get review data from seperate file	CHANGE 5 TO 0 TO GO THROUGH LOOP
			while (strcmp(BusIDRev,BusID) == 5) // add reviews when the business ID's are the same
			{
				LineStart2 = ftell(fp2); // gets location at start of reading line
				while (((c = fgetc(fp2)) != '\n') && !feof(fp2)) // Gets one line of the file
				{
					LineBuffer2[index2++] = c;
				}
				LineBuffer2[index2] = '\0'; // Terminates string
				index2 = 0; // Resets index
				if (strlen(LineBuffer2) > 0) // ensures line read isn't blank
				{
					// Gets individual strings
					BusIDRev = strtok(LineBuffer2,"\t");
					Stars = strtok(NULL,"\t");
					Funny = strtok(NULL,"\t");
					Useful = strtok(NULL,"\t");
					Cool = strtok(NULL,"\t");
					//Text = strtok(NULL,"\t");
	
					// Converts strings to offsets (line offset + string lengths + null character)
					BusIDRevL 	= LineStart2;
					StarsL 		= BusIDRevL + strlen(BusIDRev) + 1;
					FunnyL	 	= StarsL + strlen(Stars) + 1;
					UsefulL		= FunnyL + strlen(Funny) + 1;
					CoolL 		= UsefulL + strlen(Useful) + 1;
					TextL		= CoolL + strlen(Cool) + 1;
					
					if (strcmp(BusIDRev,BusID) != 0)// Check if BusIDs don't match, if so move pointer to beginning of the line
					{
						fseek(fp2,LineStart2,SEEK_SET);
					}
					else // else find business location and add reviews
					{
						BusinessID *TempBusID = FindBusiness(Name,Root);
						if (TempBusID == NULL)
						{
							printf("Error when BusID is %s, BusIDL is %i, BusIDRev is %s, name is %s\n",BusID,BusIDL,BusIDRev,Name);
							return NULL;
						}
						LocationID *TempLocID1 = TempBusID->Loc;
						LocationID *TempLocID2 = FindBusLocState(State,TempLocID1);
						LocationID *TempLocID3 = FindBusLocCity(City,TempLocID2);
						LocationID *CurrentBus = FindBusLocAddress(Address,TempLocID3); // finds given location
						CurrentBus->num_reviews++;
						CurrentBus->Rev = AddReview(CreateReviewID(StarsL,TextL),CurrentBus->Rev);
					}
				}
			} 
		}
	}
	fclose(fp); // Close Business file
	fclose(fp2); // Close Review file
 	return Root;
}


struct YelpDataBST *Insert(struct YelpDataBST *root, char *name, uint32_t BusIDL, uint32_t addressL, uint32_t cityL, uint32_t stateL, uint32_t zip_codeL)
{	// Adds or creates new location from given data
	struct YelpDataBST *BusExists = BusExist(name,root);

	if (BusExists == NULL) // Create first business location
	{
		root = Bus_insert(CreateYelpNode(name,BusIDL,addressL,cityL,stateL,zip_codeL),root);
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
	char *NameComp = root->Bus->name;
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


struct YelpDataBST * CreateYelpNode(char *name, uint32_t BusIDL, uint32_t addressL, uint32_t cityL, uint32_t stateL, uint32_t zip_codeL)
{	// Creates new Yelp Node (and Business and Location node), doesn't add reviews
	
	// Allocates size for nodes and adds data
	struct YelpDataBST *NewNode = malloc(sizeof(struct YelpDataBST));
	NewNode->Bus = malloc(sizeof(BusinessID));
	
	// Makes next nodes null
	NewNode->left = NULL;
	NewNode->right = NULL;
	
	// Business Info
	NewNode->Bus->name = name;
	NewNode->Bus->num_locations = 1;
	
	// Location Info 
	NewNode->Bus->Loc = CreateLocation(BusIDL,addressL, cityL, stateL, zip_codeL);
	
	return NewNode;
}


struct LocationID *CreateLocation(uint32_t BusIDL, uint32_t addressL, uint32_t cityL, uint32_t stateL, uint32_t zip_codeL)
{	// Creates new Location Node, doesn't add reviews
		
	// Allocates size for nodes and adds data
	LocationID *NewNode = malloc(sizeof(struct LocationID));

	// Makes next nodes null
	NewNode->LocLeft = NULL;
	NewNode->LocRight = NULL;
	NewNode->Rev = NULL;
	
	// Location Info
	//if (BusIDL == 0)
	//{
		//printf("Error! BusIDL is 0\n\n\n");
	//}
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
	
	char *NameComp = node->Bus->name;
	char *Name = root->Bus->name;

		
		
	if(strcasecmp(Name, NameComp) < 0)  // root before node, right side
	{
		if (root->right == NULL)
		{
			//printf("%s r\n",NameComp); // temp debug
			root->right = node;
		}
		else
		{
			//printf("%s\n",Name); // temp debug
			Bus_insert(node,root->right);
		}
	}
	else if(strcasecmp(Name, NameComp) > 0) //root after node, left side
	{
		if (root->left == NULL)
		{
			//printf("%s l\n",NameComp); // temp debug
			root->left = node;
		}
		else
		{
			//printf("%s\n",Name); // temp debug
			Bus_insert(node,root->left);
		}
	}
	
			// break here and c 116
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


BusinessID *FindBusiness(char *name, struct YelpDataBST *root)
{// finds specified business node
	if (root == NULL)
		return NULL;
	
	int cmp = strcmp(root->Bus->name,name);

	if (cmp == 0) // found, return the root
	{
		return root->Bus;
	}
	else if (cmp < 0) // root before node, go right
	{
		return FindBusiness(name, root->right);
	}

	return FindBusiness(name, root->left);
}


LocationID *FindBusLocState(char *state, LocationID *root)
{// finds specified location node by state
	if (root == NULL)
		return NULL;
		
	char *StateComp = OffsetToString(root->state,BusPath);
	int cmp = strcmp(StateComp,state);
	free(StateComp);
	if (cmp == 0) // found, return the root
	{
		return root;
	}
	else if (cmp < 0) // root before node, go right
	{
		return FindBusLocState(state, root->LocRight);
	}

	return FindBusLocState(state, root->LocLeft);
}


LocationID *FindBusLocCity(char *city, LocationID *root)
{// finds specified location node by city
	if (root == NULL)
		return NULL;
		
	char *CityComp = OffsetToString(root->city,BusPath);
	int cmp = strcmp(CityComp,city);
	free(CityComp);
	if (cmp == 0) // found, return the root
	{
		return root;
	}
	else if (cmp < 0) // root before node, go right
	{
		return FindBusLocState(city, root->LocRight);
	}

	return FindBusLocState(city, root->LocLeft);
}


LocationID *FindBusLocAddress(char* address, LocationID *root)
{// finds specified location node by address
	if (root == NULL)
		return NULL;
	char *AddComp = OffsetToString(root->address,BusPath);
	int cmp = strcmp(AddComp,address);
	free(AddComp);
	if (cmp == 0) // found, return the root
	{
		return root;
	}
	else if (cmp < 0) // root before node, go right
	{
		return FindBusLocState(address, root->LocRight);
	}

	return FindBusLocState(address, root->LocLeft);
}


ReviewID *CreateReviewID(uint32_t starsL, uint32_t textL)
{// Creates new Review Node
		
	// Allocates size for nodes and adds data
	ReviewID *NewNode = malloc(sizeof(struct ReviewID));

	// Makes next nodes null
	NewNode->RevLeft = NULL;
	NewNode->RevRight = NULL;
	
	// Review Info
	NewNode->stars = starsL;
	NewNode->text = textL;

	return NewNode;
}


ReviewID *AddReview(ReviewID *node, ReviewID *root)
{
	if (root == NULL)
	{
		return node;
	}
	
	char *StarsComp = OffsetToString(node->stars,RevPath);
	char *Stars = OffsetToString(root->stars,RevPath);
	char *TextComp = OffsetToString(node->text,RevPath);
	char *Text = OffsetToString(root->text,RevPath);
	
	if(strcasecmp(Stars, StarsComp) < 0)  // root before node, right side
	{
		if (root->RevRight == NULL)
		{
			root->RevRight = node;
		}
		else
		{
			AddReview(node,root->RevRight);
		}
	}
	else if(strcmp(Stars, StarsComp) > 0) //root after node, left side
	{
		if (root->RevLeft == NULL)
		{
			root->RevLeft = node;
		}
		else
		{
			AddReview(node,root->RevLeft);
		}
	}
	else if (strcmp(Text, TextComp) < 0) // root before node, right side
	{
		if (root->RevRight == NULL)
		{
			root->RevRight = node;
		}
		else
		{
			AddReview(node,root->RevRight);
		}
	}
	else
	{
		if (root->RevLeft == NULL)
		{
			root->RevLeft = node;
		}
		else
		{
			AddReview(node,root->RevLeft);
		}
	}
	
	free(StarsComp);
	free(Stars);
	free(TextComp);
	free(Text);
			
	return root;
}


char *OffsetToString (int Offset, const char *FilePath)
{// Converts ofsets into actual string, must free outputed string 
	FILE *fp;
	char c, LineBuffer[6000];
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
	}
	free(bst);
}


void DestroyBusinessID (BusinessID *node)
{//Removes Location before freeing itself
	DestroyLocationID(node->Loc);
	free(node->name);
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


void print_Bus(struct YelpDataBST * node)
{// Prints business name
	printf("----- Business Name: %s (%i locations) -----\n",node->Bus->name,node->Bus->num_locations);
}


void print_LocTree(struct LocationID *node, int i)
{// Prints every location of business
	if (node != NULL)
		{
			print_Loc(node);
			print_RevTree(node->Rev, i);
		
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


void print_Loc(struct LocationID * node)
{// Prints location information
	char *BusID = OffsetToString(node->BusID,BusPath);
	char *State = OffsetToString(node->state,BusPath);
	char *City = OffsetToString(node->city,BusPath);
	char *Address = OffsetToString(node->address,BusPath);
	char *Zip = OffsetToString(node->zip_code,BusPath);
	
	
	printf("ID: %s, Address: %s, City: %s, State: %s, Zip: %s ",BusID, Address, City, State, Zip);
	printf("--Number of reviews: %i--\n",node->num_reviews);
	//printf("Stars: %i, Text: %s\n\n",node->Bus->locations->reviews->stars,node->Bus->locations->reviews->text);
	
	free(BusID);
	free(State);
	free(City);
	free(Address);
	free(Zip);
}


void print_RevTree(struct ReviewID *node, int i)
{// Prints every location of business
	if (node != NULL)
		{
			print_Rev(node);
		
		}
		if ((node != NULL) && (node->RevLeft != NULL))
		{
			printf("Left %i\n",i++);
			print_RevTree(node->RevLeft, i);
		}
		if ((node != NULL) && (node->RevRight != NULL))
		{
			printf("Right %i\n",i++);
			print_RevTree(node->RevRight, i);
		}
}


void print_Rev(struct ReviewID * node)
{// Prints location information
	char *Stars = OffsetToString(node->stars,RevPath);
	char *Text = OffsetToString(node->text,RevPath);
	
	printf("Stars: %s, Text: %s\n\n",Stars,Text);
	free(Stars);
	free(Text);
}
