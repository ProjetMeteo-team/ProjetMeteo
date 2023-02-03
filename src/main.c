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

Csv_line* add_abr(Csv_line* head, Csv_line* new){
  if(head = NULL) return new;
  if(new->first_element < head->first_element){
    head->child[0] = add_abr(head->child[0], new);
  }
  else{
    head->child[1] = add_abr(head->child[1], new);
  }
  return head;
}

void tri_abr(FILE* input){
  Csv_line* root = get_line(imput);
  Csv_line* new = get_line(imput);
  while(new != NULL){
    add_abr(root, new);
    new = get_line(imput);
  }
}

Csv_line* rotate(Csv_line* head, int x){
  Csv_line* pivot = head->child[!x];
  head->child[!x] = pivot->child[x];
  pivot->child[x] = head;
  return pivot;
}

int get_height(Csv_line* head){
  if(head == NULL) return 0;
  else if(head->child[0]==NULL && head->child[1]==NULL) return 1;
  else return 1+max(get_height(head->child[0]), get_height(head->child[1]));
}

Csv_line* check_stability(Csv_line* head){
  if(head->child[0]!=NULL) head->child[0] = check_stability(head->child[0]);
  if(head->child[1]!=NULL) head->child[1] = check_stability(head->child[1]);
  int stability = get_height(head->child[1]) - get_height(head->child[0]);
  if(stability>1){
    int stability2 = get_height(head->child[1]->child[1]) - get_height(head->child[1]->child[0]);
    if(stability2<0){
      head->child[1] = rotate(head->child[1], 1);
      return rotate(head, 0);
    }
    else{
      return rotate(head, 0);
    }
  }
  else if(stability<-1){
    int stability2 = get_height(head->child[0]->child[1]) - get_height(head->child[0]->child[0]);
    if(stability2>0){
      head->child[0] = rotate(head->child[0], 0);
      return rotate(head, 1);
    }
    else{
      return rotate(head, 1);
    }
  }
}

void tri_avl(FILE* input){
  Csv_line* root = get_line(imput);
  Csv_line* new = get_line(imput);
  while(new != NULL){
    add_abr(root, new);
    root = check_stability(root);
    new = get_line(imput);
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
