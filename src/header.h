#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Csv_lineS{
	int first_element;
	char line[300];
  struct Csv_lineS* child[2];
} Csv_line;

int max_(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
