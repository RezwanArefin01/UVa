#include<bits/stdc++.h>
using namespace std;
char s[105];
unsigned int i, part, pnum;
int main(void){
    while(scanf("%u",&pnum) && pnum){
        scanf("%s",&s);
        part = strlen(s)/pnum;
        for(i = 0; i < pnum; i++)
            reverse(s+i*part,s+(i+1)*part);
        puts(s);
    }
    return 0;
}
