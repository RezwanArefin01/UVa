#include<bits/stdc++.h>
using namespace std;

bool mark[2<<15 + 1];
vector<int> prime = {2};
void sv() {
    memset(mark, 1, sizeof mark); mark[0] = mark[1] = 0;
    int Size = 2<<15;
    for(int i = 4; i <= Size; i += 2) mark[i] = 0;
    for(int i = 3; i*i<=Size; i += 2) if(mark[i])
        for(int j = i*i; j <= Size; j += (i<<1)) mark[j] = 0;
    for(int i = 3; i <= Size; i++) if(mark[i]) prime.push_back(i);
}
int main() {
    sv(); int n; while(cin>>n && n) {
        int cnt = 0;
        for(int i=0; prime[i] <= (n>>1); i++)
            if(mark[n - prime[i]]) cnt++;
        cout<<cnt<<endl;
    }
}
