#include "sound.h"
#include <stdlib.h>

int 
main(void){
	while(1){		// loop forever
		// run system command "arecord" to record 1 sec of wav
		system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		// display WAV header
		dispWAVHeader("test.wav");
		// display WAV strength as decibel values
		dispWAVData("test.wav");
		break;		//loop runs just once
	}
	return 0;
}
