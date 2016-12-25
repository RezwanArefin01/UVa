#include<stdio.h>
int main()
{
    int t,i,k,l;
    char message[100],letter[15]="OIZEASGTBP";
    //freopen("in.txt","r",stdin);

    scanf("%d\n",&t);
    while(t--)
    {
        while(gets(message))
        {
            for(l=0;message[l];l++);
            if(!l)break;

            for(i=0;i<l;i++)
            {
                k=message[i]-48;
                if(k>=0&&k<=9)
                    message[i]=letter[k];
            }
            printf("%s\n",message);
        }
        if(t)printf("\n");
    }
    return 0;
}
