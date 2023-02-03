#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Csv_lineS{
	char first_element[50];
	char line[300];
  struct Csv_lineS* child;
} Csv_line;
