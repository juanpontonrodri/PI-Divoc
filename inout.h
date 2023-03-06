#ifndef INOUT_H
#define INOUT_H
void stripe ();
void headline ();
int yes_or_no (char *word);
void get_string (int min, int max, char *prompt, char *my_string);
int get_integer (int min,int max,char *prompt);
char get_character(char *check, char *prompt);
void display_patient(struct aPatient table);
int verify_DNI (char DNI[10]);
#endif
