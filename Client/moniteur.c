#include "moniteur.h"

char *Cle;

void Moniteur() {
	while (1)
	{
		static int Msqid;

		Msqid = CreationMessagerie();

		EnvoyerIdentifiant(Msqid);
		MsgTimout(1);
		Cle = ReceiveResponse(Msqid);
		MsgTimout(1);
		int pid_canaux;
		pid_canaux = fork();

	}
	
}

void EnvoyerIdentifiant(int msqid) {
	dmsgbuf message;
	int CPID = getpid();
	sprintf(message.txt,"%d",CPID);
	message.type = CONNECT;

	if (msgsnd(msqid,&message,strlen(message.txt) + 1,0) < 0) {
		printf("Cl:erreur send CONNECT INFOC :%d\n",CPID);
	} else {
		printf("Cl:CONNECT sended INFOC :%d\n",CPID);
	}
}

char* ReceiveResponse(int msqid) {
	dmsgbuf message;
	int erreur;
	int CPID = getpid();
	message.type = CPID;
	if ((erreur=msgrcv(msqid,&message,L_MSG,message.type,0)) <0) {
		if (errno==EINTR)
			erreur=0;
		else
			printf("Cl:Erreur %d RecepMessage:%s %ld\n",errno,message.txt,message.type);
		return NULL;
	} else {
		printf("Cl:Reception MESSAGE:%s %ld\n",message.txt,message.type);
	}
	
	SendACK(msqid);
	char* cle = malloc(strlen(message.txt) + 1);
    if (cle != NULL) {
        strcpy(cle, message.txt);
    }

	return cle;

}

void SendACK(int msqid) {
	dmsgbuf message;
	int CPID = getpid();
	message.type = ACK;

	if (msgsnd(msqid,&message,strlen(message.txt) + 1,0) < 0) {
		printf("Cl:erreur send ACK INFOC :%d\n",CPID);
	} else {
		printf("Cl:ACK sended INFOC :%d\n",CPID);
	}	
}

void SendDeconnexion(int msqid) {
	dmsgbuf message;
	int CPID = getpid();
	sprintf(message.txt,"%d",CPID);
	message.type = DECONNECT;

	if (msgsnd(msqid,&message,strlen(message.txt) + 1,0) < 0) {
		printf("Cl:erreur send DECONNECT INFOC :%d\n",CPID);
	} else {
		printf("Cl:DECONNECT sended INFOC :%d\n",CPID);
	}
}