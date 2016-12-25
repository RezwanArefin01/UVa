#include<cstdio>
using namespace std;
#define GOOD(a,b,c) (a<21 && b<21 && c<21)
const char *ans[2] = {"bad","good"};
int a,b,c,co=0,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: %s\n",++co,ans[GOOD(a,b,c)]);
    }
    return 0;
}
