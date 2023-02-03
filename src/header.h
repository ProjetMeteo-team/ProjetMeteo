#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Csv_lineS{
	int first_element;
	char line[300];
  struct Csv_lineS* child[2];
} Csv_line;

int max_(int a, int b);
Csv_line* tri_simple(FILE* input);
Csv_line* tri_abr(FILE* input);
Csv_line* tri_avl(FILE* input);
void simple_print(Csv_line* head, FILE* output);
void abr_print(Csv_line* head, FILE* output);
Csv_line* get_line(FILE* input);
