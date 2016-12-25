#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,n1;
    vector<int> v;
    while(scanf("%d",&n)!=EOF) {
        v.push_back(n);

        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        n1 = *(v.begin() + v.size() /2);
        if(v.size()%2 == 0) {
            nth_element(v.begin(), v.begin()+v.size()/2 -1, v.end());
            int n2 = *(v.begin() + v.size()/2 -1);
            n1 = (n1+n2)/2;
        }
        printf("%d\n",n1);
    }
}
