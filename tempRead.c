#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tempReadDef.h"


int main(int argc, char *argv[]) {
int errorValue = 0;
char *device = "28-021313bf95aa";
int verbose = 0;
argc--; argv++;
while(argc > 0) {
printf("%d %s\n", argc, argv[0]);
if(!strcmp("-v", argv[0])) {
verbose = 1;
} else if (!strcmp("-d", argv[0])) {
if(argc == 0)
usage();
argc--; argv++;
device = argv[0];
} else 
usage();
argc--; argv++;
}

errorValue = yankTemp(device, verbose);
exit(errorValue);


}
