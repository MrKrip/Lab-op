#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void vvod()
{
    ifstream fin;
    string *s=new string[20];
    int n,a;
    fin.open("eurovision.csv");
    if(!fin.is_open())
    {
        cout<<"Error opening file!"<<endl;
    }
    else
    {
        fin>>n;
        int **arr=new int *[n];
        for(int i=0;i<n;i++)
        {
            arr[n]=new int [n+1];
        }
        for(int i=0;i<n;i++)
        {
            getline(cin,s[i],';');
            for(int j=0;j<n;j++)
            {
                fin>>a;
                arr[i][j]=a;
            }
            arr[i][n+1]=0;
        }
    }
    fin.close();
}

void vivod()
{

}

void newsp()
{
    ofstream fout;
    int n;
    string *s=new string[20];
    fout.open("eurovision.csv");
    cout<<"Enter the number of countries : ";
    cin>>n;
    cin.ignore();
    fout<<n<<endl;
    for(int i=0;i<n;i++)
    {   
        getline(cin,s[i]);
    }
    for(int i=0;i<n;i++)
    {
        fout<<s[i];
        for(int j=0;j<n;j++)
        {
            cout<<"How many support votes "<<s[i]<<" received from "<<s[j]<<" : ";
            cin>>n;
            fout<<";"<<n;
        }
        fout<<endl;
    }
    delete []s;
    fout.close();
    vvod();
}

void vibor()
{   
    int a;
    do
    {
    cout<<"Do you want to use the existing list (1) or write a new one (2) (write the number as your choice) : ";
    cin>>a;
    }while((a==1)&&(a==2));
    if(a==1)
    {
       vvod(); 
    }
    if(a==2)
    {
        newsp();
    }
}


int main()
{   
    vibor();

    system("pause");

    return 0;
}