#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    char s[6];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int len = strlen(s);
        if(len>3) printf("3\n");
        else if(s[0]=='o' && s[2]=='e') printf("1\n");
        else if(s[1]=='n' && s[2]=='e') printf("1\n");
        else if(s[0]=='o' && s[1]=='n') printf("1\n");
        else printf("2\n");
    }
    return 0;
}
