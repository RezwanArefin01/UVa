#include<bits/stdc++.h>
using namespace std;
int MAX;
int BS(int node, int ball) {
    int left = node << 1 , right = left +1;
    if(left < MAX && right < MAX)
        return (ball&1) ? BS(left, ball / 2 + 1) : BS(right, ball / 2);
    return node;
}
int main() {
    int t; cin>>t; while(t--) {
        int d,i; cin>>d>>i;
        MAX = 1<<d;
        cout<<BS(1, i)<<endl;
    }
}
