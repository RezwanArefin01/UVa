#include <iostream>
using namespace std;
long int i,j,g,a;
long int GCD(long int i,long int j) {
    if (j==0) return i;
    else return GCD(j,i%j);
}
int main() {
    while(cin>>a) {
        if(!a) break;
        g=0;
        for(i=1;i<a;i++)
        for(j=i+1;j<=a;j++) {
            g+=GCD(i,j);
        }
        cout<<g<<endl;
    }
    return 0;
}
