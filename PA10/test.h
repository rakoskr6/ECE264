typedef struct ReviewID {
	int text;
	int stars;
	struct ReviewID *RevLeft;
	struct ReviewID *RevRight;
}ReviewID;

typedef struct LocationID {
	int BusID;
	int address;
	int city;
	int state;
	int zip_code;
	uint32_t num_reviews;
	ReviewID *Rev;
	struct LocationID *LocLeft;
	struct LocationID *LocRight;
	
}LocationID;

typedef struct BusinessID {
	int name;
	uint32_t num_locations;
	LocationID *Loc; 
}BusinessID;

struct YelpDataBST{ 
	struct BusinessID *Bus;
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};


struct YelpDataBST * CreateYelpNode(int nameL, int BusIDL, int addressL, int cityL, int stateL, int zip_codeL);
void print_node(struct YelpDataBST * node);
void print_tree(struct YelpDataBST *tree, int i);
struct LocationID *CreateLocation(int BusIDL, int addressL, int cityL, int stateL, int zip_codeL);


struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root);
void print_LocTree(struct LocationID *node, int i);

struct YelpDataBST *Insert(struct YelpDataBST *root, int nameL, int BusIDL, int addressL, int cityL, int stateL, int zip_codeL);
struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root);
struct LocationID *Loc_insert(LocationID *node, LocationID *root);

char *OffsetToString (int Offset, const char *FilePath);

void DestroyBusinessID (BusinessID *node);
void DestroyLocationID(LocationID *node);
void DestroyReviewID(ReviewID *node);

BusinessID *FindBusiness(char *name, struct YelpDataBST *root);
LocationID *FindBusLocState(char *state, LocationID *root);
LocationID *FindBusLocCity(char *city, LocationID *root);
LocationID *FindBusLocAddress(char* address, LocationID *root);
ReviewID *CreateReviewID(int starsL, int textL);
ReviewID *AddReview(ReviewID *node, ReviewID *root);

void print_RevTree(struct ReviewID *node, int i);
void print_Rev(struct ReviewID * node);
void print_Bus(struct YelpDataBST * node);
void print_Loc(struct LocationID * node);

#define BusPath "/home/kyle/Documents/ECE264/solutions/ECE264/PA10/businesses.tsv"
#define RevPath "/home/kyle/Documents/ECE264/solutions/ECE264/PA10/reviewsShort.tsv"
