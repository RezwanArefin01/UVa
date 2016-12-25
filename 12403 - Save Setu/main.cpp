//Light OJ
#include<iostream>
#include<cstring>
using namespace std;
int t,co =0 ;
unsigned long long k,sum=0;
string s;
int main(){
    cin>>t;
    while(t--) {
        int n;
        cin>>n; sum = 0;
        cout<<"Case "<<++co<<":\n";
        while(n--){
            cin>>s;
            if(s=="donate") {
                cin>>k;
                sum+=k;
            }
            if(s=="report")
                cout<<sum<<endl;
        }
    }
    return 0;
}
