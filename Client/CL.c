#include "moniteur.h"
// #include "CL.h"
// #include "redacteur.h"
#include "lecteur.h"
#include "../Serveur/SV_msg.h"

void litbuf1();
void litbuf2();

int voie;			/*variable globale (numero du canal a lire)*/
static int MoniteurID, LecteurID, RedacteurID;
BUF *TamponPtr;

int CreationMessagerie()
{
	key_t key;
	int msqid;
	if (( key = ftok(CleServeur,'M')) < 0 )
		return CLEerr;
	msqid = msgget(key,0666|IPC_CREAT);
	return msqid;
}

void AlarmeTimeout(int s){
};

void MsgTimout(int n)
{
	signal(SIGALRM,AlarmeTimeout);
	alarm(n);
}

int main(int argc, char *argv[])
{
	  /* ... */


	signal(SIGUSR1, litbuf1);
	signal(SIGUSR2, litbuf2);

	printf("\n* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("Projet CLIENT - SERVEUR\tTemps R�el E2i - Novembre\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	// printf("\nLancement du client pendant %d secondes\n", nb_iteration);
	

    /* TO BE CONTINUED */
	static int Msqid;
	
	Msqid = CreationMessagerie();

	EnvoyerIdentifiant(Msqid);
	MsgTimout(1);
	Cle = ReceiveResponse(Msqid);
	MsgTimout(1);
	// SendDeconnexion(Msqid);

	// if ((LecteurID = fork()) == -1) {
	// 	return 0;	
	// }

	GetTampon(&TamponPtr, Cle);

	while (1) {
	}


return 0;
}	   	   
	   	   	   
/*/////////////////////////////////////////////////////////////////////////*/
	   
void litbuf1() /* semaphore 0 */
{
	voie=0;
	signal(SIGUSR1,litbuf1);
	ReadData(TamponPtr, voie);
}


/*/////////////////////////////////////////////////////////////////////////*/

void litbuf2()
{
	voie=1;	
	signal(SIGUSR2,litbuf2);
	ReadData(TamponPtr, voie);
}
