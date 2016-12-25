#include<bits/stdc++.h>
using namespace std;
int main() {
//    freopen("in.txt","r",stdin);
    int max = 0;
    string str,res;
    while(cin>>str) {
        int cnt = 0;
        if(str=="E-N-D") break;
        for(int i=0;i<str.size();i++) {
            if(isalpha(str[i]) || str[i]=='-')
                cnt++;
        }
        if(cnt>max) {
            res = str;
            max = cnt;
        }
    }
    for(int i=0;i<res.size();i++) {
        if(isalpha(res[i]) || res[i]=='-'){
            if(res[i]>='A' && res[i]<='Z') res[i] = res[i]-'A'+'a';
        cout<<res[i];
        }
    }
    cout<<endl;
    return 0;
}
