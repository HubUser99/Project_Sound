# Project_Sound

This program allows user to record a short fragment of sound, display the sound levels
and send the data to the server.

## Getting Started

### Prerequisites

To run the program you need to use a Raspberry Pi 3 computer, an external soundcard and a microphone.

1) Boot up RPi, and apply the USB sound card.

2) RPi onboard sound card doesn’t have microphone interface. We have to change the default audio device to be USB sound card.

3) Use “lsusb” command to check if your USB sound card is mounted:
```
pi@raspberrypi:~ $ lsusb
Bus 001 Device 004: ID 0d8c:000c C-Media Electronics, Inc. Audio Adapter
Bus 001 Device 003: ID 0424:ec00 Standard Microsystems Corp. SMSC9512/9514 Fast Ethernet Adapter
Bus 001 Device 002: ID 0424:9514 Standard Microsystems Corp.
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```

4) Use “sudo nano /etc/asound.conf”command and put following content to the file:
```
pcm.!default {
	type plug
	slave {
		pcm "hw:1,0"
	}
}
ctl.!default {
	type hw
	card 1
}
```

5) Go to your home directory. Use “nano .asoundrc” command and put the same content to the file.

6) Run “alsamixer” you should be able to see that USB sound card is the default audio device.
```
┌───────────────────────────────────────────── AlsaMixer v1.0.28 ──────────────────────────────────────────────┐
│ Card: C-Media USB Headphone Set                                                      F1:  Help               │
│ Chip: USB Mixer                                                                      F2:  System information │
│ View: F3:[Playback] F4: Capture  F5: All                                             F6:  Select sound card  │
│ Item: Headphone [dB gain: -20.13, -20.13]                                            Esc: Exit               │
│                                                                                                              │
│                                                                                                              │
│                                  ┌──┐               ┌──┐                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │  │                                                     │
│                                  │  │               │▒▒│                                                     │
│                                  │  │               │▒▒│                                                     │
│                                  │  │               │▒▒│                                                     │
│                                  │  │               │▒▒│                                                     │
│                                  │  │               │▒▒│                                                     │
│                                  │▒▒│               │▒▒│                                                     │
│                                  │▒▒│               │▒▒│                                                     │
│                                  ├──┤               ├──┤               ┌──┐                                  │
│                                  │OO│               │MM│               │OO│                                  │
│                                  └──┘               └──┘               └──┘                                  │
│                                 19<>19               52                                                      │
│                          <    Headphone     >       Mic         Auto Gain Control                            │
│                                                                                                              │
│                                                                                                              │
└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
```

Copy the source files of the project to your local directory from the GitHub.
Use link: https://github.com/HubUser99/Project_Sound.git

In order to compile the program you would have to use GNU compiler so please make sure that
you have it installed beforehand.

### Installing

Run "make" command inside the project folder to create an executable file.

## Running the tests

To run the program, execute the sound.a file in the project folder.

To stop the program, use the keys combination "Ctrl+C".

To run the program in "non-UNICODE" mode, apply comment style to the definition
of the UNICODE in the "screen.h" file.

To run the program in the debug mode, remove comment style from the DEBUG definition
in the "sound.h" file.

To prevent program from sending data to the server, apply comment style to the
definition of the COMM in the "comm.h" file.

