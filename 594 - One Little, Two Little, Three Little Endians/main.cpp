#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,y; while(cin>>n) {
        y = 0;
        for(int i=0; i<4;i++)
            y = (y<<8) | ((n>>(8*i))&255);
        printf("%d converts to %d\n", n, y);
    }
}
