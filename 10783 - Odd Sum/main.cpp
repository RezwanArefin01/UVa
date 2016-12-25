#include<cstdio>
int a,b,c,ncase,sum;
int main(void){
        scanf("%d",&c);
        ncase =0;
        while(c){
            scanf("%d\n%d",&a,&b);
            c--;
            if(a%2==0) a++;
            for(sum = 0; a <= b; sum+=a,a+=2);
            printf("Case %d: %d\n",++ncase,sum);
        }
    return 0;
}
