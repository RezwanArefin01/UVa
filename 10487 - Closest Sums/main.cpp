#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,co = 0;
    while(cin>>n && n) {
        int num[n]; for(int i=0 ;i<n;i++) cin>>num[i];
        sort(num,num+n); cin>>m; cout<<"Case "<<++co<<":\n";
        while(m--) {
            int mid, cur, ans = num[0] + num[1];
            cin>>mid;
            for(int i=0 ;i < n; i++) {
                for(int j=i+1; j< n; j++) {
                    cur = num[i] + num[j];
                    if(abs (ans - mid) > abs(cur - mid)) ans = cur;
                }
            }
            cout<<"Closest sum to "<<mid<<" is "<<ans<<".\n";
        }
    }
}
