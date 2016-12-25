#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc scanf
#define pf printf
int main(){
    int t;
    char a[50],b[50],c[50],d[50];
    sc("%d",&t);
    while(t--) {
        sc("%s",a);
        sc("%s",b);
        int l1=strlen(a);
        int l2=strlen(b);
        if(l1!=l2)
        {
            pf("No\n");
            continue;
        }
        int j=0;
        int k=0;
        for(int i=0;i<l1;i++)
        {
            if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' ||
               a[i]=='u')
               continue;
            else
            {
                c[j++]=a[i];
            }
               if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' ||
               b[i]=='u')
               continue;
            else
            {
                d[k++]=b[i];
            }
        }
        c[j]='\0';
        d[k]='\0';
        if(strcmp(c,d)!=0)
        pf("No\n");
        else
        pf("Yes\n");
    }
    return 0;
}
