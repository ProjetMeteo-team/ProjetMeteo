#include "header.h"

Csv_line* get_line(FILE* input){
  char* line=NULL;
  size_t size = 0;
  Csv_line* x = malloc(sizeof(Csv_line));
  if(x==NULL){
    printf("error: couldn't create required variable")
    exit(1);
  }
  int n = getline(&line, &size, input)
  if(n != -1){
    char* line_temp = malloc(sizeof(char) * n)
    strcpy(line_temp, line);
    char* StrToken = strtok(line_temp, ";");
    strcpy(x->line, line);
    strcpy(x->first_element, StrToken);
    return x;
  }
  else{
    printf("error: couldn't read line");
    exit(1);
  }
}

void tri_simple(FILE* input){

}

void tri_abr(FILE* input){

}

void tri_avl(FILE* input){

}

int main(int argc, char** argv){
  if(argc<2){
    printf("error: missing arguments in sorting");
    exit(1)
  }
  char filename[100]={};
  strcpy(filename, argv[0]);
  FILE* input = fopen(filename, "r+");
  if (input==NULL){
    printf("error: couldn't open file");
    exit(1);
  }
  int sort = argv[1][0] - '0';
  if(sort == 1) tri_simple(input);
  else if(sort == 2) tri_abr(input);
  else if(sort == 3 || sort == 0) tri_avl(input);
  else{
    printf("errror: no valid sort method")
    exit(1);
  }
}
