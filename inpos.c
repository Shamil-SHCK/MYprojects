#include<stdio.h>
#include<string.h>
#define max 20
void push (char s);
char pop ();
int prc(char s);
int top=-1;
char stack[max];
char out[max];
int main ()
{
    char in[max];
    int l;
    printf("Enter a infix expression: ");
    scanf("%s",in);
    l= strlen(in);
    int t=0;
    for(int i =0;i<l;i++)
    {
        char s=in[i];
        if(s=='+'||s=='-'||s=='*'||s=='/'||s=='^')
        {
            char op=s;
            if((prc(stack[top]))>=(prc(op)))
            {
                out[t++]=pop();
                push(op);
            }
            else{
                push(op);
            }
        }
        else if(s=='(')
        {
            push(s);
        }
        else if(s==')')
        {
            while(stack[top]!='(')
            {
                out[t++]=pop();
            }
            pop();
        }
        else
        {
            out[t++]=s;
        }
    }
    while(top>-1)
    {
        out[t++]=pop();
    }
    out[t]='\0';
    printf("postfix expression :%s",out);
}
void push(char s)
{
    if(top==max-1)
    {
        printf("stack overflow ");
    }
    else
    {
        stack[++top]=s;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("stack under flow");

    }
    else{
        return(stack[top--]);
    }
}
int prc(char s)
{
    switch(s)
    {
        case '^':
        return 3;
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}