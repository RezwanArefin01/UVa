#include <bits/stdc++.h>
using namespace std;
int t;
char punc[4] = {'!',',','.','?'};
string tmp,str;
bool pal() {
    int i=0,j=str.size()-1;
    while(i<j) {
        if(str[i++]!=str[j--]) return false;
    }
    return true;
}
int main() {
    cin>>t; getchar();
    for(int i=1;i<=t;i++) {
        getline(cin,tmp);
        str = "";
        int len = tmp.size();
        for(int j=0;j<len;j++) {
            if(isalpha(tmp[j]) && tmp[j]!=' ' && (!binary_search(punc,punc+4,tmp[j])))
                str+=tmp[j];
        }
        cout<<"Case #"<<i<<":\n";
        if(pal()) {
            int sq = sqrt(str.size());
            if(sq*sq == str.size()) cout<<sq<<endl;
            else puts("No magic :(");
        }
        else puts("No magic :(");
    }
}
