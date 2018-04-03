#include "screen.h"
#include <stdio.h>

// function definition of clearScreen()
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

// function definition of gotoxy()
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

// function definition of setColour()
void setColour(int colour){
	if(colour >= BLACK && colour <= WHITE){
		printf("%c[1;%dm", ESC, colour);
		fflush(stdout);
	}
}

// function definition of dispBar(), this function displays a vertical
// bar for the given dB value. The value varies between 30 and 80, so 
// we need to render 3dB for one row and 90dB will be displayed as bar 
// of 30 rows
void dispBar(int col, double dB){
	int i;
	for(i = 0; i < dB/3; i++){
		gotoxy(30 - i, col + 1);
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i < 50/3) setColour(WHITE);
		else if(i < 70/3) setColour(YELLOW);
		else setColour(RED);
		printf("%s", BAR);
#endif
	}	// end of for
}	// end of function
