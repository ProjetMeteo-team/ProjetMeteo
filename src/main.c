#include "header.h"

void get_line(){
  char* line=NULL;
  size_t size = 0;
  while((getline(&line, &size, input)) != -1){

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
    return 1;
  }
  char filename[100]={};
  strcpy(filename, argv[0]);
  FILE* input = fopen(filename, "r+");
  if (input == NULL) {
    printf("error: couldn't open file");
    return 1;
  }
  int sort = argv[1][0] - '0';
  if(sort == 1) tri_simple(input);
  else if(sort == 2) tri_abr(input);
  else if(sort == 3) tri_avl(input);
  else{
    printf("errror: no valid sort method")
    return 1;
  }
}
