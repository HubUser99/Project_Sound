#include "sound.h"
#include <stdlib.h>
#include <signal.h>

int 
main(void){
	int ret;
	while(1){		// loop forever
		// run system command "arecord" to record 1 sec of wav
		ret = system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT)) break;
		// display WAV header
		dispWAVHeader("test.wav");
		// display WAV strength as decibel values
		dispWAVData("test.wav");
		//break;		//loop runs just once
	}
	return 0;
}
