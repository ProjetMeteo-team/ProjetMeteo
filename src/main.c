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
    if(line_temp==NULL){
      printf("error: couldn't create required variables")
      exit(1);
    }
    strcpy(line_temp, line);
    char* StrToken = strtok(line_temp, ";");
    strcpy(x->line, line);
    x->first_element = atoi(StrToken);
    x->child[0] = NULL;
    x->child[1] = NULL;
    return x;
  }
  else{
    return NULL;
  }
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
