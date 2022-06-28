#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"./../inc/editList.h"
#include"./../inc/createList.h"
#include"./../inc/config.h"

extern struct node *head, *tail;

int editNumber()
{
	int rc=0;
        bool myBool = FALSE;
        char tName[NAME_SIZE], *qStr="Q";
        struct node *tmp=NULL;
	do
	{
                printf("Enter name which contact number you want to change: ");
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
                                        if(strncmp(tmp->name, tName, strlen(tName)) == 0)
					{
						printf("Enter mobile no which you want to change: ");
						scanf("%s", tmp->number);

						rc = updateFileContain();
                                                if(rc!=0)
                                                {
                                                        printf("Error, while updating file contains\n");
                                                }
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
