#include<bits/stdc++.h>
using namespace std;
bool mark[2002];
void sv() {
    memset(mark, 1, sizeof mark); mark[0] = mark[1] = 0;
    int Size = 2001;
    for(int i = 4; i <= Size; i += 2) mark[i] = 0;
    for(int i = 3; i*i<=Size; i += 2) if(mark[i])
        for(int j = i*i; j <= Size; j += (i<<1)) mark[j] = 0;
} int main() {
    sv(); int t,co=0; cin>>t; while(t--) {
        string str; cin>>str; map<char, int> freq;
        for(int i=0; i<str.size(); i++) freq[str[i]]++;
        cout<<"Case "<<++co<<": "; int one = false;
        for(map<char,int> :: iterator it = freq.begin(); it != freq.end(); it++)
            if(mark[it->second]) one = true, cout<<it->first;
        if(!one) cout<<"empty";
        cout<<endl;
    }
}
