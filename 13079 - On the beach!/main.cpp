#include<bits/stdc++.h>
using namespace std;
int read() {
    int n;  char c = 0;
    while(c<33) c = getc(stdin); n = 0;
    while(c>33){
        n = n*10 + c - '0';
        c = getc(stdin);
    } return n;
}
int main() {
    int n; while((n = read()) && n) {
        vector<pair<int,int> > v(n);
        for(int i=0; i<n; i++) {
            v[i].first = read(); v[i].second = read();
        }
        sort(v.begin(), v.end());
        int Max = INT_MAX, ret = 0;
        for(int i =0 ; i<n; i++) {
            if(Max != INT_MAX && Max <= v[i].first)
                ret++, Max = INT_MAX;
            Max = min(Max, v[i].second);
        } if(Max != INT_MAX) ret++;
        printf("%d\n", ret);
    }
}
