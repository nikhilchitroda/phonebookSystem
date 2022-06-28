#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"./../inc/createList.h"
#include"./../inc/editList.h"
#include"./../inc/findFromList.h"
#include"./../inc/deleteList.h"
#include"./../inc/printList.h"
#include"./../inc/sortList.h"
#include"./../inc/config.h"

struct node *head=NULL, *tail=NULL;

int menu()
{
	int rc=0, choice=0;
	do
	{
		printf("1. Add Contact\n");
		printf("2. Edit Number\n");
		printf("3. Find Number\n");
		printf("4. Delete Contact\n");
		printf("5. Print All Contacts\n");
		printf("6. Sort all Contacts\n");
		printf("7. Exit\n\n");
		printf("Enter your choice[1-7]: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				rc = addContact();
				if(rc!=0)
				{
					printf("Error, while adding Contact into the file\n");
				}
				break;
			case 2:
				rc = editNumber();
				if(rc!=0)
                                {
                                        printf("Error, while editing number\n");
                                }
				break;
			case 3:
				rc = findNumber();
				if(rc!=0)
                                {
                                        printf("Error, while finding number\n");
                                }
				break;
			case 4:
				rc = deleteContact();
				if(rc!=0)
                                {
                                        printf("Error, while deleting contact\n");
                                }
				break;
			case 5:
				rc = printAllContact();
				if(rc!=0)
				{
					printf("Error, while printing all contact numbers\n");
				}
				break;
			case 6:
				rc = sortAllContacts();
                                if(rc!=0)
                                {
                                        printf("Error, while sortint all contacts numbers\n");
                                }
                                break;
			case 7:
				exit(1);
			default:
				printf("Please, Enter valid choice between [1 to 7]\n");
		}
	}while(FALSE);
	return rc;
}

int main()
{
        int rc=0;
        do
        {
                printf("\n***** Welcome to Phonebook Directory *****\n");
                rc = readAndCreateList(head);
                if(rc != 0)
                {
                        printf("Error, while reading And Creating Linked List\n");
                        break;
                }
                while(1)
                {
                        rc = menu();
                        if(rc != 0)
                        {
                                printf("Error, while printing menu function\n");
                                break;
                        }
                }
        }while(FALSE);
        return rc;
}
