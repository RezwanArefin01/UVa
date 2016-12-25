#include <iostream>
using namespace std;
int main() {
    int t,n,k,p,co=0;
    cin>>t;
    while(t--) {
        cin>>n>>k>>p;
        while (p--) {
            k++;
            if (k > n) k = 1;
        }
        cout<<"Case "<<++co<<": "<<k<<endl;
    }
    return 0;
}
