#include <iostream>

using namespace std;

int phone()
{
    int x = 10;
    for(int l7=0;l7!=x;l7++)
    {
        for(int l6=0;l6!=x;l6++)
        {
            for(int l5=0;l5!=x;l5++)
            {
                for(int l4=0;l4!=x;l4++)
                {
                    for(int l3=0;l3!=x;l3++)
                    {
                        for(int l2=0;l2!=x;l2++)
                        {
                            for(int l1=0;l1!=x;l1++)
                            {
                                for(int l0=0;l0!=x;l0++)
                                {
                                    cout << "012" << l7 << l6 << l5 << l4 << l3 << l2 << l1 << l0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

Item* item(){;}

int shape(){
int a=1;
{
    getchar();
    ofstream f("f.txt");
    int a=1;
    char c = 'o';
    while (a != 0)
    {
        for (int i = 1; i != 168;i++)
        {
            for (int j = 0; j != i; j++)
            {
                f << c;
            }
            f << "\n";
        }
        for (int i = 166; i != 0;i--)
        {
            for (int j = 0; j != i; j++)
            {
                f << c;
            }
            f << "\n";
        }
        a=0;
    }
    f.close();
    ifstream r("f.txt");
    string m;
    while (getline(r,m))
    {
        cout << m << endl;
    }
    r.close();
    return 0;
}

int main()
{
    while(1==1)
    {
    int q;
    scanf("%i", &q);
    switch(q)
    {
    case 1:
        phone();
        break;
    case 2:
        shape();
        break;
    default:
        break;}
    }
}
