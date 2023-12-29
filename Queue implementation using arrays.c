//LINEAR QUEUE IMPLEMENTATION USING ARRAYS
//CHARAN G

#include<stdio.h>
#include<stdlib.h>
#define qsize 5  //defining the queue size

void enqueue(int queue[], int *rear, int *front, int value);  //function prototype
int dequeue(int queue[],int *rear, int *front);
void display(int queue[],int *rear,int *front);




int main()
{
    int queue[qsize];
    int front=0,rear=-1;   //index rear keeps track of index in push function and index function keeps track of the pop function index
    int value;
    char choice;
    printf("QUEUE IMPLEMENTATION USING ARRAYS\nQUEUE SIZE: %d\n",qsize);
    while(1)   //infinite loop till the user opts to exit
    {
        printf("\n1: Push\n2: Pop\n3: Display\n4: Exit\n\nEnter your choice: ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case '1': printf("\nEnter the item to be pushed: ");   //function call to push the item on choice 1
            scanf("%d",&value);
            enqueue(queue,&rear,&front,value);
            break;

            case '2': printf("\nThe item popped is: %d\n",dequeue(queue,&rear,&front)); //function call to pop item on choice 2
            break;

            case '3': display(queue,&rear,&front);  //function call to display the items in the queue
            break;

            case '4': printf("\nQueue implementation stopped successfully!\n");  //to exit the loop and terminate the program
            return 0;

            default: printf("\nPlease enter your choice from the menu only\n");  //message when the user opts for a choice out of the menu
            break;
        }
    }
    return 0;
}



void enqueue(int queue[], int *rear, int *front,int value)
{
    if(*rear==qsize-1)
        {
            if(*front>*rear)        //if all the memory locations are used up and all the items are also popped, no more implementation is possible, so it terminates the program
            {
                printf("\nAll memory locations used, linear queue terminated\n");
                exit(0);
            }
            else
            {
                printf("\nQueue overflow, cannot push item\n");   //if front index is not greater than rear index and rear index has reached the maximum size, then its an overflow condition
            }
        }
    else
    {
        (*rear)++;
        queue[*rear]=value;   //increments the rear index and pushes the value passed from the main function if there is no overflow
        printf("\n%d pushed to queue successfully\n",queue[*rear]);
    }
}



int dequeue(int queue[],int *rear, int *front)
{
    if(*front>*rear)
    {
        printf("\nQueue underflow, cannot pop item, the -1 indicates that the pop was unsuccessful\n");  //front index greater than rear index implies there are no items present in the queue currently, hence it leads to underflow
        return -1;
    }
    else
    {
        int deleted_item=queue[*front];  //stores the item to be popped, and increments the front index to point to the next item and returns the item popped
        (*front)++;
        return deleted_item;
    }
}




void display(int queue[],int *rear,int *front)
{
    if(*front>*rear)
    {
        printf("\nQueue is empty\n");  //displays a message that queue is empty
    }
    else
    {
        printf("\nQueue in the current position:\n\n");
        for(int i=*front;i<=*rear;i++)
        {
            printf("%d\t",queue[i]);   //displays all the items of the queue in a single line with tab spaces
        }
        printf("\n\n");
    }
}
