#ifndef LECTEUR_H
#define LECTEUR_H

#include "CL_include"

int GetTampon(BUF **Ptr, char Cle[L_MSG]);
int ReadData(BUF *Tptr, int va);

#endif // LECTEUR_H