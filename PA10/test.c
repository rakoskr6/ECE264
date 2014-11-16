#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(void)
{
	printf("\e[1;1H\e[2J"); // clears screen
	struct YelpDataBST *root = NULL;

	
	root = Insert(root, strdup("McDonalds"), 258, strdup("125 Wilson"), strdup("Batavia"), strdup("IL"), strdup("60510"));
	root = Insert(root, strdup("McDonalds"), 392, strdup("587 Randall Rd"), strdup("Geneva"), strdup("IL"), strdup("60134"));
	root = Insert(root, strdup("McDonalds"), 587, strdup("21 Main St"), strdup("Aurora"), strdup("IL"), strdup("60584"));
	root = Insert(root, strdup("McDonalds"), 123, strdup("21 Main St"), strdup("Houston"), strdup("TX"), strdup("54128"));
	root = Insert(root, strdup("Chipotle"), 25, strdup("587 Randall Rd"), strdup("Geneva"), strdup("IL"), strdup("60134"));
	root = Insert(root, strdup("Chipotle"), 1328, strdup("State St"), strdup("West Lafayette"), strdup("IN"), strdup("47906"));
	

	
	print_tree(root, 1);
	
	return EXIT_SUCCESS;
}
