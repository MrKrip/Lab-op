#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void vivod(string *s,int **arr,int n)
{   
    int max=0,k=0,p,temp;
    string a;
    int *schetchik=new int[10];
    int *ocenka = new int[10]{ 12,10,8,7,6,5,4,3,2,1 };
    for(int i=0;i<n;i++)
    {
        for(int m=0;m<10;m++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j][n]==0)
                {
                    if(max<arr[j][i])
                    {
                        max=arr[j][i];
                        schetchik[k]=j;
                    }
                }    
            }
            arr[schetchik[k]][n]=arr[schetchik[k]][n]+ocenka[m];
            k++;
            max=0;
        }
        k=0;    
    }
    p=n;
    while(n>1)
    {
        for(int i=0;i<(n-1);i++)
        {
            if(arr[i][n]<arr[i+1][n])
            {
                for(int j=0;j<(p+1);j++)
                {
                    temp=arr[i][j];
                    arr[i][j]=arr[i+1][j];
                    arr[i+1][j]=temp;
                    a=s[i];
                    s[i]=s[i+1];
                    s[i+1]=a;
                }
            }
        }
        n--;
    }
    ofstream fout;
    fout.open("results.csv");
    for(int i=0;i<10;i++)
    {
        fout<<s[i]<<";";
        for(int j=0;j<9;j++)
        {
            fout<<arr[i][j]<<";";
        }
        fout<<arr[i][10]<<endl;
    }
    fout.close();
    delete []ocenka;
    delete []schetchik;
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
        cout<<"Result is displayed in results.csv"<<endl;
        vivod(s,arr,n);
        delete []s;
        delete []k;
        delete []arr;     
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