#include <bits/stdc++.h>
using namespace std;

int main() {
    int num; while(cin>>num && num ) { int len = 1;
        cout<<"Original number was "<<num<<endl;
        map<int,bool> m; string inc, dec; m[num] = 1;
        while(1){
            ostringstream ss, A; ss<<num; A<<num;
            inc = ss.str(), dec = A.str();
            sort(inc.begin(), inc.end());
            sort(dec.begin(), dec.end(), greater<char> ());
            int a,b, New; istringstream iss(inc), dss(dec); iss>>a; dss>>b;
            New = b-a;
            cout<<b<<" - "<<a <<" = "<<New<<endl;
            if(m[New]) break;
            m[New] = 1; num = New; len++;
        } cout<<"Chain length "<<len<<endl<<endl;
    }
}
