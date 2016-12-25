#include<stdio.h>

static char s[128];

int main(){
    register unsigned int i;
    unsigned remainder;
    while(gets(s)){
        if(s[0] == 48 && s[1] == 0) return 0;
        for(remainder = i = 0; s[i]; ++i)
            remainder = ( remainder * 10 + s[i] - 48 ) % 17;
        remainder ? printf("0\n") : printf("1\n");
    }
    return 0;
}
