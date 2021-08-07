#include<iostream>
#include<windows.h>
using namespace std;

 int main()
 {
   int h1,m1,s1,h2,m2,s2,err,a;
   err=a=0;

   while(err==0)
   {
    cout<<"Enter Hour :"<<endl;
    cin>>h1;
    cout<<"Enter Minute :"<<endl;
    cin>>m1;
    cout<<"Enter Second :"<<endl;
    cin>>s1;
    if(h1<24 && m1<60 && s1<60)
    err++;
    else
    system("cls");
    }


    while(h1 || s1 || m1)
    {
        system("cls");
        cout<<h1<<":"<<m1<<":"<<s1<<endl;
        Sleep(930);
        s1--;

        if(s1<1)
        {
            if(m1!=0)
            {
                s1=59;
                m1--;
            }

            else
                s1=0;

        }
        if(m1<1)
        {

            if(h1!=0)
            {
                m1=59;
                h1--;
            }
            else
                m1=0;

        }
       // if(h2>24)
        //{
        //    h2=0;
        //}
    }
     system("cls");
    cout<<h1<<":"<<m1<<":"<<s1<<endl;


return 0;


 }

