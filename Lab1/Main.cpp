#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void vivod(string *s,int **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
        for(int j=0;j<(n+1);j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void vvod()
{
    ifstream fin;
    int n;
    fin.open("eurovision.csv");
    if(!fin.is_open())
    {
        cout<<"Error opening file!"<<endl;
    }
    else
    {   
        fin>>n;
        cout<<n<<endl;
        cin.ignore();
        string *s=new string[n];
        string *k=new string[n];
        int **arr=new int *[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=new int [n+1];
        } 
        for(int i=0;i<n;i++)
        {   
            getline(fin,s[i],';');
            for(int j=0;j<n;j++)
            {
                if(j<n-1)
                {   
                    getline(fin,k[j],';');
                    arr[i][j]=stoi(k[j]);
                }
                else 
                {
                    getline(fin,k[j],'\n');
                    arr[i][j]=stoi(k[j]);
                }
            }
            arr[i][n]=0; 
        }
        vivod(s,arr,n);
    }
    fin.close();
}



void newsp()
{
    ofstream fout;
    int n,a;
    fout.open("eurovision.csv");
    cout<<"Enter the number of countries : ";
    cin>>n;
    cin.ignore();
    fout<<n<<endl;
    string *s=new string[n];
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
            cin>>a;
            fout<<";"<<a;
        }
        fout<<endl;
    }
    delete []s;
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