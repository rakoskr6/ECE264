#include "answer10.h"
#include <stdio.h>
#include <stdlib.h>


struct YelpDataBST{ // Root of tree (may want to consider changing)
	struct Business *left;
	struct Business *right;
};


struct YelpDataBST* create_business_bst(const char* businesses_path,
                                        const char* reviews_path);
/* This function reads the two files and creates an index that can be used
 * to search the data and quickly retrieve the reviews.  You must *not* store
 * all of the review text in memory.  Your structure should store the file
 * offsets where the review text can be found.
 *
 * businesses_path - path to the businesses.tsv file provided for this assignment.
 * reviews_path - path to the businesses.tsv file provided for this assignment.
 *     When running on ecegrid, you can pass the following:
 *        /home/shay/a/ece264p0/share/yelp_data/businesses.tsv
 *        /home/shay/a/ece264p0/share/yelp_data/reviews.tsv
 *
 * DO NOT COPY THOSE FILES TO YOUR HOME DIRECTORY.  PLEASE ACCESS THEM USING
 * THOSE PATHS.  THESE ARE LARGE FILES AND WE DO NOT WANT TO FILL THE DISK
 * WITH MULTIPLE COPIES OF THEM.
 */

struct Business* get_business_reviews(struct YelpDataBST* bst,
                                      char* name, char* state, char* zip_code);
/* get_reviews(..) should return a pointer to a Business struct object
 * on the heap.  That object will include links to the individual locations.
 * For example, if "McDonald's" is the business, then there would be thousands
 * of locations.  Each Location struct object in turn contains links to
 * reviews of that location.
 *
 * bst - the object returned by create_business_bst(..)
 * name - name of the business to search for (e.g., "McDonald's"); search is
 *     case insensitive.
 * state - two-letter (uppercase) state code to filter locations by, or NULL
 *     to include all states.
 * zip_code - five digit ZIP code to filter locations by, or NULL to include
 *     all ZIP codes.
 *
 * Locations must be sorted by state >> city >> address.
 *
 * Reviews must be sorted by star rating (descending) >> text of review.
 *
 * Matching of names, cities, and states must be case-insensitive.  You
 * may use functions from strings.h for that, if you wish.
 */


void destroy_business_bst(struct YelpDataBST* bst);
/* Deallocate all memory allocated by the object returned
 * by create_business_bst(..) and close the files. */

void destroy_business_result(struct Business* b);
/* Deallocate all heap memory tied to an object returned
 * by get_business_reviews(..). */
