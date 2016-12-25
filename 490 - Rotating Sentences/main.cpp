#include<bits/stdc++.h>
using namespace std;
int m = 0; string l; vector<string> a;
int main() {
    while(getline(cin, l)) {
        a.push_back(l); m = max(m, (int) l.length());
    }
    for(int i = 0; i < m; i++) {
        for(int j = a.size() - 1; j >= 0; j--) {
            printf("%c", i < a[j].length()? a[j][i] : ' ');
        } printf("\n");
    }
}
