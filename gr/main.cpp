#include <iostream>
using namespace std;
void f();
void n();
void s();
void o();
int main()
{
    o();
    return 0;
}
char c=254;

void f()
{
    int o[13];int a = 0;int b = 1;int l=0;
    while (a<150){o[l]=a;l++;int t=a;a=b;b+=t;}
    for(int i=l;i!=0;i--)
    {
        cout<<endl;
        for(int j=0;j!=o[i];j++)cout<<c;
    }
    for(int i=0;i!=l;i++)
    {
        for(int j=0;j!=o[i];j++)cout<<c;
        cout<<endl;
    }
}

void n()
{
    for(int i=167;i!=0;i--)
    {
        for(int j=0;j!=i;j++)
        {
            cout<<c;
        }
    cout<<endl;
    }
    for(int i=0;i!=168;i++)
    {
        for(int j=0;j!=i;j++)
        {
            cout<<c;
        }
    cout<<endl;
    }
}
void s()
{
    for(int i=12;i!=0;i--)
    {
        for(int j=0;j!=i*i;j++)
        {
            cout<<c;
        }
    cout<<endl;
    }
    for(int i=1;i!=13;i++)
    {
        for(int j=0;j!=i*i;j++)
        {
            cout<<c;
        }
    cout<<endl;
    }
}
void o(){short x;bool y=1;while(y){cin>>x;switch(x){case 0:y=0;break;case 1:n();break;case 2:s();break;case 3:f();break;}}}
