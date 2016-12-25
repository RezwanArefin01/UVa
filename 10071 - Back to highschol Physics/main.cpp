#include <cstdio>
using namespace std;
int main()
{    freopen("in.txt","r",stdin);
    int v,t;
    while(scanf("%d %d",&v,&t)==2)
    {
        int ans = v*(t*2);
        printf("%d\n",ans);
    }
    return 0;
}
