#include<cstdio>
using namespace std;

int main()
{
    unsigned long long n,i;
    while (scanf("%lld",&n)==1)
    {
        if(n<=210000000 && n>=0)
        {
            i=(n*(n+1)/2)+1;
            printf("%lld\n",i);
        }
        else break;
    }
    return 0;
}
