#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"./../inc/printList.h"
#include"./../inc/createList.h"
#include"./../inc/config.h"

extern struct node *head, *tail;

int addNode(char *tName, char *tNumber)
{
        int rc=0;
        struct node *tmp=NULL;

        do
        {
                tmp=(struct node*)malloc(sizeof(struct node));
                if(tmp == NULL)
                {
                        printf(" Failed to allocated Memory\n");
                        rc=1;
                        break;
                }
                snprintf(tmp->name, sizeof(tmp->name), "%s", tName);
                snprintf(tmp->number, sizeof(tmp->number), "%s", tNumber);
                tmp->ptr=NULL;

                if(head==NULL)
                {
                        head=tail=tmp;
                }
                else
                {
                        tail->ptr=tmp;
                        tail=tmp;
                }
        }while(FALSE);
        return rc;
}

int readAndCreateList(struct node *hPtr)
{
	int rc=0, row=0, column=0;
	char buffer[BUFFER_SIZE]={0}, *tempName=NULL, *tempNumber=NULL;

	do
	{
		//open file in read mode
		FILE *fp = fopen(CSV_FILE, READ_MODE);
		if(fp == NULL)
		{
			printf("Error, Not able to open file\n");
			rc=1;
			break;
		}
		else
		{
			printf("File contains are: \n");
			while (fgets(buffer, BUFFER_SIZE, fp))
			{
				//update the row & column values
				column = 0;
				row = row + 1;

				//ignore the first row, Ex: name, number etc.
				if(row == 1)
				{
					continue;
				}

				//split a string into a series of tokens
				char *value = strtok(buffer, ",");
				while(value!=NULL)
				{
					if (column == 0)
					{
						tempName=value;
					}
					if (column == 1)
					{
						tempNumber=value;
					}
					value = strtok(NULL, ",");
					column++;
				}
				printf("name: %s, and number: %s", tempName, tempNumber);

				//add values into the list
				rc = addNode(tempName, tempNumber);
				if(rc!=0)
				{
					printf("Error, while adding linked list node\n");
					break;
				}
			}
		}
		printf("\n");
		//print the list contains
		rc = printAllContact();
		if(rc!=0)
		{
			printf("Error, while adding linked list node\n");
			break;
		}
		fclose(fp);
	}while(FALSE);
	return rc;
}

int writeIntoFile(char *tName, char *tNumber)
{
	int rc=0;
	do
	{
		//open file in read mode
                FILE *fp = fopen(CSV_FILE, APPEND_MODE);
                if (fp == NULL)
                {
                        printf("Error, Not able to open file\n");
                        rc=1;
                        break;
                }
                else
                {
			fseek(fp,0,SEEK_END);
			fprintf(fp, "%s,%s\n", tName, tNumber);
		}
		fclose(fp);
	}while(FALSE);
	return rc;
}

int addContact()
{
	int rc=0;
	char localName[NAME_SIZE], localNo[NUMBER_SIZE];
	do
	{
		printf("Enter your name: ");
		scanf(" %[^\n]s", localName);
		printf("Please, enter your mobile no: ");
		scanf("%s", localNo);
		
		rc = addNode(localName, localNo);
		if(rc!=0)
		{
			printf("Error, while adding linked list node\n");
			break;
		}

		rc = writeIntoFile(localName, localNo);
		if(rc!=0)
		{
			printf("Error, while writting into file\n");
			break;
		}
		printf("Successfully, added details in the Linked list & file\n\n");
	}
	while(FALSE);
	return rc;
}

int updateFileContain()
{
	int rc=0;
	struct node *tmp=NULL;
        do
        {
		//open file in read mode
                FILE *fp = fopen(CSV_FILE, WRITE_MODE);
                if (fp == NULL)
                {
                        printf("Error, Not able to open file\n");
                        rc=1;
                        break;
                }
                else
                {
			tmp=head;
			fseek(fp, 0, SEEK_SET);
			fprintf(fp, "%s,%s\n", "name", "number");
			while(tmp!=NULL)
			{
				fprintf(fp, "%s,%s\n", tmp->name, tmp->number);
				tmp=tmp->ptr;
			}
			printf("Sucessfully, updated the CSV file\n\n");
                }
                fclose(fp);
        }while(FALSE);
        return rc;
}
