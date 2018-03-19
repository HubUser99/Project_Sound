#include "sound.h"
#include <stdio.h>
#include <math.h>
// function definition of printID()
void
printID(char id[]){
	int i;
	for(i = 0; i < 4; i++){
		printf("%c", id[i]);
	}
	printf("\n");
}

// function definition of dispWAVHeader()
void
dispWAVHeader(char filename[]){
	FILE *fp;
	WAVHeader mh;	// an instance of WAVHeader struct
	
	// open the test.wav file for reading
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when opening the file!\n");
		return;	// function stops
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp);	//close the opened file
	printf("Chunk ID: ");
	printID(mh.chunkID);
	printf("  chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf("  subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf("  subchunk 1 size: %d\n", mh.subchunk1Size);
	//tbc.
}
