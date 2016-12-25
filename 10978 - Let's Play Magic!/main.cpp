#include<bits/stdc++.h>
using namespace std;

int main() { int n;
    string word[64], card[64], order[64];
    while(cin>>n && n) {
        for(int i=0; i<n; i++) cin>>card[i]>>word[i];
        for(int i=0; i<n; i++) order[i] = "?";
        for(int i=0,j=0; i<n; i++) {
            for(int k = word[i].size();; j = (j+1)%n)
                if(order[j][0] == '?' && --k <= 0) break;
            order[j] = card[i];
        } cout<<order[0];
        for(int i = 1; i < n; i++) cout<<" " <<order[i];
        cout<<endl;
    }
}
