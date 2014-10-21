/* Lecture Notes for 10/21/2014
 * Chapter 5- read info on make file
 * for "aliasing" of commands to save time
 * Meta-data -> about the data
 * meta-x -> description abut x
 * image meta data can contain:
 * width, height, color, focal length, etc.
 * 
 * Image file has two parts:
 * meta-data (sometimes called header)
 * and data
 * 
 * For assignment, 
 * 1. Read the heade which is a fixed size (to read binary file, use fread)
 * 2. Some standards (not this assignment) will have additonal metadata
 * 3. Read data
 * 
 * For this assignment we will use BMP image format (bitmap)
 * This is an uncompressed format
 * 
 * A common color scheme is RGB (Red, Green, Blue)
 * True Color: 8 bits per color -1 byte, 24 bits per pixel
 * Ex:
 * 255,0,0 = pure red
 * 0,255,0 = pure green
 * 
 * Another color scheme is RGBA (Red, Green, Blue, Alpha - transparency)
 * 
 * Compressed images have a compression ratio
 * 	Ratio = Size of uncompressed / Compressed
 * 
 * For JPEG ratio ~= #pixels/(3 to 4)
 * 
 * A JPEG imageis a lossy comprssion - data is lost
 * Lossless compression allows full data recovery
 * Lossy compression allows an improved compression ratio
 * 
 * For program assignment: */
 

 char *pixels = malloc(width*height, sizeof(char));
 rtv = fread (pixels, sizeof(char),width*height,fptr);
 
 if (rtv != (width*height))
	// error
	
	
/*	
 * How histograms work for images:
 
	#pixels
	|
	|
	|
	|
	|
	|		x (this number of pixels have a certain intensity)
	|
	|_______________________________ brightness/intensity
	 
	
*/


// Example as to why you need to see how much was read
// Read or write 1MB to network
while (more to read)
{
	rtv = read from network
	more to read = rtv
}


/*************** Dynamic Structures **************************/

// dynamic structures vs fixed structures
	//fixed size used for known size
	int arr[80];
	
	// dynamic allocation used for unknon size. Released when no longer needed
	int size;
	// find size at runtime
	scanf("%d",&size);
	int *arr;
	arr = malloc(sizeof(int)*size);
	
/* In this class we will learn two types of dynamic structures
 * Linked list
 * Binary tree
 */
 
 typedef struct listnode
 {
	struct listnode *next;
	attributes (data); // data you want to store
	int value;
} Node; //New type
 

	
