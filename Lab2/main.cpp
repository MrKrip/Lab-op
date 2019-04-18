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

void pushst(stack &s, int value)
{
	elem *temp = new elem;
	temp->data = value;
	temp->next = s.top;
	s.top = temp;
}

void popst(stack &s, int &out)
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

int main(int argc,char* argv[])
{
    for(int  i = 0; i < argc; i++)
    {
        cout<<argv[i]<<endl;
        cout<<i<<endl;
    }
    system("pause");
}