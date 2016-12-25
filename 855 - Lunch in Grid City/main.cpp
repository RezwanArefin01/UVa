#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int s,a,f;
        cin>>s>>a>>f;
        int str[f+1],ave[f+1];
        for(int i=0;i<f;i++) cin>>str[i]>>ave[i];
        sort(str,str+f);
        sort(ave,ave+f);
        if(f%2) cout<<"(Street: "<<str[f/2]<<", Avenue: "<<ave[f/2]<<")"<<endl;
        else cout<<"(Street: "<<str[(f-1)/2]<<", Avenue: "<<ave[(f-1)/2]<<")"<<endl;
    }
    return 0;
}
