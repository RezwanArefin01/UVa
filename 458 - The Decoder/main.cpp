#include<cstdio>
int main(){
    char c;
    while((c = getchar())!=EOF) putchar(c=='\n'?'\n': (char)(c-7));
    return 0;
}
