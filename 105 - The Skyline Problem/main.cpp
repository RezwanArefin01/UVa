#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> height(10001, 0);
    int L,H,R;
    while(cin>>L>>H>>R) {
        for(int i=L; i<R; i++)
            height[i] = max(height[i], H);
    } int curr = 0; bool first = false;
    for(int i=0; i != 10000; i++)  if(height[i] != curr) {
        if(first) cout<<" "; first = true;
        cout<<i<<" " <<height[i];
        curr = height[i];
    } puts("");
}
