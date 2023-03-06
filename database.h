#ifndef DATABASE_H
#define DATABASE_H
struct aPatient { //Structure definition
  char NAME[25];
  char DNI[10];
  short AGE;
  char FEVER;
  char COUGH;
  char SYMPTOM;
};
int p_register (struct aPatient *table, int *number);
int p_search (struct aPatient *table, int *number);
int p_discharge (struct aPatient *table, int *number);
int p_list (struct aPatient *table, int *number);
int p_mark(struct aPatient *table, int *number);
int p_exit(struct aPatient *table, int *number);
#endif
