#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yankTemp(char* device, int verbose);
void usage();

int yankTemp(char* device, int verbose) {
FILE *fp;
int n;
char buf[101];
char temp[7];
char checkError[1];
int i;
char firstPathSegment[] = "/sys/bus/w1/devices/";
char thirdPathSegment[] = "/w1_slave";

strcat(strcat(firstPathSegment, device), thirdPathSegment);
if((fp = fopen(firstPathSegment, "r")) == (FILE *)NULL) {
exit(1);
}



/*fp = fopen(firstPathSegment, "r");
*/
n = fread(buf, 1, 100, fp);

buf[n] = '\0';

checkError[0] = buf[0];

if(checkError[0] == '0')
exit(1);

for(i = 0; i < 5; i++) 
temp[i] = buf[69 + i];
temp[5] = '\0';
printf("%s\n", temp);


if(verbose)
printf("%s", buf);


(void) fclose(fp);
return 0;
}

void usage() {
printf("Error");
exit(1);

}


