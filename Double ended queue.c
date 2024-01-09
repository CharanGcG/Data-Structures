#include<stdio.h>
#define size 5

void enqueue_front(int q[],int *rear,int *front,int value)
{
    if((*front==0 && *rear==size-1) || (*front==*rear+1))
    {
        printf("\nQueue is full, cannot enqueue item\n");
    }
    else if(*front==-1 && *rear==-1)
    {
        *front=0;
        *rear=0;
        q[*front]=value;
        printf("\nItem enqueued at front index: %d\n",value);
    }
    else if(*front==0)
    {
        *front=size-1;
        q[*front]=value;
        printf("\nItem enqueued at front index: %d\n",value);
    }
    else
    {
        (*front)--;
        q[*front]=value;
        printf("\nItem enqueued at front index: %d\n",value);
    }
}

void enqueue_rear(int q[],int *rear,int *front,int value)
{
    if((*front==0 && *rear==size-1) || (*front==*rear+1))
    {
        printf("\nQueue is full, cannot enqueue item\n");
    }
    else if(*front==-1 && *rear==-1)
    {
        *front=0;
        *rear=0;
        q[*rear]=value;
        printf("\nItem enqueued at rear index: %d\n",value);
    }
    else if(*rear==size-1)
    {
        *rear=0;
        q[*rear]=value;
        printf("\nItem enqueued at rear index: %d\n",value);
    }
    else
    {
        (*rear)++;
        q[*rear]=value;
        printf("\nItem enqueued at rear index: %d\n",value);
    }
}


void display(int q[],int *rear,int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        int i=*front;
        printf("\nQueue items: ");
        while(i!=*rear)
        {
            printf("\t%d",q[i]);
            i=(i+1)%size;
        }
        printf("\t%d\n",q[i]);
    }

}

void get_front(int q[],int *rear,int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront item: %d\n",q[*front]);
    }
}

void get_rear(int q[],int *rear,int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nRear item: %d\n",q[*rear]);
    }
}

void dequeue_front(int q[],int *rear,int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty, cannot dequeue item\n");
    }
    else if(*front==*rear)
    {
        printf("\nDequeued item: %d\n",q[*front]);
        *front=-1;
        *rear=-1;

    }
    else if(*front==size-1)
    {
        printf("\nDequeued item: %d\n",q[*front]);
        *front=0;
    }
    else
    {
        printf("\nDequeued item: %d\n",q[*front]);
        (*front)++;
    }
}

void dequeue_rear(int q[],int *rear,int *front)
{
    if(*front==-1 && *rear==-1)
    {
        printf("\nQueue is empty, cannot dequeue item\n");
    }
    else if(*front==*rear)
    {
        printf("\nDequeued item: %d\n",q[*rear]);
        *front=-1;
        *rear=-1;
    }
    else if(*rear==0)
    {
        printf("\nDequeued item: %d\n",q[*rear]);
        *rear=size-1;
    }
    else
    {
        printf("\nDequeued item: %d\n",q[*rear]);
        (*rear)--;
    }
}

int main()
{
    int q[size],rear=-1,front=-1,value;
    char choice,choice2;
    while(1)
    {
        printf("\nEnqueue: 1\nDequeue: 2\nDisplay: 3\nExit: 4\n\nEnter choice: ");
        scanf(" %c",&choice);

        switch(choice)
        {
        case '1':
            printf("\nEnqueue at front: 1\nEnqueue at rear: 2\n\nEnter enqueue end: ");
            scanf(" %c",&choice2);
            if(choice2=='1')
            {
                printf("Enter item to be enqueued: ");
                scanf("%d",&value);
                enqueue_front(q,&rear,&front,value);
            }
            else if(choice2=='2')
            {
                printf("Enter item to be enqueued: ");
                scanf("%d",&value);
                enqueue_rear(q,&rear,&front,value);

            }
            else
            {
                printf("\nEnter 1 or 2 only\n");
            }
            break;

        case '2':
            printf("\nDequeue at front: 1\nDequeue at rear: 2\n\nEnter Dequeue end: ");
            scanf(" %c",&choice2);
            if(choice2=='1')
            {
                dequeue_front(q,&rear,&front);
            }
            else if(choice2=='2')
            {
                dequeue_rear(q,&rear,&front);
            }
            else
            {
                printf("\nEnter 1 or 2 only\n");
            }
            break;

        case '3':
            printf("\nDisplay all items: 1\nDisplay rear item: 2\nDisplay front item: 3\nEnter your choice: ");
            scanf(" %c",&choice2);
            if(choice2=='1')
            {
                display(q,&rear,&front);
            }
            else if(choice2=='2')
            {
                get_rear(q,&rear,&front);
            }
            else if(choice2=='3')
            {
                get_front(q,&rear,&front);
            }
            else
            {
                printf("\nEnter 1,2 or 3 only\n");
            }
            break;

        case '4':
            printf("\n\nDouble ended queue implementation stopped successfully!\n\n");
            return 0;

        default:
            printf("\nPlease enter choice from menu only\n");
            break;

        }

    }
    return 0;
}


