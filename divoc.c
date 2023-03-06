#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>
#include "database.h"
#include "inout.h"


int p_init(struct aPatient *table, int *number);

int main() {
  char a;
  int finish=0;
  struct aPatient thePatients[100];
  int numPatients=0;
  p_init(thePatients, &numPatients);
  //Title:
  stripe ();
  headline();
  stripe();
  //Menu:
  do {
      printf("\n\nR) Register a patient\n");
      printf("S) Search for a patient\n");
      printf("D) Discharge a patient\n");
      printf("L) List patients by age\n");
      printf("P) Mark positive\n");
      printf("\nX) Exit the program\n");
      a=get_character("RSDLPX", "Choose an option");
    switch (a){
    case 'R':
      p_register(thePatients, &numPatients);
      break;
    case 'S':
      p_search(thePatients, &numPatients);
      break;
    case 'D':
      p_discharge(thePatients, &numPatients);
      break;
    case 'L':
      p_list(thePatients, &numPatients);
      break;
    case 'P':
      p_mark(thePatients, &numPatients);
      break;
    case 'X':
      finish=p_exit(thePatients, &numPatients); 
      break;
    }}
    while (finish==0);
  return 0;
  }


int p_init(struct aPatient *table, int *number){
  char string[256];
  FILE *file;
  char *file_name="patients.txt";
  file=fopen(file_name,"r");
  if (file!=NULL){
  while ((fgets (string, sizeof(string), file)) != NULL){
    sscanf(string,"%s%s%hd%hhd%hhd %c",table[*number].NAME,table[*number].DNI,&table[*number].AGE,&table[*number].FEVER,&table[*number].COUGH,&table[*number].SYMPTOM);
    (*number)++;  
  }
  fclose (file);
}
  return 0;
}



