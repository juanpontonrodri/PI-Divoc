#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>
#include "database.h"
#include "inout.h"


int p_register (struct aPatient *table, int *number){
  printf("\nRegister\n"); 
  (*number)++; 
  get_string(1,24,"Name",table[(*number)-1].NAME);
  get_string(9,9,"DNI",table[(*number)-1].DNI);
  while (verify_DNI (table[(*number)-1].DNI)!=1)
  {
    printf("\nInvalid DNI");
    get_string(9,9,"DNI",table[(*number)-1].DNI);  
  }
  table[(*number)-1].AGE=get_integer (1900,2020, "Date");
  table[(*number)-1].FEVER=yes_or_no("Fever");
  table[(*number)-1].COUGH=yes_or_no("Cough");
  table[(*number)-1].SYMPTOM=get_character("FSTMN", "Symptom");
  printf("\nNew patient:\n");
  display_patient(table[(*number)-1]);
  return 0;
}

int p_search (struct aPatient *table, int *number){
  char DNI[10];
  int i;
  printf("\nSearch\n");
  if (*number==0){
    printf("\nNo patients yet\n");
    return -1;
  }
  get_string(9,9,"DNI",DNI);
  for ( i = 0; i < *number; i++)
  {
    if (strcmp(DNI,table[i].DNI)==0)    //strcmp returns 0 if the strings are identical
    {
      printf("\nPatient data:\n");
      display_patient(table[i]);
      return -1;
    } 
  }
  printf("\nUnknown patient\n");
  return 0;
}

int p_discharge (struct aPatient *table, int *number){
  char DNI[10];
  int i,k;
  printf("\nDischarge\n");
  if (*number==0){
    printf("\nNo patients yet\n");
    return -1;
  }
  get_string(9,9,"DNI",DNI);
  for ( i = 0; i < *number; i++)
  {
    if (strcmp(DNI,table[i].DNI)==0)    //strcmp returns 0 if the strings are identical
    {
      for ( k = i; k < (*number)-1; k++)
      {
        table[k]=table[k+1];
      }
      (*number)--;
      printf("\nDischarged patient\n");
      return -1;
    }
  }
  printf("\nUnknown patient\n");
  return 0;
}

int p_list (struct aPatient *table, int *number){
  int i,date;
  printf("\nList\n");
  if ((*number)==0){
    printf("\nNo patients yet\n");
    return -1;
  }
  date=get_integer(1900,2020,"Date");
  printf("\nPatients born before %d:\n\n",date);
  for ( i = 0; i < (*number); i++)
  {
    if (table[i].AGE<=date)    
    {
      display_patient(table[i]);
    }
}
return 0;
}

int p_mark(struct aPatient *table, int *number){
  int i;
  printf("\nPositives\n");
  if (*number==0){
    printf("\nNo patients yet\n");
    return -1;
  }
  printf("\nPositive patients:\n\n");
  for ( i = 0; i < *number; i++)
  {
    if ((table[i].FEVER==1)&&(table[i].COUGH==1)&&(table[i].SYMPTOM!='N'))    
    {
      display_patient(table[i]);
    }
    
  }
  return 0;

}

int p_exit(struct aPatient *table, int *number){
  printf("\nExit\n");
  if((yes_or_no("Are you sure you want to exit the program?"))==1){
    int i=0;
    FILE *file;
    char *file_name="patients.txt";
    file=fopen(file_name,"w");
    while (i<(*number))
    {
      fprintf(file,"%s %s %hd %d %d %c\n",table[i].NAME, table[i].DNI,table[i].AGE,table[i].FEVER,table[i].COUGH,table[i].SYMPTOM);
      i++;
    }

    fclose(file);
    return 1;
  }
  else
  {
    return 0;
  }
}
