#include<bits/stdc++.h>
using namespace std;

int main() {
    int w,h; while(cin>>h>>w) {
        int ans = 0; getchar();
        for(int i=0; i<h; i++){ stack<int> s;
            for(int j=0; j<w; j++) {
                char c = getchar();
                if(c != '.') s.push(j);
            } getchar();
            while(!s.empty()) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                ans += abs(a-b);
            }
        } cout<<ans<<endl;
    }
}
