#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
int n,coins[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
unsigned long long ways[MAX];
int main() {
    for(int i=0; i<MAX; i++) ways[i] = 0;
    ways[0] = 1;
    for(int i=0; i<21; i++ )
        for(int j=coins[i]; j<=MAX; j++)
            ways[j] += ways[j-coins[i]];
    while(cin>>n) {
        cout<<ways[n]<<endl;
    }
}
