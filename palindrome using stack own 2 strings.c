#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>

#define size 20

void push(char stack[],int *top,char value);
char pop(char stack[],int *top);
int isPalindrome(char input[]);

int main()
{
    char input[size],stack[size];
    printf("Enter the string: ");
    scanf("%s",input);
    if(isPalindrome(input)==0)
    {
        printf("The string is a palindrome");
    }
    else
    {
        printf("The string is not a palindrome");
    }
    return 0;
}

void push(char stack[],int *top,char value)
{
    if(*top==size-1)
    {
        printf("Stack overflow, cannot push item");
    }
    else
    {
        (*top)++;
        stack[*top]=value;
    }
}

char pop(char stack[],int *top)
{
    if(*top==-1)
    {
        printf("Stack underflow, cannot pop item");
        return '\0';
    }
    else
    {
        return stack[(*top)--];
    }
}

int isPalindrome(char input[])
{
    char stack[size];
    int top=-1;
    for(int i=0;i<strlen(input);i++)
    {
        push(stack,&top,tolower(input[i]));
    }

    for(int i=0;i<strlen(input);i++)
    {
        if(tolower(pop(stack,&top))!=tolower(input[i]))
        {
            return -1;
        }
    }
    return 0;
}
