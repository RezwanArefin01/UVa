#include<bits/stdc++.h>
using namespace std;

int pr[10000];
void reset(int n){
    for(int i=0;i<=n;i++)
        pr[i] = i;
}
int find(int a) {
    return (pr[a]==a) ?a:(pr[a]=find(pr[a]));
}
void Union(int a,int b) {
    pr[find(b)] = find(a);
}
int t,n_c,a,b;
char ch;
bool blank = false;
int c = 0;
int main() {
    cin>>t;
    while(t--) {
        int suc = 0,uns = 0;
        string str;
        cin>>n_c;
        for(int i=0;i<n_c+1;i++) pr[i]=i;
        getline(cin,str);
        while(getline(cin,str)){
            if(str=="") break;
            istringstream iss(str);
            iss>>ch>>a>>b;
            if(ch=='c') {
                pr[find(b)] = find(a);
            }
            if(ch=='q') {
                if(find(a)==find(b)) suc++;
                else uns++;
            }
        }
        if(blank) puts("");
        blank = true;
        cout<<suc<<","<<uns<<endl;
    }
    return 0;
}
