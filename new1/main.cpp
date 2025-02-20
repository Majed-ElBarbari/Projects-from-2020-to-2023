#include <fstream>
using namespace std;
int main()
{
    ofstream F("filename.txt");
    int x=9;
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
                                    F<<"012"<<l7<<l6<<l5<<l4<<l3<<l2<<l1<<l0<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    F.close();
    return 0;
}
