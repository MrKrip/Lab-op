#include <iostream>
#include <string>

using namespace std;

struct elem
{
	string data;
	elem *next;
};

struct stack
{
	elem *top;

	stack(void) :top(NULL) {}
};

void pushst(stack &s, string value)
{
	elem *temp = new elem;
	temp->data = value;
	temp->next = s.top;
	s.top = temp;
}

void popst(stack &s, string &out)
{
	if (!s.top)
		exit(1);

	if (!s.top->next)
	{
		out = s.top->data;
		delete s.top;
		s.top = NULL;
		
	}
	else
	{
	elem *del = s.top;
	out = s.top->data;
	s.top = s.top->next;
	delete del;
	}
	
}

int priority(string s)
{
	if(s=="+")
	{
		return 1;
	}
	else if(s=="-")
	{
		return 2;
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

int calculate(string fn,int num1,int num2)
{
	if(fn=="+")
	{
		return (num2+num1);
	}
	else if(fn=="-")
	{
		return (num2-num1);
	}
	else if(fn=="*")
	{
		return (num2*num1);
	}
	else if(fn=="/")
	{
		return (num2/num1);
	}
}

void podschet(stack &fun,stack &number)
{	
	string fn,num1,num2,num3;
	int n1,n2,n3;
	while(fun.top)
	{	
		popst(fun,fn);
		popst(number,num1);
		popst(number,num2);
		n1=stoi(num1);
		n2=stoi(num2);
		n3=calculate(fn,n1,n2);
		num3=to_string(n3);
		pushst(number,num3);
	}
}

void razdelenie(int argc,char* argv[])
{
	stack fun;
	stack number;
	string s;
	string a,b,c="";
	for(int i=1;i<argc;i++)
	{
		s=argv[i];
		for(int j=0;j<s.size();j++)
		{	
			b=s[j];
			if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/')
			{	
				if(fun.top)
				{
					popst(fun,a);
					pushst(fun,a);
					if(priority(a)>priority(b))
					{
						podschet(fun,number);
					}
				}
				pushst(fun,b);
			}
			else
			{
				c=c+s[j];
				if(s[j+1]=='+' || s[j+1]=='-' || s[j+1]=='*' || s[j+1]=='/' || j==(s.size()-1))
				{
					if(c!="")
					{	
						pushst(number,c);
						c="";
					}
				}
			}
		}
		c="";
	}
	podschet(fun,number);
	popst(number,a);
	cout<<"Result : "<<a<<endl;	
}

int main(int argc,char* argv[])
{	
	razdelenie(argc,argv);
    system("pause");
}