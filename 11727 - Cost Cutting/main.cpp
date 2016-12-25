#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,a,b,c,co=0;

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        vector <int> s;
        s.push_back(a);
        s.push_back(b);
        s.push_back(c);
        sort(s.begin(),s.end());
        printf("Case %d: %d\n",++co,s[1]);
    }

    return 0;
}
