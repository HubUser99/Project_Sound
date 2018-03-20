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

// function definition of dispWAVData()
void
dispWAVData(char filename[]){
	int i, j;	// loop counters
	FILE* fp;	// file handler to open the file "test.wav"
	double rms[80], sum;	// 80 pieces of RMS value
	short samples[SAMPLERATE];	// totally 16000 samples in 1 sec
	WAVHeader mh;	// just used to skip over the header of wav file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when opening the file!\n");
		return;
	} 
	fread(&mh, sizeof(mh), 1, fp);
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	for(i = 0; i < 80; i++){
		for(j = 0, sum = 0.0; j < SAMPLERATE / 80; j++){
			sum += pow(samples[j + i * 200], 2.0);
		}
		rms[i] = sqrt(sum / 200);
		printf("rms[%d]: %10.4f\n", i, rms[i]);
	}
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
	printf("  audio format: %d\n", mh.audioFormat);
	printf("  number of channels: %d\n", mh.numChannels);
	printf("  sample rate: %d\n", mh.sampleRate);
	printf("  byte rate: %d\n", mh.byteRate);
	printf("  block align: %d\n", mh.blockAlign);
	printf("  bits per sample: %d\n", mh.bitsPerSample);
	printf("Subchunk 2 ID: ");
	printID(mh.subchunk2ID);
	printf("  subchunk 2 size: %d\n", mh.subchunk2Size);
}
