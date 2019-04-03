#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void nwfiles(string s)
{
    ofstream fout;
    string a;
    int n;
    a=s+".txt";
    n=stoi(s);
    fout.open(a);
    string units    [] = {"один","два","три","четыре","пять","шесть", "семь","восемь","девять"}; 
    string tens     [] = {"десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят", "восемьдесят","девяносто"}; 
    string hundreds [] =  {"сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"};
    string thousand [] = {"одна тысяча","две тысячи","три тысячи","четыре тысячи","пять тысяч","шесть тысяч","семь тысяч","восемь тысяч","девять тысяч","тысяч"}; 
    string secondten[] = {"одиннадцать","двенадцать","тринадцать","четырнадцать","пятнадцать","шестнадцать","семнадцать","восемнадцать","девятнадцать"};
    int arr[4];
    arr[0]=n%10;
    arr[1]=(n/10)%10;
    arr[2]=n/100;
    arr[3]=n/1000;
    a="";
    if(arr[3]>0)
    {
        if(arr[3]<10)
        {
            a=a+thousand[arr[3]-1];
        }
        if(arr[3]==10)
        {
            a=a+tens[0]+thousand[9];
        }
        if(arr[3]>10 && arr[3]<20)
        {
            a=a+secondten[arr[3]-1]+thousand[9];
        }
        if(arr[3]>19 && arr[3]<100)
        {
            if(arr[3]%10!=0)
            {
                a=a+tens[(arr[3]/10)-1]+units[(arr[3]%10)-1];
            }
            else
            {
               a=a+tens[(arr[3]/10)-1];
            }            
        }
        if(arr[3]>99 && arr[3]<1000)
        {
            if((arr[3]%10)!=0 && (arr[3]%100)!=0)
            {
                a=a+hundreds[(arr[3]/100)-1]+tens[(arr[3]%100)-1]+units[(arr[3]%10)-1];
            }
        }

    }
    fout.close();
}

void vhod()
{
    ifstream fin;
    string s;
    fin.open("Chisla.txt");
    if(!fin.is_open())
    {
        cout<<"Eror opening file";
    }
    else
    {
        while(!fin.eof())
        {
            fin>>s;
            cout<<s<<" / ";
            nwfiles(s);
        }
    }
    fin.close();    
}


int main()
{   
    vhod();
    system("pause");
    return 0;
}