#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi pset(1000), set_size(1000); int disjointSetsSize;
void initSet(int N) { disjointSetsSize = N; set_size.assign(N, 1); pset.assign(N, 0); for(int i=0;i<N;i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { if (!isSameSet(i, j)) { disjointSetsSize--; set_size[findSet(j)] += set_size[findSet(i)]; pset[findSet(i)] = findSet(j); } }

int main() {
    map<char,int> m;
    for(int i=0;i<26;i++) m[char(i+65)] = i;
    int t;
    char n;
    cin>>t;
    string str;
    getchar();
    while(t--) {
        cin>> n;
        getchar();
        bool visited[m[n]];
        memset(visited,false,sizeof visited);
        char a,b;
        initSet(m[n]+1);
        while(getline(cin,str) && str!="") {
            unionSet(m[str[0]],m[str[1]]);
        }
        cout<<disjointSetsSize<<endl;
        if(t) puts("");
    }
}
