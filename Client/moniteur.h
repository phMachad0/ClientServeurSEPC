#ifndef MONITEUR_H
#define MONITEUR_H

#include "CL_include"

void EnvoyerIdentifiant(int msqid);

char* ReceiveResponse(int msqid);

void SendACK(int msqid);

void SendDeconnexion(int msqid);

#endif // MONITEUR_H