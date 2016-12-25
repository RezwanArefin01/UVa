#include<bits/stdc++.h>
using namespace std;
int read() {
    int n;
    char c = 0;
    while(c<33) c = getc(stdin);
        n = 0;
    while(c>33){
        n = n*10 + c - '0';
        c = getc(stdin);
    }
    return n;
}
int t,arr[4];
int main() {
    t = read();
    while(t--) {
        for(int i=0;i<4;i++) arr[i] = read();
        if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3]) {
            puts("square");
            continue;
        }
        sort(arr,arr+4);
        if(arr[0]==arr[1] && arr[2]==arr[3]) puts("rectangle");
        else if(arr[0]+arr[1]+arr[2]>arr[3]) puts("quadrangle");
        else puts("banana");
    }
}
