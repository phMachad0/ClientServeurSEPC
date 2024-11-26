CC = gcc
INCLUDE_PATH = ./Client
 # -g enables debugging
 # -Wall enables compiler warnings
 # -ansi enforces ANSI C standards
 # -D _SVID_SOURCE: Defines the _SVID_SOURCE macro, which could add compatibility with System V libraries.
# -c compile source to object files without linking
CFLAG = -g -Wall -D _SVID_SOURCE -I $(INCLUDE_PATH) 
COBJFLAG = -c -Wall -D _SVID_SOURCE -I $(INCLUDE_PATH)

OBJETS = CL.o moniteur.o lecteur.o
SRC_FILES = CL.c moniteur.c lecteur.c

cl : CL.o moniteur.o lecteur.o
	$(CC) $(CFLAG) $(OBJETS) -o CL
# 	$(CC) $(CFLAG) $(SRC_FILES) -o CL

CL.o : CL.c
	$(CC) $(COBJFLAG) CL.c -o CL.o

moniteur.o : moniteur.c
	$(CC) $(COBJFLAG) moniteur.c -o moniteur.o

lecteur.o : lecteur.c
	$(CC) $(COBJFLAG) lecteur.c -o lecteur.o

clean:
	@rm -f *~ *.o cl_zz CL 