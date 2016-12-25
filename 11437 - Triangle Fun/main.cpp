#include <bits/stdc++.h>
using namespace std;
struct point {long double x,y;};
int main() {
    point A,B,C;
    int t;
    cin>>t;
    while(t--) {
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
        double ans =fabs(A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y))/14.0 + 0.5;
        cout<<(int)ans<<endl;
    }
    return 0;
}
