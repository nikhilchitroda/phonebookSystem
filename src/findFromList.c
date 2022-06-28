#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"./../inc/findFromList.h"
#include"./../inc/config.h"

extern struct node *head, *tail;

int findNumber()
{
	int rc=0;
	bool myBool = FALSE;
	char tName[NAME_SIZE], *qStr="Q";
	struct node *tmp=NULL;
	do
	{
		printf("whom do you want to search: ");
		while(1)
		{
			scanf(" %[^\n]s", tName);
			if(strcmp(tName,qStr)==0)
			{
				printf("\n");
				break;
			}
			else
			{
				tmp=head;
				while(tmp!=NULL)
				{
					if(strncmp(tmp->name, tName,strlen(tName)) == 0)
					{
						myBool = TRUE;
						printf("Successfully, Found value!\n");
						printf("Name: %s, with number: %s\n\n",tmp->name,tmp->number);
						return rc;
					}
					tmp=tmp->ptr;
				}
				if(myBool == FALSE)
				{
					printf("Not able to found, Please add valid name['Q' for back menu]: ");
				}
			}
		}	
	}while(FALSE);
	return rc;
}
