#include<bits/stdc++.h>
using namespace std;
long long r,c,t,co=0;
int main() {
    cin>>t;
    while(t--) {
        cin>>c>>r;
        if(c==r) {
            cout<<"Case #"<<++co<<": 0"<<endl;
        }
        else {
            int sq = sqrt(c-r),num = c-r;
            set<int> divisors;
            for(int i=1;i<=sq;i++) {
                if(num%i==0){
                    divisors.insert(i);
                    divisors.insert(num/i);
                }
            }
            cout<<"Case #"<<++co<<":";
            for(set<int>::iterator it=divisors.begin();it!=divisors.end();it++) if(*it>r) cout<<" "<<*it;
            cout<<endl;
            divisors.clear();
        }
    }
    return 0;
}
