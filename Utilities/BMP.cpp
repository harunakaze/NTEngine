#include "BMP.h"
#include <stdio.h>
#include <stdlib.h>

char * load_bmp(const char * fileName, int * width, int * height, int * obpp) {
	FILE *file;
	short int bpp;
	short int planes;
	long size;
	short int colorTotalByte;

	long imwidth;
	long imheight;
	char *imdata;

	if (!(file = fopen(fileName, "rb"))) {
		fprintf(stderr, "Error: file %s not found!\n", fileName);
	};
	fseek(file, 18, SEEK_CUR);

	fread(&imwidth, 4, 1, file);
	fread(&imheight, 4, 1, file);
	fread(&planes, 2, 1, file);
	fread(&bpp, 2, 1, file);

	if (bpp == 24) {
		colorTotalByte = 3;
	}
	else {
		colorTotalByte = 4;
	}

	size = imwidth * imheight * colorTotalByte;
	fseek(file, 24, SEEK_CUR);
	imdata = new char[size];

	fread(imdata, size, 1, file);

	char temp;
	for (long i = 0; i < size; i += colorTotalByte){
		temp = imdata[i];
		imdata[i] = imdata[i + 2];
		imdata[i + 2] = temp;
	}

	fclose(file);

	*width = imwidth;
	*height = imheight;
	*obpp = bpp;

	return imdata;
}