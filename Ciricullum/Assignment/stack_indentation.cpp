
#include<iostream>
#define MAX 200
using namespace std;

struct stack
{
	int a[MAX];
	int top;
};

void push(int x, struct stack *s)
{
	if(s->top==MAX-1)
	{
		return;
	}
	s->top=s->top+1;
	s->a[s->top]=x;
}
int pop(struct stack *s)
{
	if(s->top<0)
	{
		return -1;
	}
	int t=s->a[s->top];
	s->top=s->top-1;
	return t;
}

int top(struct stack *s)
{
	return s->a[s->top];
}
int isEmpty(struct stack *s)
{
	return s->top==-1;
}
void display(struct stack *s)
{
	while(s->top!=-1)
	{
		int t=pop(s);
		cout<<t<<" ";
	}
}

int main()
{
	struct stack s;
	s.top=-1;

	FILE *fptr;
	fptr=fopen("file.txt", "r");
	char str[200];
	char c;
	c=fgetc(fptr);
	int spaces=0;
	int lineNum=1;

	while(c!=EOF)
	{
		if(c==' ')
		{
			spaces++;
			c=fgetc(fptr);
		}
		else
		{
			if(isEmpty(&s) || top(&s)<=spaces)
			{
				push(spaces, &s);
			}
			else
			{
				while(!isEmpty(&s) && top(&s)>spaces)
				{
					pop(&s);
				}
				if(isEmpty(&s) || top(&s)<spaces)
				{
					cout<<"Error on line number: "<<lineNum<<"\n";
					return 0;
				}
				if(top(&s)==spaces)
				{
					pop(&s);
				}
			}
			spaces=0;
			fgets(str, 200, fptr);
			lineNum++;
			c=fgetc(fptr);
		}
	}
    cout<<"File is correctly indented"<<"\n";
	fclose(fptr);
	return 0;
}