#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void p1(int* m,int a=1)
{
    if(a%3==0||a%5==0)*m+=a;
    if(a!=1000)p1(m,a+1);
}
void p2(int* m)
{
    *m=0;
    int a=1,b=2;
    while(a<=4000000)
    {
        if(a%2==0)*m+=a;
        int t=a;
        a=b;
        b+=t;
    }
}
int  p3(int* m)
{
    *m=0;
    long long a=600851475143;
    short b=2;
    for(; a!=0;)
    {
        if(a%b!=0)
        {
            b++;
        }
        else
        {
            *m=a;
            a/=b;
            if(a==1)return 0;
        }
    }
}
int  p4(int* m)
{
    *m=0;
    for(int i=999; i!=99; i--)
    {
        for(int j=999; j!=99; j--)
        {
            *m=j*i;
            long long a=log10(*m);
            int b=0;
            if(a==5)
            {
                for(int i=0; i<=a; i++)b+=(floor(*m/pow(10,i))-floor(*m/pow(10,i+1))*10)*pow(10,a-i);
                if(b==*m&&floor(*m/pow(10,a))==9)return 0;
            }
        }
    }
}
int  p5(int *m)
{
    *m=2;
    while(1==1)
    {
        if(*m%11==0&&*m%13==0&&*m%7==0&&*m%16==0&&*m%17==0&&*m%18==0&&*m%19==0&&*m%20==0)break;
        else
        {
            *m+=2;
        }
    }
}
void p6(int* m)
{
    *m=0;
    int a=0;
    int b=0;
    for(int i=0; i!=101; i++)a+=i*i;
    for(int i=0; i!=101; i++)b+=i;
    b*=b;
    *m=b-a;
}
void p7(int* m)
{
    *m=0;
    long a[10001];
    a[0]=2;
    long b=1;
    for(long i=3; b!=10001; i++)
    {
        for(long j=0; j!=b; j++)
        {
            if(i%a[j]!=0)
            {
                if(j==b-1)
                {
                    a[b]=i;
                    b++;
                }
            }
            else
            {
                break;
            }
        }
    }
    *m=a[10000];
    delete(a);
}
void p10(){}
int main()
{
    int s;
    p1(&s);
    cout<<s<<endl;
    p2(&s);
    cout<<s<<endl;
    p3(&s);
    cout<<s<<endl;
    p4(&s);
    cout<<s<<endl;
    p5(&s);
    cout<<s<<endl;
    p6(&s);
    cout<<s<<endl;
    p7(&s);
    cout<<s<<endl;
    //p10(&s);
    //2,000,000 is too big for one list perhaps make 10 lists or something?
    s=2;
    long a[199999];
    a[0]=2;
    long b=1;
    for(long i=3; i<=199999; i++)
    {
        for(long j=0; j!=b; j++)
        {
            if(i%a[j]!=0&&i%2==1)
            {
                if(j==b-1)
                {
                    s+=i;
                    a[b]=i;
                    b++;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout<<s<<" "<<a[b-1];
    return 0;
}
