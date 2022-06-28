#include<stdio.h>
#include"./../inc/printList.h"
#include"./../inc/config.h"

extern struct node *head, *tail;

int printAllContact()
{
        int rc=0;
        struct node *tmp=NULL;
        do
        {
                if(head == NULL)
                {
                        printf("Node list is empty, please create the list!\n");
			rc=1;
                }
                else
                {
                        tmp=head;
                        printf("\nLinked List contains are: \n");
                        while(tmp!=NULL)
                        {
                                printf("Name: %s, and its number: %s\n", tmp->name, tmp->number);
                                tmp=tmp->ptr;
                        }
                        printf("\n");
                }
        }while(FALSE);
        return rc;
}
