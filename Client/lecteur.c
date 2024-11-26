#include "lecteur.h"

int GetTampon(BUF **Ptr, char Cle[L_MSG]) {
    BUF *MemTamponPtr;
    int CLTshmid;
    key_t key;

    if ((key = ftok(Cle,'T')) < 0)
        return CLEerr;
    if ((CLTshmid = shmget(key,2*sizeof(BUF),0666|IPC_CREAT)) <0)
        return SHMerr;
    if ((MemTamponPtr = (BUF *)shmat(CLTshmid,NULL,0)) == 0)
        return SHMerr;
    
    *Ptr = MemTamponPtr;
    return CLTshmid;
}

int ReadData(BUF *Tptr, int va) {
	int n;
	n = (Tptr + va)->n;
	printf("receiving data %d in voie %d\n", n, va);
	return va+1;
}

