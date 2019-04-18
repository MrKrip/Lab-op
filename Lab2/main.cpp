#include <iostream>

using namespace std;

struct elem
{
	int data;
	elem *next;
};

struct stack
{
	elem *top;

	stack(void) :top(NULL) {}
};

void pushst(stack &s, char value)
{
	elem *temp = new elem;
	temp->data = value;
	temp->next = s.top;
	s.top = temp;
}

void popst(stack &s, char &out)
{
	if (!s.top)
		;

	if (!s.top->next)
	{
		out = s.top->data;
		delete s.top;
		s.top = NULL;
	}
	elem *del = s.top;
	out = s.top->data;
	s.top = s.top->next;
	delete del;
}

int priority(string s)
{
	if(s=="+")
	{
		return 1;
	}
	else if(s=="-")
	{
		return 1;
	}
	else if(s=="*")
	{
		return 2;
	}
	else if(s=="/")
	{
		return 2;
	}
}

void podschet(int argc,char* argv[])
{
	stack fun;
	stack number;
	string s;
	for(int i=1;i<argc;i++)
	{
		s=argv[i];
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/')
			{
				pushst(fun,s[i]);
			}
			else
			{
				pushst(number,s[i]);
			}
		}
	}
	
}

int main(int argc,char* argv[])
{	
    system("pause");
}