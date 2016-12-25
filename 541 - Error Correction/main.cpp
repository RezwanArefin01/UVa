#include <bits/stdc++.h>
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
int main(){
    int M[99][99],F[99],C[99],n,conti,contj,I,J;

    while(true){
        n=read();
        if(n==0) break;
        memset(C,0,sizeof(C));
        for(int i=0;i<n;i++){
            F[i]=0;
            for(int j=0;j<n;j++){
                scanf("%d",M[i][j]);
                F[i]+=M[i][j];
                C[j]+=M[i][j];
            }
        }
        conti=0;
        contj=0;
        for(int i=0;i<n;i++){
            if(F[i]%2==1){
                conti++;
                I=i;
            }
            if(C[i]%2==1){
                contj++;
                J=i;
            }
            if(conti+contj>2) break;
        }
        if(conti+contj==0) puts("OK");
        else if(conti==1 && contj==1) printf("Change bit (%d,%d)\n",I+1,J+1);
        else if(conti+contj>0) puts("Corrupt");
    }

    return 0;
}
