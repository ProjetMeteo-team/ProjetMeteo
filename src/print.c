#include "header.h"

void simple_print(Csv_line* head, FILE* output){
  while(head!=NULL){
    fprintf(output, "%s", head->line);
    head = head->child[0];
  }
}

void abr_print(Csv_line* head, FILE* output, int way){
  if(head!=NULL){
    if(way=0){
      abr_print(head->child[0], output, way);
      fprintf(output, "%s", head->line);
      abr_print(head->child[1], output, way);
    }
    else{
      abr_print(head->child[1], output, way);
      fprintf(output, "%s", head->line);
      abr_print(head->child[0], output, way);
    }
  }
}
