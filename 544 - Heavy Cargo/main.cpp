#include<bits/stdc++.h>
using namespace std;
#define inf INT_MIN
int main() {
    int n,c,l,co=0;
    while(cin>>n>>l && (n||l)) {
        map<string,int> mp;
        int tag = 1;
        string s1,s2;
        int cost[203][203];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++){
                cost[i][j] = inf;
                if(i==j) cost[i][j] = 0;
            }
        }
        for(int i=0;i<l;i++) {
            cin>>s1>>s2>>c;
            if(mp[s1]==0)
                mp[s1] = tag++;
            if(mp[s2]==0)
                mp[s2] = tag++;
            cost[mp[s1]][mp[s2]] = c;
            cost[mp[s2]][mp[s1]] = c;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    cost[i][j] = max(cost[i][j], min(cost[i][k],cost[k][j]));
        cin>>s1>>s2;
        printf("Scenario #%d\n%d tons\n\n",++co,cost[mp[s1]][mp[s2]]);
    }
}
