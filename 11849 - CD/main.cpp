#include<bits/stdc++.h>
#define M 1000000
using namespace std;
int jack[M],jill;

int main()
{
    int i,j,k,m,n,l;
    while(scanf("%d%d",&n,&m)&&(m||n))
    {
        k=l=0;
        for(i=0;i<n;i++)
            scanf("%d",&jack[i]);
        sort(jack,jack+n);

        for(i=0;i<m;i++)
        {
            scanf("%d",&jill);
            if(binary_search(jack, jack + n, jill))
                k++;
        }
        printf("%d\n",k);
    }
    return 0;
}
