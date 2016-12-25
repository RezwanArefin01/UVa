#include<bits/stdc++.h>
using namespace std;

vector<int> pset(1000), set_size(1000); int disjointSetsSize;
void initSet(int N) {
    disjointSetsSize = N;
    set_size.assign(N, 1);
    pset.assign(N, 0);
    for(int i=0;i<N;i++) pset[i] = i;
}
int findSet(int i) {
    return (pset[i] == i) ? i:(pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    if(!isSameSet(i, j)){
        disjointSetsSize--;
        set_size[findSet(j)] += set_size[findSet(i)];
        pset[findSet(i)] = findSet(j);
    }
}
int sizeOfSet(int i) { return set_size[findSet(i)]; }
int t,n;
string a,b;
int main() {
    cin>>t;
    while(t--) {
        map<string,int> m;
        cin>>n;
        int tag = 0;
        initSet(n);
        while(n--) {
            cin>>a>>b;
            if(m.find(a) == m.end()) m[a] = tag++;
            if(m.find(b) == m.end()) m[b] = tag++;
            unionSet(m[a],m[b]);
            cout<<sizeOfSet(m[a])<<endl;
        }
    }
}
