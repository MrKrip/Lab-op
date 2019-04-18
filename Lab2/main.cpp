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

void podschet(int argc,char* argv[])
{
	stack fun;
	stack q;
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
				pushst(q,s[i]);
			}
		}
	}
	
}

int main(int argc,char* argv[])
{	
    system("pause");
}