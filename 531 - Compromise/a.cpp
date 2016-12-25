#include<bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(ara,n) memset(ara,n,sizeof ara)
#define loop(i,j,n) for(i=j;i<n;i++)
#define rloop(i,j,n) for(i=n;i>=j;i--)
#define INF 2147483647
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
#define mii map<int,int>
#define vi vector<int>
#define all(n) n.begin(),n.end()
#define inf INF

//const int row[]={-1, -1, -1,  0,  0,  1,  1,  1};  // Kings Move
//const int col[]={-1,  0,  1, -1,  1, -1,  0,  1};  // Kings Move
//const int row[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int col[]={-1,  1, -2,  2, -2,  2, -1,  1};  // Knights Move
//const int row[]={-1,0,0,1,0};
//const int col[]={0,-1,1,0,0};
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return ((a*b)/gcd(a,b));}

/*bool bitcheck(int n,int pos)
{
    return (bool)(n & (1<<pos));
}

int biton(int n,int pos)
{
    return n=n or (1<<pos);
}
int bitoff(int n,int pos)
{
    return n=n & ~(1<<pos);
}*/

using namespace std;
int ara1[100005],ara2[100005];

struct data
{
    vi v;
    int len;
};
data dp[101][101];int vis[101][101],test;
data LCS(int n,int m)
{
    if(n<0|| m<0)
    {
        data ret;
        ret.len=0;
        return ret;
    }
    if(vis[n][m]==test)return dp[n][m];//printf("%d %d\n",n,m);
    vis[n][m]=test;
    if(ara1[n]==ara2[m])
    {
        data ret;
        ret.len=0;
        ret=LCS(n-1,m-1);
        ret.v.pb(ara1[n]);
        ret.len+=1;
        return dp[n][m]=ret;
    }
    data ret1,ret2;
    ret1.len=0,ret2.len=0;
    {
        {
            ret1=LCS(n-1,m);
            ret2=LCS(n,m-1);
            if(ret1.len>ret2.len)return dp[n][m]=ret1;
            else return dp[n][m]=ret2;
        }
    }
}

int main()
{
//FRO;
//FRU;
//std::ios_base::sync_with_stdio(false);
    int a,b,c,i,j,k,tc,t=1;
    int n,m,len,cnt=0;
    char s[10001];
    string ss;
    map<string,int>mmp;
    map<int,string>mmp1;
    test=1;
    while(1)
    {
        //if(t!=1)printf("\n");
        t=2;
        if(scanf("%s",s)==EOF)return 0;
        j=1;
        k=0;//printf("dfsf");
        while(s[0]!='#')
        {
            ss.clear();
            len=strlen(s);
            for(i=0;i<len;i++)ss.pb(s[i]);
            if(mmp[ss]==0)mmp[ss]=j,mmp1[j++]=ss;
            ara1[k++]=mmp[ss];
            scanf("%s",s);
        }
        scanf("%s",s);
        n=k-1;
        k=0;
        while(s[0]!='#')
        {
            ss.clear();
            len=strlen(s);
            for(i=0;i<len;i++)ss.pb(s[i]);
            if(mmp[ss]==0)mmp[ss]=j,mmp1[j++]=ss;
            ara2[k++]=mmp[ss];
            scanf("%s",s);
        }
        m=k-1;
        data ans=LCS(n,m);
        test++;
        if(ans.len!=0)
        {
            cout<<mmp1[ans.v[0]];
            for(i=1;i<ans.len;i++)cout<<" "<<mmp1[ans.v[i]];
            printf("\n");
        }
    }
return 0;
}
