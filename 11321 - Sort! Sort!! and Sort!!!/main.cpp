#include<bits/stdc++.h>
using namespace std;
int n,M;
bool comp(int n1, int n2) {
    int mod_n1 = n1 % M;
        int mod_n2 = n2 % M;
        if (mod_n1 < mod_n2)
            return true;
        else if (mod_n1 == mod_n2)
        {
            if (abs(n1 % 2) == 1)
            {
                if (n2 % 2 == 0)
                    return true;
                return n1 > n2;
            }
            else if (n1 % 2 == 0)
            {
                if (n2 % 2 == 0)
                    return n1 < n2;
            }
        }
        return false;
}
int main() {
    while(cin>>n>>M && (n||M)) {
        int arr[n+1];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr,arr+n,comp);
        cout<<n<<" "<<M<<endl;
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<endl;
        }
    }
    cout<<"0 0"<<endl;
    return 0;
}
