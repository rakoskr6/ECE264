#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"
#define FALSE 0
#define TRUE 1

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
		
		else if (header.width == 0 || header.height == 0) // min size
		{
			fprintf(stderr, "Can't have dimension be 0 in '%s'\n", filename);
			err = TRUE;
		}
		
		else if (header.width >= 5000 || header.height >= 5000) // max size
		{
			fprintf(stderr, "Can't have dimension be 0 in '%s'\n", filename);
			err = TRUE;
		}
		
		else if (header.comment_len >= 10000) // comment max size
		{
			fprintf(stderr, "Comment too large '%s'\n", filename);
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
						Image_free(LoadedImage);
						err = TRUE;
					}
					else // Ensure data isn't still left at the end of the file
					{
						uint8_t * TestBuffer;
						TestBuffer = malloc(sizeof(uint8_t) * 50);
						read = fread(TestBuffer,sizeof(uint8_t), 1, fp);
						if (read != 0)
						{
							fprintf(stderr, "Failed to reach end of file '%s'\n", filename);
							Image_free(LoadedImage);
							err = TRUE;
						}
						free(TestBuffer);
					}
				}
			}
		}
	}
	
	// Couple more checks
	if (!err)
	{
		if ( (LoadedImage->comment[header.comment_len-1]) != '\0') 
		{
			fprintf(stderr, "Comment doesn't end with null character in '%s'\n", filename);
			Image_free(LoadedImage);
			err = TRUE;
		}
		
	}
		

    if(fp) 
    {
		fclose(fp);
    }
    
	if (!err)
	{
		return LoadedImage;
	}

	return NULL;
}



int Image_save(const char * filename, Image * image)
{
    int err = FALSE; 
    FILE * fp = fopen(filename, "wb");
    size_t written = 0;
    uint8_t * buffer;

    if(fp == NULL) // Ensures file was properly opened
    {
		fprintf(stderr, "Failed to open '%s' for writing\n", filename);
		return FALSE;
    }

    // Prepare the header
    ImageHeader header;
    header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
    header.width = image->width;
    header.height = image->height;    
    header.comment_len =  sizeof(char) * strlen(image->comment) + 1; // plus 1 for null


    if(!err) // Write the header
    {  
		written = fwrite(&header, sizeof(header), 1, fp);
		if(written != 1) 
		{
			fprintf(stderr, "Error: only wrote %zd of %zd of file header to '%s'\n", written, sizeof(ImageHeader), filename);
			err = TRUE;	
		}
    }


    if(!err) // Before writing, we'll need a write buffer
    { 
		buffer = malloc(header.width);
		if(buffer == NULL)
		{
			fprintf(stderr, "Error: failed to allocate write buffer\n");
			err = TRUE;
		}
		else
		{
			// not strictly necessary, we output file will be tidier.
			memset(buffer, 0, header.width); 
		}
    }

	if(!err) // Write comments	
    { 
		written = fwrite(image->comment, header.comment_len, 1, fp);
    }
    

    if(!err) // Write pixels	
    { 
		uint8_t * read_ptr = image->data;	
		int row, col; // row and column
		for(row = 0; row < header.height && !err; ++row) 
		{
			uint8_t * write_ptr = buffer;
			for(col = 0; col < header.width; ++col) 
			{
				*write_ptr++ = *read_ptr;
				read_ptr++; // advance to the next pixel
			}
			// Write line to file
			written = fwrite(buffer, sizeof(uint8_t), header.width, fp);
			if(written != header.width) 
			{
				fprintf(stderr, "Failed to write pixel data to file\n");
				err = TRUE;
			}
		}
    }
    
    // Cleanup
    free(buffer);
    if(fp)
	{
		fclose(fp);
	}
	
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
	int index;
	int Max = intensity[0], Min = intensity[0];
	
	// Finds max and min
	for (index = 0; index < (width * height); index++)
	{
		if (intensity[index] > Max)
			Max = intensity[index];
		if (intensity[index] < Min)
			Min = intensity[index];
	}
	
	for (index = 0; index < (width * height); index++)
	{
		intensity[index] = (intensity[index] - Min) * 255.0 / (Max - Min);
	}
}




