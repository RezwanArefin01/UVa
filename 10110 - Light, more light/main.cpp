#include<bits/stdc++.h>
using namespace std;
long long n;

int main()
{
    double sq;
    while(1)
    {
        char c = 0;
        while(c<33) c = getc(stdin);
            n = 0;
        while(c>33){
            n = n*10 + c - '0';
            c = getc(stdin);
        }
        if(n==0) break;
        sq = sqrt(n);
        if(sq*sq==n) puts("yes");
        else puts("no");
    }
    return 0;
}
