#include "header.h"

Csv_line* tri_simple(FILE* input, int way){
  Csv_line* root = get_line(input);
  Csv_line* new = get_line(input);
  while(new != NULL){
    Csv_line* head = root;
    if(way=0){
      if(new->first_element < head->first_element){
        new->child[0] = head;
        root = new;
      }
      else{
        while(new->first_element > head->child[0]->first_element){
          head = head->child[0];
        }
        new->child[0] = head->child[0];
        head->child[0] = new;
      }
      new = get_line(input);
    }
    else{
      if(new->first_element > head->first_element){
        new->child[0] = head;
        root = new;
      }
      else{
        while(new->first_element < head->child[0]->first_element){
          head = head->child[0];
        }
        new->child[0] = head->child[0];
        head->child[0] = new;
      }
      new = get_line(input);
    }
  }
  return root;
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

Csv_line* tri_abr(FILE* input){
  Csv_line* root = get_line(input);
  Csv_line* new = get_line(input);
  while(new != NULL){
    add_abr(root, new);
    new = get_line(input);
  }
  return root;
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
  else return 1+max_(get_height(head->child[0]), get_height(head->child[1]));
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

Csv_line* tri_avl(FILE* input){
  Csv_line* root = get_line(input);
  Csv_line* new = get_line(input);
  while(new != NULL){
    add_abr(root, new);
    root = check_stability(root);
    new = get_line(input);
  }
  return root;
}
