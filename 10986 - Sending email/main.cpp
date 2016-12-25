#include<bits/stdc++.h>
#define max 20001
#define INF 100100

using namespace std;

vector<int>edge[max];
vector<int>cost[max];
int level[max];

struct data
{
    int n,cost;
    data(int a,int b) { n = a; cost = b;    }
    bool operator < (const data& p) const
    {
        return cost>p.cost;
    }
};
void Dijkstra(int start,int node)
{
    int i,j,u,v;
    for(j=0; j<=node; j++)
        level[j] = INF;
    priority_queue<data>Q;
    Q.push(data(start,0));
    level[start] =0;
    while(!Q.empty())
    {
        data top = Q.top();
        Q.pop();
        u = top.n;
        for(i=0; i<edge[u].size(); i++)
        {
            v = edge[u][i];
            if(level[u]+cost[u][i]<level[v])
            {
                level[v] = level[u]+cost[u][i];
                Q.push(data(v,level[v]));
            }
        }
    }
}
int main()
{
    int node,e,i,j,k,l,m,x,y,z,start,end,cas;
    scanf("%d",&cas);
    for(k=1; k<=cas; k++)
    {
        scanf("%d %d %d %d",&node,&e,&start,&end);
        for(i=0; i<e; i++)
        {
            cin>>x>>y>>z;

            edge[x].push_back(y);
            edge[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        Dijkstra(start,node);
         if(level[end]==INF)
            printf("Case #%d: unreachable\n",k);
        else
            printf("Case #%d: %d\n",k,level[end]);
        memset(level,0,sizeof(level));

        for(l =0; l<max; l++)
        {
            edge[l].clear();
            cost[l].clear();
        }
    }

    return 0;


}

