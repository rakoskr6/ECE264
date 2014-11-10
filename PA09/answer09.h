#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef PA09_H
#define PA09_H

typedef struct bnode {
  char * name;
  char * stars;
  char * address;

  struct bnode * left;
  struct bnode * right;
} BusinessNode;
/* A BusinessNode contains the name, address, and average rating of a Business.
 * It also contains pointers to the left and right children of the node.
 */
 
 
BusinessNode *create_node(char * stars, char * name, char * address);
/*
 * Construct one BusinessNode. You need to allocate memory for this node first.
 *
 * The caller needs to make sure to use strdup(...) for the arguments, do not
 * use strdup(...) inside of this function.
 *
 * stars: the stars of this business
 * name: name of this business
 * address: address of this business
 */


BusinessNode *tree_insert(BusinessNode * node, BusinessNode * root);
/* Insert a node into a BST. Primarily used in load_tree_from_file(). Return a
 * pointer to the root of the BST.
 */


BusinessNode *load_tree_from_file(char * filename);
/* Parse a .tsv file line by line, create a BusinessNode for each entry, and
 * enter that node into a new BST. Return a pointer to the root of the BST.
 *
 * The explode(...) function from PA03 may be useful for breaking up a lines 
 * into seperate fields. 
 */


BusinessNode *tree_search_name(char * name, BusinessNode * root);
/* Search a BusinessNode BST for the node with the name 'name'. Returns
 * pointer to the node with a match.
 *
 * If there is no match, return NULL.
 */


void print_node(BusinessNode * node);
/* Print out a single node: name, address, and stars
 * The format can be similar to this:
 *
 * Country Cafe
 * ============
 * Stars:
 *    3.5
 * Address:
 *    1030 Emerald Ter, Sun Prairie, WI 53590
 *
 * This function is not graded, but it could come in very handful while
 * debugging this assignment.
 */


void print_tree(BusinessNode * tree);
/* Print the entire tree, starting from the root. Like the print_node(...)
 * function, this is not graded.
 */


void destroy_tree(BusinessNode * root);
/* Deallocate all of the memory used by a BusinessNode BST, without memory
 * leaks.
 */


#endif
