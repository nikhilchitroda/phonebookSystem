#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include"./../inc/deleteList.h"
#include"./../inc/createList.h"
#include"./../inc/config.h"

int deleteContact()
{
	int rc=0;
        bool myBool = FALSE;
        char tName[NAME_SIZE], *qStr="Q";
        struct node *tmp=NULL, *prev=NULL;
	do
        {
                printf("whom do you want to delete: ");
                while(1)
                {
                        scanf(" %[^\n]s", tName);
                        if(strcmp(tName,qStr)==0)
                        {
                                printf("\n");
                                return rc;
                        }
                        else
                        {
                                tmp=prev=head;
                                while(tmp!=NULL)
                                {
                                        if(strncmp(tmp->name, tName,strlen(tName)) == 0)
                                        {
                                                myBool = TRUE;
						prev->ptr=tmp->ptr;
						free(tmp);
						printf("Deleted the contact and \n");
							
						rc = updateFileContain();
                                                if(rc!=0)
                                                {
                                                        printf("Error, while updating file contains\n");
                                                }
						return rc;
                                        }
					prev=tmp;
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
