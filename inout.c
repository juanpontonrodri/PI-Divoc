#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>
#include "database.h"
#include "inout.h"


int yes_or_no (char *word){ //receives the word and asks for 'y' or 'n' 
  char car;                 //(upper or lowercase) to confirm
  do{                       // it keeps asking is the character is not correct
   car=get_character("y/n",word);
   if (car=='Y'){ 
     printf("\n");
     return 1;
   }
   else {
     if (car=='N'){
       return 0;
     }
   }
  }while ((car!='Y') || (car!='N'));
  return 1;
}

void headline () {//displays the middle line of the box title
  int i;
  printf("|");
  for (i=0;i<21;i++){
    printf(" ");
  }
  printf("DIVOC_");
  for (i=0;i<21;i++){
    printf(" ");
  }
  printf("|");
  printf("\n");
  return;

}

void stripe() {   //writes a 50 characters (+) stripe
  int i;
  for (i=0;i<50;i++){          
    fprintf(stdout, "-");
  }
  printf("\n");
  return;
}
void get_string (int min, int max, char *prompt, char *my_string){ //Displays the prompt passed and asks for a string
  char input[256], rest[256], word[256];                                     //If it's legnth is bigger than max or less than min it keeps asking
  int length, x=0, OK=0;                                             //If it' s correct it assigns it to the variable
  do {                                                             //my string passed by reference
    printf( "\n%s (%d-%d char):",prompt,min,max);
    fgets(input,sizeof(input), stdin);
    x=sscanf(input, "%s%s",word,rest);
    if (x==1) {
      length=strlen(word);
      if ((length>=min)&&(length<=max)) OK=1;
    }
  } while (OK==0);
  strcpy(my_string,word);
  return;
}
int get_integer (int min,int max,char *prompt){         //Asks for an integer (displaying the prompt given by reference)
  int number,x=0,OK=0;                                           //between 1 and 25 until it is correct. Then it is returned
  char input[256], rest[256];  
do{
    fprintf(stdout, "\n%s [%d-%d]:",prompt,min,max);
    fgets(input,sizeof(input), stdin);
    x=sscanf(input, "%d%s",&number,rest);
    if (x==1){
        if((number>=min) && (number<=max)) OK=1;
  }} while (OK==0);
  return number;
}

char get_character(char *check, char *prompt){              //check is the string where the character must exist to be correct
  int x=0, OK=0;                                                  //prompt is the string showed to ask
  char input[256],rest[256];
  char character;                                          
  do{                                                     //keeps asking until it only reads 1 character and it is located inside check
    printf("\n%s (%s) :", prompt, check);
    fgets(input,sizeof(input),stdin);
    x=sscanf(input, "%c%s",&character,rest) ;
    if (x==1) {
      if (strchr(check,character)!=NULL) OK=1;
      if (strchr(check,toupper(character))!=NULL) OK=1;
      if (strchr(check,tolower(character))!=NULL) OK=1;
    }
  } while(OK==0);

  return toupper(character);

}

void display_patient(struct aPatient table){
    printf(">%24s;%s;%hd;%d;%d;%c;\n",table.NAME, table.DNI,table.AGE,table.FEVER,table.COUGH,table.SYMPTOM);
    return;
    }

int verify_DNI (char DNI[10]){
    int number,index,i;
    char string[9], check[]="TRWAGMYFPDXBNJZSQVHLCKE";
    char c;
    sscanf(DNI, "%8s%c",string,&c);       //it splits the DNI string into string(the numbers) and c(character)
    for(i=0;i<8;i++){
        if (isdigit(string[i])==0) return 0; //isdigit returns a 0 when it is not a digit so it returns a 0 if one od the first 8 characters is not a digit
}
    number=atoi(string);                  //atoi converts the string numbers into an integer
    index=number%23;                      //calculates the reminder 
    if (check[index]==c){                 //if the character c is equal to the character in position of the reminder 
      return 1;                           //inside the check string it is correct
    }
    else return 0;
}
