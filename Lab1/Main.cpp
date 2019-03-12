#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void newsp()
{
    ofstream fout;
    int n;
    string s;
    fout.open("eurovision.csv");
    cout<<"Vvedite strani : "<<endl;
    fout<<n<<endl;
    cin.ignore();
    for(int i=0;i<20;i++)
    {   
        getline(cin,s); 
        fout<<s<<endl;
    }

    fout.close();
}

void vibor()
{   
    int a;
    do
    {
    cout<<"Вы хотите испльзовать уже имеющийся список(1) или написать новый(2) (напишите цифру как ваш выбор) : ";
    cin>>a;
    }while((a==1)&&(a==2));
    if(a==1)
    {
        
    }
    if(a==2)
    {
        newsp();
    }
}




int main()
{   
    setlocale(LC_ALL,"ru");


    return 0;
}