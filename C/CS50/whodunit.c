#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[]){

	if (argc < 3){	// if not given read/write files names
		fprintf(stderr, "%s\n", "You should provide two command-line arguments!");
		return 1;
	}

	// define files pointers
	char *readFileName = argv[1];
	char *writeFileName = argv[2];

	// open files to operate
	FILE *readFile = fopen(readFileName, "r");
	FILE *writeFile = fopen(writeFileName, "w");

	if (readFile == NULL){
		fclose(readFile);
		fprintf(stderr, "%s\n", "failed opening the read file!");
		return 2;
	}

	if (writeFile == NULL){
		fclose(writeFile);
		fprintf(stderr, "%s\n", "failed opening the write file!");
		return 3;
	}

	// fetch the bmp metadata structs
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;

	// if not correct format of the BMP file shutdown the program with error
	fread(&bfh, sizeof(BITMAPFILEHEADER), 1, readFile);
	if ((bfh.bfType != 0x4d42) || (bfh.bfOffBits != 54) || (bih.biSize != 40) || (bih.biBitCount != 24) || (bih.biCompression != 0)){
		fclose(readFile);
		fclose(writeFile);
		fprintf(stderr, "%s\n", "Check file fromat bmp file not recognized!");
		return 4;
	}

	// write the metadata to the new output file.
	fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, writeFile);
	fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, writeFile);

	// compute padding for the output file
	int padding = (4 - (bih.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	// iterating over each pixel in the readfile line by line
	for (int i = 0, height = abs(bih.biHeight); i < height; i++){
		for (int j = 0, width = abs(bih.biWidth); j < width; j++){
			RGBTRIPLE rgb;	// pixel triple struct
			// fetch the rgb triple of current pixel
			fread(&rgb, sizeof(RGBTRIPLE), 1, readFile);
			if (rgb.rgbtRed == 255){  // if it is a red pixel
				// then make it white
				rgb.rgbtBlue = 255;  
				rgb.rgbtGreen = 255;
			}
			// write the new cleaned pixel into the output file
			fwrite(&rgb, sizeof(RGBTRIPLE), 1, writeFile);
		}
		// apply padding and updating cursor location
		fseek(readFile, padding, SEEK_CUR);
		for (int k = 0; k < padding; k++){
			fputc(0x00, writeFile);
		}
	}
	// when done close the read/write files
	fclose(readFile);
	fclose(writeFile);
	return 0;
}