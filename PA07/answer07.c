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
    int err = FALSE; 
    FILE * fp = fopen(filename, "wb");
    size_t written = 0;

    if(fp == NULL) // Ensures file was properly opened
    {
		fprintf(stderr, "Failed to open '%s' for writing\n", filename);
		return FALSE;
    }

    // Prepare the header
    Image ImageHeader;
    header.type = ECE264_IMAGE_MAGIC_NUMBER;
    header.width = image->width;
    header.height = image->height;    
    header.comment_len = strlen(image->comment);


    if(!err) // Write the header
    {  
		written = fwrite(&header, sizeof(ImageHeader), 1, fp);
		if(written != 1) 
		{
			fprintf(stderr, "Error: only wrote %zd of %zd of file header to '%s'\n", written, sizeof(ImageHeader), filename);
			err = TRUE;	
		}
    }
// Stopped working here! /////////////////////

    if(!err) { // Before writing, we'll need a write buffer
	buffer = malloc(bytes_per_row);
	if(buffer == NULL) {
	    fprintf(stderr, "Error: failed to allocate write buffer\n");
	    err = TRUE;
	} else {
	    // not strictly necessary, we output file will be tidier.
	    memset(buffer, 0, bytes_per_row); 
	}
    }

    if(!err) { // Write pixels	
	uint8_t * read_ptr = image->data;	
	int row, col; // row and column
	for(row = 0; row < header.height && !err; ++row) {
	    uint8_t * write_ptr = buffer;
	    for(col = 0; col < header.width; ++col) {
		*write_ptr++ = *read_ptr; // blue
		*write_ptr++ = *read_ptr; // green
		*write_ptr++ = *read_ptr; // red
		read_ptr++; // advance to the next pixel
	    }
	    // Write line to file
	    written = fwrite(buffer, sizeof(uint8_t), bytes_per_row, fp);
	    if(written != bytes_per_row) {
		fprintf(stderr, "Failed to write pixel data to file\n");
		err = TRUE;
	    }
	}
    }
    
    // Cleanup
    free(buffer);
    if(fp)
	fclose(fp);

    return !err;	
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
