#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"
#define FALSE 0
#define TRUE 1
int CheckValidee264(ImageHeader *Header);

Image * Image_load(const char * filename)
{
	// Note: Some code taken from image-bmp.c
	    
	FILE * fp = fopen(filename, "rb");
    size_t read;
    int err = FALSE;
	ImageHeader header;
	Image *LoadedImage;

	if(!fp) // Ensures file was successfully opened
	{
	    fprintf(stderr, "Failed to open file '%s'\n", filename);
	    err = TRUE;
	}

    if(!err) // Read the header
    { 
		read = fread(&header, sizeof(ImageHeader), 1, fp);
		if(read != 1) 
		{
			fprintf(stderr, "Failed to read header from '%s'\n", filename);
			err = TRUE;
		}
    }


    if(!err) // Ensure valid ee264 file
    { 
		if(header.magic_number != ECE264_IMAGE_MAGIC_NUMBER)
		{
			fprintf(stderr, "Invalid header in '%s'\n", filename);
			err = TRUE;
		}
    }

    if(!err) // Allocate Image struct
    { 
		LoadedImage = malloc(sizeof(Image));
		
		if(LoadedImage == NULL)
		{
			fprintf(stderr, "Failed to allocate LoadedImage structure\n");
			err = TRUE;
		} 
    }

    if(!err)// Initialize the Image struct
	{ 
		LoadedImage->width = header.width;
		LoadedImage->height = header.height;
		LoadedImage->comment = malloc(header.comment_len * sizeof(char)); // allocates size for comment
		if (LoadedImage->comment == NULL)
		{
			fprintf(stderr, "Failed to allocate space for comment");
			err = TRUE;
		}
		else // if comment was succesfully malloced then continue
		{
			LoadedImage->data = malloc(sizeof(uint8_t) * header.width * header.height);
			if (LoadedImage->data == NULL)
			{
				fprintf(stderr, "Failed to allocate space for data");
				err = TRUE;
			}
			else // if data was succesfully malloced then continue
			{
				read = fread(LoadedImage->comment, header.comment_len, 1, fp);
				if(read != 1) 
				{
					fprintf(stderr, "Failed to read comment from '%s'\n", filename);
					err = TRUE;
				}
				else // if comment was properly read
				{
					read = fread(LoadedImage->data, header.width * header.height, 1, fp);
					if(read != 1) 
					{
						fprintf(stderr, "Failed to read data from '%s'\n", filename);
						err = TRUE;
					}
				}
			}
		}
	}
		

    if(fp) 
    {
		fclose(fp);
    }

    return LoadedImage;
}



int Image_save(const char * filename, Image * image)
{

return EXIT_SUCCESS;	
}



void Image_free(Image * image)
{
	if (image != NULL)
	{
		free(image->comment);
		free(image->data);
		free(image);
	}
}



void linearNormalization(int width, int height, uint8_t * intensity)
{
	
}
