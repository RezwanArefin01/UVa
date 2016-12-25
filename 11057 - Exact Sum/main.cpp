#include<bits/stdc++.h>
using namespace std;

int N,M,tmp;
int book[10010];
inline void Scan_f(int &a)
{
    char c = 0;
    while(c<33) c = getc(stdin);
    a = 0;
    while(c>33){
        a = a*10 + c - '0';
        c = getc(stdin);
    }
}
int Search(int n,int start) {
    int left=start;
    int right=N;
    int mid;
    while (left<=right){
        mid = (left+right)/2;
        if (n==book[mid]) return mid;
        if (n>book[mid]) left=mid+1;
        else right=mid-1;
    }
    return -1;
}
int main() {
    while (scanf("%d",&N)!=EOF) {
        for(int i=0;i<N;i++) Scan_f(book[i]);
        Scan_f(M);
        sort(book,book+N);
        int ans[10010], a=0;
        for(int i=0;book[i]<(M/2);i++) {
            if(Search(M-book[i],i+1)!=-1)
                ans[a++] = book[i];
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans[a-1],M-ans[a-1]);
    }
    return 0;
}
