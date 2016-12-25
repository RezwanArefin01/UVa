#include <cstdio>
using namespace std;
#define MAX 1000

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[MAX],zero=0,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0;

    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
    for (int i=res_size-1; i>=0; i--)
    {
        if (res[i]==0) zero++;
        if (res[i]==1) one++;
        if (res[i]==2) two++;
        if (res[i]==3) three++;
        if (res[i]==4) four++;
        if (res[i]==5) five++;
        if (res[i]==6) six++;
        if (res[i]==7) seven++;
        if (res[i]==8) eight++;
        if (res[i]==9) nine++;
    }
    printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",zero,one,two,three,four);
    printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",five,six,seven,eight,nine);
}

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        printf("%d! --\n",n);
        factorial(n);
    }
    return 0;
}
