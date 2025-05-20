#include<stdio.h>
#include<conio.h>
#include<conio.h>


#define MAX 100
int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char const *argv[])
{
    int val,option;
    do
    {
        printf("\nStack Operations\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter the option: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                val = pop(st);
                printf("Popped value is %d\n",val);
                break;
            case 3:
                val = peek(st);
                printf("Top element is %d\n",val);
                break;
            case 4:
                display(st);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option!=5);
    return 0;
}

void push(int st[], int val)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        st[top] = val;
    }
}
int pop(int st[])
{
    int val;
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}
void display(int st[])
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",st[i]);
    }
    printf("\n");
}
int peek(int st[])
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return st[top];
    }
}