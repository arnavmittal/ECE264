#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include <stdint.h>

#define ECE264_IMAGE_MAGIC_NUMBER 0x21343632

typedef struct ImageHeader_st
{
    uint32_t magic_number; // Should be ECE264_IMAGE_MAGIC_NUMBER
    uint32_t width;        // [width x height], cannot be zero
    uint32_t height;
    uint32_t comment_len;  // A comment embedded in the file
} ImageHeader;

typedef struct Image_st
{
    int width;
    int height;
    char * comment;
    uint8_t * data;
} Image;

int checkHeader(ImageHeader * hdr)
{
    if ((hdr -> magic_number) != ECE264_IMAGE_MAGIC_NUMBER)
    {
        return 0;
    }
    if ((hdr -> width) == 0)
    {
        return 0;
    }
    if ((hdr -> height) == 0)
    {
        return 0;
    }
    if ((hdr -> comment_len)-1 == 0)
    {
        return 0;
    } return 1;
}

Image * cleanUp(FILE * fptr, Image * img)
{
    if (fptr != NULL)
    {
        fclose (fptr);
    }
    if (img != NULL)
    {
        if (img -> comment != NULL)
        {
            free (img -> comment);
        }
        if (img -> data != NULL)
        {
            free (img -> data);
        }
        free (img);
    }
    return NULL;
}

Image * Image_load(const char * filename)
{
    
    FILE * fptr = NULL;
    Image *img = NULL;
    
    //size_t read;
    ImageHeader header;
    //Image * tmp_im = NULL,* im = NULL;
    //size_t n_bytes = 0;
    
    fptr = fopen(filename, "r"); // "rb" unnecessary in Linux if (fptr == NULL)
    if (fptr == NULL)
    {
        //fclose(fptr);
        return cleanUp(fptr, img);
    }
    // read the header
    if (fread(&(header),sizeof(ImageHeader),1,fptr) != 1)
    {
        // fread fails
        return cleanUp(fptr, img);
    }
    if (checkHeader(&header) == 0)
    {
        return cleanUp(fptr, img);
    }
    img = malloc(sizeof(Image));
    if (img == NULL)
    {
        return cleanUp(fptr, img);
    }
    int bytes = header.width * header.height * sizeof(uint8_t);
    //img -> data_size = (img -> header).size - sizeof(ImageHeader);
    img -> width = header.width;
    img -> height = header.height;
    img -> data = NULL;
    img -> comment = NULL;
   
    img->comment = malloc(sizeof(char) * header.comment_len);
    if(fread((img->comment), sizeof(char),header.comment_len, fptr) != header.comment_len)
    {
        return cleanUp(fptr, img);
    }
    if(img -> comment[header.comment_len - 1] != '\0')
    {
        return cleanUp(fptr, img);
    }
    
    //free(filename_cpy);
    // this also takes care of file_basename
    //img -> bytes_per_pixel = (img -> header).bits / BITS_PER_BYTE; img -> data = malloc(sizeof(unsigned char) * (img -> data_size));
    img -> data = malloc(bytes);
    if(img->data == NULL){
     return cleanUp(fptr,img);
}
    if (fread(img -> data, sizeof(uint8_t), bytes, fptr) != (bytes))
    {
        // fread fails
        return cleanUp(fptr, img);
    }
    char onebyte;
    if (fread(& onebyte, sizeof(char), 1, fptr) != 0)
    {
        //notattheofthe return cleanUp(fptr,file but the file still has data img);
        return cleanUp(fptr, img);
    }
    // everything successful fclose (fptr);
    fclose (fptr);
    return img;
}
int Image_save(const char * filename, Image * image)
{
    FILE * filepoint = NULL ;
    filepoint = fopen ( filename , "w") ;
    ImageHeader header;
    header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
    header.width = image -> width;
    header.height = image -> height;
    header.comment_len = strlen(image -> comment) + 1;
    if ( filepoint == NULL )
    {
        return 0;
    }
    if(fwrite(&header,sizeof(ImageHeader),1,filepoint) != 1)
    {
        fclose(filepoint);
        return 0;
    }
    if(fwrite(image -> comment, sizeof(char), header.comment_len, filepoint) != (header.comment_len)){
        fclose(filepoint);
        return 0;
    }
    int nbytes = image -> width * image -> height;
    if(fwrite(image -> data, sizeof(uint8_t), nbytes, filepoint) != (nbytes)){
        fclose(filepoint);
        return 0;
    }
    
    fclose(filepoint);
    return 1;
    
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
    int maximum=0;
    int minimum=0;
    int c=0;
    int i=0;
    
    maximum = intensity[0];
    
    for (c = 1; c < width*height; c++)
    {
        if (intensity[c] > maximum)
        {
            maximum  = intensity[c];
        }
    }
    minimum = intensity[0];
    for (c = 1; c < width*height; c++)
    {
        if (intensity[c] < minimum)
        {
            minimum  = intensity[c];
        }
    }
    for(i = 0 ; i < width*height ; i++)
    {
        intensity[i] = (intensity[i] - minimum) * 255.0 / (maximum - minimum);
    }

}
void Image_free(Image * image)
{
    free(image->comment);
    free(image->data);
    free(image);
}



