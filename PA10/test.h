typedef struct ReviewInfo{
	uint32_t text;
	uint32_t stars;
}ReviewInfo;


typedef struct LocInfo{
	uint32_t BusID;
	uint32_t address;
	uint32_t city;
	uint32_t state;
	uint32_t zip_code;
	uint32_t num_reviews;
	ReviewInfo *Reviews[500];

}LocInfo;

struct YelpDataBST{ 
	char *name;
	uint32_t num_locations;
	LocInfo *Locations[500];
	struct YelpDataBST *left;
	struct YelpDataBST *right;
};

struct YelpDataBST *create_business_bst(const char* businesses_path, const char* reviews_path); 
struct YelpDataBST *Insert(struct YelpDataBST *root, uint32_t BusIDL, char *name, uint32_t addressL, uint32_t cityL, uint32_t stateL, uint32_t zip_codeL, int *LocNumber);
struct YelpDataBST *BusExist(char *name, struct YelpDataBST *root); 
struct YelpDataBST *CreateYelpNode(char *name);
LocInfo *CreateLocInfo(uint32_t BusID, uint32_t address, uint32_t city, uint32_t state, uint32_t zip_code);
ReviewInfo *CreateReviewInfo(uint32_t text, uint32_t stars);
struct YelpDataBST *Bus_insert(struct YelpDataBST *node, struct YelpDataBST *root);

void destroy_business_bst(struct YelpDataBST* bst);
void DestroyReviews(LocInfo *node);
void print_tree(struct YelpDataBST *tree);
struct YelpDataBST *FindBusiness(char *name, struct YelpDataBST *root);


