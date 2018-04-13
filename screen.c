#include "screen.h"
#include <stdio.h>

/**
	function definition of clearScreen()
	This function uses VT100 escape sequence \ESC[2J to make the whole
	terminal screen empty
	argument: no
	return: no
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/**
	function definition of gotoxy()
	This function moves the cursor to the specified row and column
	counting from the bottom left corner
	argument: int int
	return: no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/**
	function definition of setColour()
	This function sets the colour of the text to the one specified
	by the program
	argument: int
	return: no
*/
void setColour(int colour){
	if(colour >= BLACK && colour <= WHITE){
		printf("%c[1;%dm", ESC, colour);
		fflush(stdout);
	}
}

/**
 	function definition of dispBar()
 	This function displays a vertical bar for the given dB value.
 	The value varies between 30 and 80, so we need to render 3dB
 	for one row and 90dB will be displayed as bar of 30 rows
 	argument: int double
 	return: no
*/
void dispBar(int col, double dB){
	int i;
	for(i = 0; i < dB/3; i++){
		gotoxy(30 - i, col + 1);
	// if UNICODE is NOT defined, we use asterisk symbol for the output
#ifndef UNICODE
		printf("%c", '*');
#else
	// if UNICODE IS defined, we use BAR symbol for the output
		if(i < 50/3) setColour(WHITE);
		else if(i < 70/3) setColour(YELLOW);
		else setColour(RED);
		printf("%s", BAR);
#endif
	}	// end of for
}	// end of function
