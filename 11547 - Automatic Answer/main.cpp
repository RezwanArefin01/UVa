#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<abs((((n * 63 + 7492) * 5 - 498)/10)%10)<<endl;
    }
    return 0;
}
