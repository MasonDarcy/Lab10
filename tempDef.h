#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
static float lowestTempNum;
static float currentTempNum;
static float highestTempNum;

void setTempVariables(int newestTemp);
void timeDelay(int number_of_seconds);
int charToInt(char in[]);
char * intToChar(int num);


char * intToChar(int num) {
char *ptr;
char output[5] = "junk";
sprintf(output, "%d", num);
ptr = output;
return ptr;
}


void setTempVariables(int newestTemp) {
if(newestTemp < lowestTempNum)
	lowestTempNum = newestTemp;

if(newestTemp > highestTempNum)
	highestTempNum = newestTemp;


}

int charToInt(char in[]) {
int q;
sscanf(in, "%d", &q);
return q;
}

void timeDelay(int number_of_seconds) {
int milli_seconds = 1000 * number_of_seconds;
clock_t start_time = clock();
while(clock() < start_time + milli_seconds)
	;
}
