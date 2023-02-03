#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Csv_lineS{
	int first_element;
	char line[300];
  struct Csv_lineS* child;
} Csv_line;
