#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m; while(cin>>n>>m) {
        string str[n]; cin>>str[0];
        int idx[n] = {0};
        for(int i=1; i<n;i ++) {
            cin>>str[i]; int cnt = 0;
            for(int j=0; j<m; j++)
                if(str[i][j] != str[0][j]) cnt++;
            idx[cnt] = i;
        } for(int i=0; i<n; i++) cout<<str[idx[i]]<<endl;
    }
}
