#include <iostream>

using namespace std;

struct elem
{
	int data;
	elem *next;
};

struct queue
{
	elem *back;
	queue(void) :back(NULL){}
};

void pushq(queue &q, int value)
{
	elem *temp = new elem;

	temp->data = value;
    temp->next = NULL;

	if (!q.back)
	{
		q.back = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = q.back;
		q.back = temp;
	}

}

void popq(queue &q, int &out)
{
	if (!q.back)
	{
		return;
	}
	if (!q.back->next)
	{
		out = q.back->data;
		delete q.back;
        q.back = NULL;
	}
	elem *del = q.back;
	out = q.back->data;
	q.back = q.back->next;
	delete del;
}

void print(queue &q,int n)
{
	elem *cursor = q.back;
	for(int i=0;i<n;i++)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

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