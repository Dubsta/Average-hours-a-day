// Given input of the total hours for the year,
// Outputs the average hours per day.

// Michael Atkinson
// Mikeatk88@gmail.com

#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void)
{
	// Get total hours for the year
	printf("Enter total hours for the year: ");
	int hours;
	scanf("%d", &hours);
	
	// Get the time
	time_t rawtime;
	time(&rawtime);	

	// Get day of the year from rawtime
	struct tm *now;
	now = localtime(&rawtime);
	int yearday = now->tm_yday + 1;
	printf( "As of %s", asctime(now) );

	// Calc average hours per day
	float avrgHours = (float)hours / yearday;

	// Calc remainder for the year
	int estimated = avrgHours * 365;

	// Calc mins
	int decimins = round(avrgHours * 100);
	decimins %= 100;
	int realmins = round(decimins * 0.6);
	printf("You average %d hours and %d mins over %d days.\n", (int)avrgHours, realmins, yearday);
	printf("At this rate you will accumalate %d hours by the end of the year\n", estimated);
	return (int)avrgHours;
}
