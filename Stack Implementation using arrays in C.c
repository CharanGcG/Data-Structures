//STACK IMPLEMENTATION USING ARRAYS IN C

#include<stdio.h>
#include<stdlib.h>


void push(int stack[],int *top,int value,int stack_size); // function prototype
void display(int stack[],int *top); // function prototype
int pop(int stack[],int *top); // function prototype
void switching(int stack[],int *top,int stack_size); // function prototype

int main()
{
    int stack_size;
    printf("Enter the size of the stack: ");
    scanf("%d", &stack_size);

    int *stack = (int *)malloc(stack_size * sizeof(int));  // dynamic memory allocation of the stack based on user input
    if (stack == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");  // error message if the memory allocation was not successful
        return 1;
    }
    int top=-1;


    while(1)  //infinite loop, terminates on encountering exit or return statement
    {

        switching(stack,&top,stack_size);

    }
    free(stack);  //to free the dynamically allocated memory to prevent memory leaks
    return 0;  //end of main function
}

void push(int stack[],int *top,int value,int stack_size)   // push function definition
{
    if(*top==stack_size-1)
    {
        printf("Stack overflow, cannot push item");  //checks stack overflow condition
    }
    else
    {
        (*top)++;
        stack[*top]=value;   //increment the top index value and store the value passed in that top index
        printf("%d pushed to stack successfully",value);
    }
}

void display(int stack[],int *top)  //display function definition
{
    printf("\nThe stack in current position: ");
    if(*top==-1)
    {
        printf("\nStack is empty\n");  // empty stack message
    }
    else
    {
        for(int i=*top; i>=0; i--)
        {
            printf("\n%d",stack[i]);   //prints all the stack items
        }
    }
}

int pop(int stack[],int *top)  //pop function definition
{

    if(*top==-1)
    {
        printf("Stack underflow. Cannot pop items from an empty stack.\n");  //checks stack underflow condition
        return -1;
    }
    else
    {
        int pop_value=stack[*top];
        (*top)--;
        printf("The item popped successfully : %d",pop_value);  // pops the top item and prints it
        return 0;
    }

}



void switching(int stack[],int *top,int stack_size)  //switch case function definition
{
    int choice;
    printf("\n\n1: Push\n2: Pop\n3: Display Stack items\n4: Exit\n\nEnter choice: ");  //menu display
    scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        printf("\nEnter the item to be pushed: ");
        int value;
        scanf("%d",&value);
        push(stack,top,value,stack_size);  // function call
        break;

    case 2:
        pop(stack,top);  // function call
        break;

    case 3:
        display(stack,top);  // function call
        break;

    case 4:
        printf("Stack implementation stopped");// function call
        exit(0);

    default:
        printf("Please enter choice from the menu only\n");
    }
}
