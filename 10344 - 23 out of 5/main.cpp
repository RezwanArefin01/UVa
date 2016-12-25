#include<bits/stdc++.h>
using namespace std;

int num[5];

bool search(int n, int curr) {
    if(n == 5) {
        if(curr == 23) return true;
        else return false;
    }

    return search(n+1, curr+num[n]) || search(n+1, curr-num[n]) || search(n+1, curr*num[n]);
}
int main() {
    while(true) { int a = 0;
        for(int i=0; i<5; i++) cin>>num[i], a |= num[i];
        if(!a) break;
        sort(num,num+5); bool possible = false;
        do {
            if(search(1, num[0])) {
                possible = true; break;
            }
        } while(next_permutation(num,  num+5));
        puts(possible ? "Possible" : "Impossible");
    }
}
