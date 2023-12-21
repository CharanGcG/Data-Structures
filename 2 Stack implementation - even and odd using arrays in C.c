#include<stdio.h>
#include<stdlib.h>

void push(int stack[],int *top,int value,char type[],int stack_size); //function prototype
void display(int stack[],int *top,char type[],int stack_size);
void pop(int stack[],int *top,char type[],int stack_size);

int main()
{
    int stack_size;
    printf("Enter the size of both the stacks: ");
    scanf("%d",&stack_size);
    if (stack_size <= 0)
    {
        printf("Invalid stack size. Exiting.\n");
        exit(1);
    }
    int *stack_even=(int *)malloc(stack_size * sizeof(int));  //dynamic memory allocation
    int *stack_odd=(int *)malloc(stack_size * sizeof(int));
    if(stack_even==NULL || stack_odd==NULL)
    {
        printf("Memory allocation failed, Exiting.");   //check if memory allocation is successful, otherwise terminate the execution
        return 1;
    }
    int top_even=-1;
    int top_odd=-1;
    int choice,value;
    char even[]="Even";  //strings to be passed to the functions to reuse the same function for both odd and even
    char odd[]="Odd";
    while(1)
    {
        printf("\n\nPUSH: 1\nPOP: 2\nDISPLAY: 3\nEXIT: 4\n\nEnter choice from menu: ");  //display menu
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter item to be pushed: ");
            scanf("%d",&value);
            if(value%2==0)
            {
                push(stack_even,&top_even,value,even,stack_size); //function call
            }
            else
            {
                push(stack_odd,&top_odd,value,odd,stack_size); //function call
            }
            break;

        case 2:
            printf("1: POP from even stack\n2: POP from odd stack\nEnter choice: ");
            int pop_choice;
            scanf("%d",&pop_choice);
            if(pop_choice==1)
            {
                pop(stack_even,&top_even,even,stack_size); //function call
            }
            else if(pop_choice==2)
            {
                pop(stack_odd,&top_odd,odd,stack_size); //function call
            }
            else
            {
                printf("\nPlease enter choice 1 or 2 only\n");
            }
            break;

        case 3:
            printf("1: Display even stack\n2: Display odd stack\nEnter choice: ");
            int display_choice;
            scanf("%d",&display_choice);
            if(display_choice==1)
            {
                display(stack_even,&top_even,even,stack_size); //function call
            }
            else if(display_choice==2)
            {
                display(stack_odd,&top_odd,odd,stack_size); //function call
            }
            else
            {
                printf("\nPlease enter choice 1 or 2 only\n");
            }
            break;

        case 4:
            printf("\nStack implementation stopped\n\n");
            return 0;

        default:
            printf("\nEnter choice from menu only\n");
        }
    }
    free(stack_even); //to free the dynamically allocated memory to prevent memory leaks
    free(stack_odd);
    return 0;
}

void push(int stack[],int *top,int value,char type[],int stack_size)
{
    if(*top==stack_size-1)
    {
        printf("\n%s Stack overflow, cannot push item\n",type); //stack overflow message if items greater than the stack size is pushed onto the stack
    }
    else
    {
        (*top)++;
        stack[*top]=value;
        printf("\n%d pushed to %s stack successfully",value,type);  //successful push message
    }
}


void display(int stack[],int *top,char type[],int stack_size)
{
    printf("\n%s Stack in current position:\n",type);
    if(*top==-1)
    {
        printf("\n%s Stack is empty\n",type);  //empty stack message
    }
    else
    {
        for(int i=*top; i>=0; i--)
        {
            printf("%d\n",stack[i]);  //display the items from the top to bottom
        }
    }
}


void pop(int stack[],int *top,char type[],int stack_size)
{
    if(*top==-1)
    {
        printf("\nStack underflow, cannot pop item from %s stack\n",type);  //stack underflow message when you try to pop an empty stack
    }
    else
    {
        int popped=stack[*top];
        (*top)--;
        printf("\nThe item %d popped successfully from the %s stack.\n",popped,type); //successful pop message
    }
}




