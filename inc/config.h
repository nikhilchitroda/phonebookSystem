
#define NAME_SIZE 30
#define NUMBER_SIZE 11
#define TRUE  1
#define FALSE 0

struct node
{
        char name[NAME_SIZE];
        char number[NUMBER_SIZE];
        struct node *ptr;
};
