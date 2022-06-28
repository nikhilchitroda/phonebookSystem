#include<stdio.h>
#include<string.h>
#include"./../inc/sortList.h"
#include"./../inc/createList.h"
#include"./../inc/config.h"

int sortAllContacts()
{
	int rc=0, chFlag=0;
	struct node *currNode=NULL, *nextNode=NULL;
	char tName[NAME_SIZE], tNumber[NUMBER_SIZE];
	do
	{
		currNode=head;
		while(currNode!=NULL)
		{
			nextNode=currNode->ptr;
			while(nextNode!=NULL)
			{
				if( strcmp(currNode->name, nextNode->name) >0 )
				{
					chFlag=1;

					snprintf(tName, NAME_SIZE, "%s", currNode->name);
					snprintf(tNumber, NUMBER_SIZE, "%s", currNode->number);
				
					snprintf(currNode->name, NAME_SIZE, "%s", nextNode->name);
					snprintf(currNode->number, NUMBER_SIZE, "%s", nextNode->number);
				
					snprintf(nextNode->name, NAME_SIZE, "%s", tName);
					snprintf(nextNode->number, NUMBER_SIZE, "%s", tNumber);
				}
				nextNode=nextNode->ptr;	
			}
			currNode=currNode->ptr;
		}
		if(chFlag==1)
		{
			rc = updateFileContain();
			if(rc!=0)
			{
				printf("Error, while updating file contains\n");
			}
		}
		else
		{
			printf("List contains are in sorted order!\n\n");
		}
	}while(FALSE);
	return rc;
}
