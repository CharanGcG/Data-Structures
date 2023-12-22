#include<stdio.h>
#include<ctype.h>

#define size 50  //defining sufficient array size

char stack[size]; //declaring global variables stack and top to store operators and parenthesis
int top=-1;

void push(char value);  //function prototypes
char pop();
int precedence(char operators);



int main()
{
    char infix[size],postfix[size],character;  //declaring two arrays, infix for user input, postfix for output, character to read every character of the infix expression
    int i=0,k=0;  //infix and postfix array indexes declared and initialized
    push('#');  //base value of the stack to prevent underflow
    printf("Enter the Infix Expression: ");
    scanf("%s",infix); //user input
    while(infix[i]!='\0')   //while condition to run till the end of the string
    {
        character=infix[i++];  //variable character assigned the infix index character
        if(character=='(')
        {
            push(character);  //an opening parenthesis is pushed onto the stack
        }
        else if(isalnum(character))
        {
            postfix[k++]=character;  //an alphanumeric character is stored in the postfix array
        }
        else if(character==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();   //all other operators popped when a closed parenthesis is encountered to get rid of parenthesis in the postfix expression
            }
            char open=pop();  //getting rid of parenthesis by storing it in another variable
        }
        else
        {
            while(precedence(character)<=precedence(stack[top]))   //checks precedence condition and pushes the operators to the stack
            {
                postfix[k++]=pop();
            }
            push(character);
        }
    }

    while(stack[top]!='#')
    {
        postfix[k++]=pop();  //pop the remaining characters from the stack onto the postfix array
    }
    postfix[k]='\0';  //terminating the string with a null character to make it valid
    printf("\n\nPostfix Expression: %s",postfix);  //printing the postfix expression
    return 0;
}

void push(char value)
{
    stack[++top]=value;    //pushes the items onto the stack
}

char pop()
{
    return stack[top--];   //pops the items and stores into the postfix array
}

int precedence(char operators)  //assigns precedence orders to check while pushing it onto the stack
{
    if(operators=='^')
        return 3;
    else if(operators=='/' || operators=='*')
        return 2;
    else if(operators=='+' || operators=='-')
        return 1;
    else
        return 0;
}
