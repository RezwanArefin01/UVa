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
int main()
{
    int t,i,n,cnt,cs=1;
    char a[105];
    t = read();
    for(cs=1;cs<=t;cs++) {
        n = read();
        gets(a);
        cnt=0;
        for(i=0;i<n;i++)
            if(a[i]=='.')
                {
                    i=i+2;
                    cnt++;
                }
        printf("Case %d: %d\n",cs,cnt);
    }
    return 0;
}


