#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,days, nump, holiday;
    cin>>t;
    while(t--) {
        int loss=0;
        cin>>days>>nump;
        int hartals[nump+1];
        for(int i=0;i<nump;i++)
            cin>>hartals[i];
        for(int i=1;i<=days;i++) {
            if (i%7==0 || i%7==6) continue;
            bool hartal = false;
            for (int j=0;j<nump;j++) {
                if(i%hartals[j]==0) hartal = true;
            }
            if(hartal) loss++;
        }
        cout<<loss<<endl;
    }
    return 0;
}
