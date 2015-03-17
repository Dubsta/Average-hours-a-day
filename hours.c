// Given input of the total hours for the year,
// Outputs the average hours per day.

// Michael Atkinson
// Mikeatk88@gmail.com

#include <stdio.h>
#include <time.h>

int main(void)
{
	// Get total hours for the year
	printf("Enter total hours for the year: \n");
	int hours, mins;
	scanf("%d", &hours);
	printf("You have logged %d hours\n", hours, mins);
	
	// Get the time
	time_t rawtime;
	time(&rawtime);	

	// Get day of the year from time.h
	struct tm *now;
	now = localtime(&rawtime);
	int yearday = now->tm_yday + 1;
	printf( "%s", asctime(now) );
	printf("I've counted %d days for the year.\n", yearday);

	// Calc average hours per day
	
	return 0;
}
