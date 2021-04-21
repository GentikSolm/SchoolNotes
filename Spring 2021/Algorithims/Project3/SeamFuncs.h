#ifndef SEAMFUNCS_H
#define SEAMFUNCS_H

int** genEnergyMatrix(int**, int, int);
int** vertE(int**, int, int);
int** horizE(int**, int, int);
void delEnergyMatrix(int**, int**, int);
void vertSeam(int**, int**, int, int);
void horizSeam(int**, int**, int, int);

#endif
