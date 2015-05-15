#Makefile for AverageHours project
all:
	gcc -g hours.c -o ./hours -lcurl
	gcc -g togglData.c -o ./togglData -lcurl

clean:
	-rm -r *.o *.out yearsum.c hours togglData *.dSYM/
