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


struct YelpDataBST * CreateYelpNode(char *name, uint32_t BusID, char *address, char *city, char *state, char *zip_code);
void print_node(struct YelpDataBST * node);
void print_tree(struct YelpDataBST *tree, int i);
struct LocationID *CreateLocation(uint32_t BusID, char *address, char *city, char *state, char *zip_code);


struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root);
void print_LocTree(struct LocationID *node, int i);

struct YelpDataBST *Insert(struct YelpDataBST *root, char *name, uint32_t BusID, char *address, char *city, char *state, char *zip_code);
struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root);
struct LocationID *Loc_insert(LocationID *node, LocationID *root);

char *OffsetToString (int Offset, const char *FilePath);
