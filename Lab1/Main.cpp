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




int main()
{   
    setlocale(LC_ALL,"ru");


    return 0;
}