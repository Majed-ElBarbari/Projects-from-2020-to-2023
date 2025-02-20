#include <iostream>
#include <chrono>
using namespace std;
int main()
{
    cout << "Let us know how fast you are in typing! Enter text(We recommend using the same case):";
    string i;
    getline(cin,i);
    while(1)
    {
        auto t0 = chrono::high_resolution_clock::now();
        decltype(i) o;
        cout << i << "\r";
        getline(cin,o);
        auto t1 = chrono::high_resolution_clock::now();
        auto t=chrono::duration_cast<chrono::seconds>(t1-t0).count();
        auto ps=o.size()/t;
        if(o==i)
        {
            cout<<"\aYou got it in "<<t<<" seconds! This means your speed is "<<ps<<" chars per second!"<<endl;
        }
        else
        {
            cout<<"\aYou failed! You typed "<<o<<" instead of "<<i<<" in "<<
            t<<" seconds. Meaning your speed was "<<ps<<" chars per second!"<<endl;
        }
    }
}
