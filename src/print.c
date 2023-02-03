#include "header.h"

void simple_print(Csv_line* head, FILE* output){
  while(head!=NULL){
    fprintf(output, "%s", head->line);
    head = head->child[0];
  }
}

void abr_print(Csv_line* head, FILE* output){
  if(head!=NULL){
    abr_print(head->child[0], output);
    fprintf(output, "%s", head->line);
    abr_print(head->child[1], output);
  }
}
