#include<bits/stdc++.h>
using namespace std;
bool mark[1001];
vector<int> prime = {1,2};
void sv() {
    memset(mark, 1, sizeof mark); mark[0] = mark[1] = 0;
    int Size = 1000;
    for(int i = 4; i <= Size; i += 2) mark[i] = 0;
    for(int i = 3; i*i<=Size; i += 2) if(mark[i])
        for(int j = i*i; j <= Size; j += (i<<1)) mark[j] = 0;
    for(int i = 3; i <= Size; i++) if(mark[i]) prime.push_back(i);
}
int main() {
    int n,c; sv();
    while(cin>>n>>c) {
        int N = n; n = n > 1000 ? 1000 : n;
        int cnt = 0;
        while(prime[cnt++] <= n); cnt--;
        int l,r;
        if(cnt & 1) { l = cnt/2 - c + 1; r = l + 2*c - 1;}
        else { l = cnt/2 - c; r = l + 2*c;}
        l = l < 0 ? 0 : l;
        r = r > cnt - 1 ? cnt : r;
        cout<<N<<" " <<c<<":";
        for(int i=l; i<r; i++) cout<<" "<<prime[i];
        puts("\n");
    }
}
