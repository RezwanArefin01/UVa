#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main() {
    int k; while(cin>>k) {
        vector<ii> v;
        for(int y = k+1; y <= 2 * k ; y++){
            if(!((k*y)%(y-k)))
                v.push_back(ii((k*y)/(y-k), y));
        }
        cout<<v.size()<<endl;
        for(auto n : v)
            printf("1/%d = 1/%d + 1/%d\n", k, n.first,n.second);
    }
}
