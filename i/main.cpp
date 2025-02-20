#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream f("f.txt");
    int a=1;
    char c = getchar();
    while (a != 0)
    {
        for (int i = 1; i != 168;i++)
        {
            for (int j = 0; j != i; j++)
            {
                //cout << c;
                f << c;
            }
            //cout << "\n";
            f << "\n";
        }
        for (int i = 166; i != 0;i--)
        {
            for (int j = 0; j != i; j++)
            {
                //cout << c;
                f << c;
            }
            //cout << "\n";
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
