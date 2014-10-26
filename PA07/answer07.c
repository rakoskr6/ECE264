#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"

//Image * Image_load(const char * filename)
//{
	
//}



int Image_save(const char * filename, Image * image)
{

return EXIT_SUCCESS;	
}



void Image_free(Image * image)
{
     free(image->comment);
     free(image->data);
     free(image);
}



void linearNormalization(int width, int height, uint8_t * intensity)
{
	
}
