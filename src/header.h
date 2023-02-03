#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LineS{
	char first_element[50];
	char line[300];
  struct LineS* child;
} Line;
