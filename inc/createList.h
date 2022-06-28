#include<stdio.h>

#define READ_MODE 	"r"
#define WRITE_MODE 	"w"
#define APPEND_MODE 	"a+"
#define BUFFER_SIZE 	1024
#define CSV_FILE 	"/home/chitroda/Desktop/tempPB/wrk_26june_pbDirecProj/phoneBookProj/myContact.csv"

extern struct node *head, *tail;

int addNode(char *tName, char *tNumber);
int readAndCreateList(struct node *hPtr);
int writeIntoFile(char *tName, char *tNumber);
int addContact();
int updateFileContain();
