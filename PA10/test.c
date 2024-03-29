#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(void)
{
	printf("\e[1;1H\e[2J"); // clears screen
	struct YelpDataBST *root = NULL;

	root = create_business_bst("/home/kyle/Documents/ECE264/solutions/ECE264/PA10/businesses.tsv", "/home/kyle/Documents/ECE264/solutions/ECE264/PA10/reviews.tsv");
	
	print_tree(root);
	destroy_business_bst(root);
	
	return EXIT_SUCCESS;
}
