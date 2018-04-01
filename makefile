OBJ = main.o comm.o sound.o screen.o 
DEPS = sound.h screen.h

APPNAME = sound.a

#link rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm
#compiling rule
%.o : %.c $(DEPS)
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)	

tar :
	tar cf project.tar *

backup :
	scp project.tar e1700698@shell.puv.fi:.

git :
	git add *.c *.h makefile
	git commit -a --allow-empty-message -m ''
	git push origin master

plot :
	scp test.wav ../PySound/
	python3 ../PySound/plot.py
	scp graph.png e1700698@shell.puv.fi:.	
