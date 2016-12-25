#include<bits/stdc++.h>
using namespace std;

int main() {
    string str; while(getline(cin,str)) {
        istringstream iss(str); int num;
        vector<int> a;
        while(iss>>num) a.push_back(num);
        int sum = 0, ans = 0;
        for(int i=0; i<a.size(); i++) {
            sum += a[i];
            ans = max(ans, sum);
            sum = sum < 0 ? 0 : sum;
        } cout<<ans<<endl;
    }
}
