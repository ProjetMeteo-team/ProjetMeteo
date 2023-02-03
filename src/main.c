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
    x->first_element = atoi(StrToken);
    x->child[0] = NULL;
    x->child[1] = NULL;
    return x;
  }
  else{
    return NULL;
  }
}

void tri_simple(FILE* input){
  Csv_line* root = get_line(imput);
  Csv_line* new = get_line(imput);
  while(new != NULL){
    Csv_line* head = root;
    if(new->first_element < head->first_element){
      new->child[0] = head;
      root = new;
    }
    else{
      while(new->first_element > head->child->first_element){
        head = head->child[0];
      }
      new->child[0] = head->child[0];
      head->child[0] = new;
    }
    new = get_line(imput);
  }
}

void add_abr(Csv_line* head, Csv_line* new){
  if(new->first_element < head->first_element){
    if(head->child[0] == NULL){
      head->child[0] = new;
    }
    else{
      add_abr(head->child[0], new);
    }
  }
  else{
    if(head->child[1] == NULL){
      head->child[1] = new;
    }
    else{
      add_abr(head->child[1], new);
    }
  }
}

void tri_abr(FILE* input){
  Csv_line* root = get_line(imput);
  Csv_line* new = get_line(imput);
  add_abr(root, new);
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
