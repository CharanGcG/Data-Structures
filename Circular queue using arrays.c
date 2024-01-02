#include<stdio.h>
#define size 5
void enqueue(int queue[],int *rear, int *front, int value);
void dequeue(int queue[],int *rear, int *front);
void display(int queue[],int *rear, int *front);

int main()
{
    int queue[size],rear=-1,front=-1,value;
    printf("Circular Queue implementation\n");
    char choice;
    while(1)
    {
        printf("\nInsert: 1\nDelete: 2\nDisplay: 3\nExit: 4\n");
        printf("\nEnter your choice: ");
        scanf(" %c",&choice);
        switch(choice)
        {
        case '1':
            printf("\nEnter the item to be pushed: ");
            scanf("%d",&value);
            enqueue(queue,&rear,&front,value);
            break;

        case '2':
            dequeue(queue,&rear,&front);
            break;

        case '3':
            display(queue,&rear,&front);
            break;

        case '4':
            printf("\nQueue implementation stopped successfully\n");
            return 0;

        default:
            printf("\nPlease enter choice from the menu only\n");
        }
    }
    return 0;

}



void enqueue(int queue[],int *rear, int *front, int value)
{
    if(*front==-1 && *rear==-1)
    {
        *front=0;
        *rear=0;     //to initiate the queue, we need to assign both indexed to zero and then insert the first item
        queue[*rear]=value;
        printf("\n%d inserted to queue successfully\n",queue[*rear]);
    }
    else if(((*rear)+1)%size==*front)
    {
        printf("\nQueue is full, cannot insert item\n");   //checks if front index is ahead of rear index by one location, if true: the queue has to be full
    }
    else
    {
        *rear=((*rear)+1)%size;   //if the queue is already initialized and is not full, insert the item
        queue[*rear]=value;
        printf("\n%d inserted to queue successfully\n",queue[*rear]);
    }
}



void dequeue(int queue[],int *rear, int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty, cannot delete item\n");   //if queue is not initialized or if all locations were inserted and also deleted, then the queue is empty
    }
    else if(*front==*rear)
    {
        printf("\nDeleted item : %d\n",queue[*front]);
        *front=-1;
        *rear=-1;   //front and rear indexes are equal only if they are pointing to the last item, so we have to restart the queue after deleting
    }
    else
    {
        printf("\nDeleted item: %d\n",queue[*front]);
        *front=((*front)+1)%size;  //if queue is not empty and also if they haven't reached the last item, then delete and increment front using mod operator
    }
}

void display(int queue[],int *rear, int *front)
{
    int i=*front;
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue in current position: ");  //prints all the items starting from the front index till the rear index, but does not print the item of rear index
        while(i!=*rear)
        {
            printf("%d   ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d",queue[i]);    //this statement prints the item of rear index
    }
}


